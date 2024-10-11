#include "WiFiS3.h"
#include <Wire.h>
#include <SparkFun_VL53L5CX_Library.h>

WiFiClient client;
SparkFun_VL53L5CX mySensor; 

char ssid[] = "your network name";
char pass[] = "your network password";

int led =  LED_BUILTIN; 
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("********* Starting Program ********* ");

  // Initialize the I2C communication
  Wire.begin();
  
  // Try to initialize the sensor
  if (!mySensor.begin()) {
    Serial.println("Failed to communicate with VL53L5CX. Check wiring.");
    while (1); // If failed, halt the program
  }

  Serial.println("VL53L5CX detected!");
  
  mySensor.setResolution(8 * 8); // Set resolution to 8x8
  mySensor.startRanging(); // Start measuring distance

  // set the LED pin mode
  pinMode(led, OUTPUT);      
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }
  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);  
    // wait 10 seconds for connection:
    delay(10000);
  }
  // start the web server on port 80
  server.begin();
  // you're connected now, so print out the status
  printWiFiStatus();
}

void loop() {
  // compare the previous status to the current status
  if (status != WiFi.status()) {
    // it has changed update the variable
    status = WiFi.status();
    if (status == WL_AP_CONNECTED) {
      // a device has connected to the AP
      Serial.println("Device connected to AP");
    } else {
      // a device has disconnected from the AP, and we are back in listening mode
      Serial.println("Device disconnected from AP");
    }
  }

  client = server.available();   // listen for incoming clients
  unsigned long clientConnectedTime = millis();

  if (client) {                             // if you get a client,
    // Serial.println("new client");        // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (millis() - clientConnectedTime > 1000) { // Check if the client has been connected for more than 2 seconds
        client.stop(); // Forcefully close the connection
        break; // Exit the loop
      }

      delayMicroseconds(10);                // This is required for the Arduino Nano RP2040 Connect - otherwise it will loop so fast that SPI will never be served.
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        //Serial.write(c);                    // print it out to the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // this is the response for the website but i moved it to the specific endpoints
            // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          printHeaders();
          client.println("We're turning it on bbgirl!!");
          // The HTTP response ends with another blank line:
          client.println();
          digitalWrite(led, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          printHeaders();
          client.println("Lights off bb!!!");
          // The HTTP response ends with another blank line:
          client.println();
          digitalWrite(led, LOW);                // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /readSensor")) {
          printHeaders();
          client.print(checkSensor());
        }
      }
    }
    delay(1);
    // close the connection:
    client.stop();
    // Serial.println("client disconnected");
  }
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
  Serial.println(checkSensor());
}

int checkSensor() {
  int distance;
  
  if (mySensor.isDataReady()) { // Check if data is ready
    VL53L5CX_ResultsData results; // Create an object to hold the data
    mySensor.getRangingData(&results); // Get the data from the sensor
    
    // Print the distance for the first zone (zone 0)
    distance = results.distance_mm[0] / 10;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  return distance;
}

void printHeaders() {
  // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  // and a content-type so the client knows what's coming, then a blank line:
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Access-Control-Allow-Origin: *"); // This allows any origin
  client.println();
}

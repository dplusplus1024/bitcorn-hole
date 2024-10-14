![image](https://github.com/user-attachments/assets/6203ecbb-de3d-4308-81ec-74ea63075224)

# Bitcorn Hole 🌽🕳️

**Bitcorn Hole** is a physical hardware game where players earn bitcoin every time they score a point! Bean bags are tossed into the cornhole set and detected using microcontrollers with time-of-flight sensors. Each point scored triggers an **instant** payment of sats to the player’s Lightning Address! ⚡

## Live Demo
See how the game works live in action [here](https://x.com/D_plus__plus/status/1807889900093821104) and [here](https://x.com/D_plus__plus/status/1845504750739218734).

## What You’ll Need

To build your own Bitcorn Hole setup, you’ll need the following:

- [Cornhole set](https://www.amazon.com/dp/B07S1PYYTV) — comes with two boards
- 2x [Wifi-enabled microcontrollers](https://www.amazon.com/dp/B0C8V88Z9D) —
  I used the Arduino Uno R4, but you could refactor the code to work with ESP32
- 2x [Time-of-flight (ToF) sensors](https://a.co/d/5bQHzve)
- [Jumper wires](https://www.amazon.com/California-JOS-Breadboard-Optional-Multicolored/dp/B0BRTJQZRD) and USB-C cables
- [Battery packs](https://www.amazon.com/gp/product/B08LH26PFT) or AC adapters
- [DIY enclosures](ENCLOSURES.md) —
  These are placed under each cornhole board to house the sensors and detect bean bags
- A computer with a screen and speakers to run the game

Massive thanks to [Dani Go](https://www.youtube.com/@bitcoineando) for her soldering help!

## Code and Setup

There are three main code files in this repository:

1. **Frontend Webpage**: This displays the game interface and real-time scoring updates.  
   [Frontend Code - Coming Soon](#link-to-frontend-code) | [View Screenshot](https://github.com/dplusplus1024/bitcorn-hole/blob/main/screenshot.png)

2. **Microcontroller Code**: This code runs on each microcontroller, hosting a web server and interfacing with the ToF sensor to detect when a bean bag is present.  
   [View Microcontroller Code](https://github.com/dplusplus1024/bitcorn-hole/blob/main/microcontroller_webserver_with_tof.ino)

5. **API to Pay Sats**: This handles the instant payments to players' Lightning Addresses. You can substitute your own API endpoint, and either run your own LND node or use a custodial API like ZBD.  
   [API Code - Coming Soon](#link-to-api-code)

## Gameplay Instructions

For detailed gameplay instructions, view the [Instruction Sheet](INSTRUCTIONS.md).

## Bitcorn Hole in Your Community

Did you make a set for your conference, community, or event? Brag about it [here](COMMUNITY.md)!

## Disclaimer

This is experimental software. Use at your own risk. 🌽


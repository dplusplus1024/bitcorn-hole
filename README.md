![image](https://github.com/user-attachments/assets/6203ecbb-de3d-4308-81ec-74ea63075224)

# Bitcorn Hole 🌽🕳️

**Bitcorn Hole** is a physical hardware game where players earn bitcoin every time they score a point! Beanbags are tossed into the cornhole set and detected using microcontrollers with time-of-flight sensors. Each point scored triggers an **instant** payment of sats to the player’s Lightning Address! ⚡

## Live Demo

To see how the game works in action, check out [this demo on Twitter](https://x.com/D_plus__plus/status/1807889900093821104).

## What You’ll Need

To build your own Bitcorn Hole setup, you’ll need the following:

- [Cornhole set](https://www.amazon.com/dp/B07S1PYYTV) — comes with two boards
- 2x [Microcontrollers](https://www.amazon.com/dp/B0C8V88Z9D) —
  I used the Arduino UNO R4, but you could refactor the code to work on ESP32
- 2x [Time-of-flight (ToF) sensors](https://a.co/d/5bQHzve)\*
- [Jumper wires](https://www.amazon.com/California-JOS-Breadboard-Optional-Multicolored/dp/B0BRTJQZRD) and USB-C cables
- [Battery packs](https://www.amazon.com/gp/product/B08LH26PFT) or AC adapters
- DIY enclosures —
  These are placed under each cornhole board to detect beanbags and house the microcontrollers and sensors
- A computer to run the user-facing webpage

\* When using this particular microcontroller/sensor combo, qwiic cables may not work (unless there’s a workaround I'm missing). Instead, you'll need individual wires, which require soldering. Massive thanks to [Dani Go](https://www.youtube.com/@bitcoineando) for her help with this part!

## Code and Setup

There are three main code files in this repository:

1. **Frontend Webpage**: This displays the game interface and real-time scoring updates.  
   [View the Frontend Code](#link-to-frontend-code) | [View Screenshot](#link-to-screenshot)

2. **Microcontroller Code**: This is the code that runs on the microcontrollers, interfacing with the ToF sensors to detect when a beanbag is present.  
   [View Microcontroller Code](#link-to-microcontroller-code)

3. **API to Pay Sats**: This handles the instant payments to players' Lightning Addresses. You can substitute your own API endpoint, and either run your own LND node or use a service like Lightspark or ZBD.  
   [View API Code](#link-to-api-code)



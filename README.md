![image](https://github.com/user-attachments/assets/6203ecbb-de3d-4308-81ec-74ea63075224)

# Bitcorn Hole 🌽🕳️

**Bitcorn Hole** is a physical hardware game where players receive bitcoin each time they score points! Beanbags are tossed into the cornhole set and detected using microcontrollers with time-of-flight sensors. Each time a player scores, they get paid sats **instantly** to their Lightning Address! ⚡

## Live Demo

To see how the game works in action, check out [this demo on Twitter](https://x.com/D_plus__plus/status/1807889900093821104).

## What You’ll Need

To build your own Bitcorn Hole setup, you’ll need the following:

- [Cornhole set](https://www.amazon.com/dp/B07S1PYYTV?ref=ppx_pop_mob_ap_share) (2 boards)
- 2x [Time-of-Flight (ToF) sensors](https://a.co/d/5bQHzve)
- 2x [Microcontrollers](https://www.amazon.com/dp/B0C8V88Z9D?ref=ppx_pop_mob_ap_share) -
  I used the Arduino UNO R4, but you could refactor the code slightly to work on ESP32
- Wires and cables
- Battery packs or AC adapters
- DIY enclosures -
  These are to be placed under each cornhole board for beanbag detection and housing of the microcontrollers & sensors
- Computer to run the user-facing webpage

## Code and Setup

There are three main code files in this repository:

1. **Frontend Webpage**: This displays the game interface and real-time scoring updates.  
   [View the Frontend Code](#link-to-frontend-code) | [View Screenshot](#link-to-screenshot)

2. **Microcontroller Code**: This is the code that runs on the microcontrollers, interfacing with the ToF sensors to detect when a beanbag is scored.  
   [View Microcontroller Code](#link-to-microcontroller-code)

3. **API to Pay Sats**: This handles the instant payments to players' Lightning Addresses. You can substitute your own API endpoint, and either run your own LND node or use a service like Lightspark or ZBD.  
   [View API Code](#link-to-api-code)



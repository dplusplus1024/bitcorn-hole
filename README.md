![image](https://github.com/user-attachments/assets/6203ecbb-de3d-4308-81ec-74ea63075224)

# Bitcorn Hole 🏆🌽⚡

**Bitcorn Hole** is my first hardware game and was a hit last year at the Unconfiscatable conference! In this game, players instantly receive bitcoin sats via Lightning Addresses each time they score points. Now, I'm excited to refactor the project, open-source it, and take Bitcorn Hole on the road to host tournament brackets at conferences worldwide.

## How it Works

Players toss beanbags into the cornhole set, and the game keeps track of their scores using two Time-of-Flight (TOF) sensors. Each time a player scores, their Lightning Address is paid instantly with sats, offering a fun, interactive way to combine gaming and bitcoin!

## What You’ll Need

To build your own Bitcorn Hole setup, you’ll need the following:

- Cornhole set (2 boards)
- 2x Time-of-Flight (TOF) sensors
- 2x Microcontrollers (e.g., ESP32)
- Cables
- Battery packs or AC adapters
- DIY enclosures (to place under each cornhole board for beanbag detection and to house the sensors/microcontrollers)

## Code and Setup

There are three main code files in this repository:

1. **API to Pay Sats**: This handles the instant payments to players' Lightning Addresses. You can substitute your own API endpoint, and either run your own LND node or use a service like Lightspark or ZBD.  
   [View API Code](#link-to-api-code)

2. **Frontend Webpage**: This displays the game interface and real-time scoring updates.  
   [View the Frontend Code](#link-to-frontend-code) | [View Screenshot](#link-to-screenshot)

3. **Microcontroller Code**: This is the code that runs on the microcontrollers, interfacing with the TOF sensors to detect when a beanbag is scored.  
   [View Microcontroller Code](#link-to-microcontroller-code)

## How to Play

To see how the game works in action, check out a demo on Twitter!  
[Watch the Bitcorn Hole Demo on Twitter](#link-to-twitter)

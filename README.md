# Smart_Door_Lock_System
# Smart Door Lock System Using ESP32 and ESP32-CAM

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Components](#components)
- [Block Diagram](#block-diagram)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [Contributing](#contributing)

## Description
The Smart Door Lock System is an innovative security solution designed to authenticate users and grant access to premises efficiently and securely. It utilizes ESP32 and ESP32-CAM microcontrollers to provide a robust password authentication mechanism with additional security features such as email notifications and live video streaming.

![Complete Smart Door Lock System Setup](https://github.com/user-attachments/assets/97729ab6-04f7-4e35-a065-5c3d9a296c21)

*Figure 1: Complete setup of the Smart Door Lock System*

## Features
- Password-based authentication for door access
- LCD display for user interaction
- Keypad for password input
- Automated email notifications for multiple failed access attempts
- Live video streaming from ESP32-CAM for visual verification
- WiFi connectivity for remote monitoring and control

## Components
- ESP32 microcontroller
- ESP32-CAM module
- 16x2 LCD Display
- 4x4 Keypad
- Power supply
- Connecting wires

![Components of the Smart Door Lock System](https://github.com/user-attachments/assets/0ca7712d-2f13-4f6d-9a5b-315b49222625)

*Figure 2: Main components of the Smart Door Lock System*

## Block Diagram
Here's a high-level block diagram of the Smart Door Lock System:

![Block Diagram of Smart Door Lock System](https://github.com/user-attachments/assets/10cfd900-f18b-45ae-884c-d68b597a054a)

*Figure 3: Block diagram illustrating the system architecture*

## Setup Instructions
1. Clone this repository to your local machine.
2. Install the Arduino IDE and necessary libraries:
   - LiquidCrystal
   - Keypad
   - EEPROM
   - EMailSender
   - WiFi
3. Connect the components according to the wiring diagram (provide a link or include the diagram in the README).
4. Update the WiFi credentials and email settings in the ESP32 and ESP32-CAM code files.
5. Upload the ESP32 code to your ESP32 board.
6. Upload the ESP32-CAM code to your ESP32-CAM module.

## Usage
1. Power on the system.
2. For first-time use, enter a new password when prompted.
   
   ![Complete Smart Door Lock System Setup](https://github.com/user-attachments/assets/97729ab6-04f7-4e35-a065-5c3d9a296c21)
   
   *Figure 4: LCD display showing the prompt to enter a new password*
     
3. To unlock the door, enter the correct password using the keypad.
   
   ![Entering password to unlock the door](https://github.com/user-attachments/assets/611b3408-e51e-4165-8588-b4e545b4ccbe)
   
   *Figure 5: User entering the password on the keypad*

4. If an incorrect password is entered three consecutive times:
   - The system will lock for 5 seconds.
   - An email alert will be sent to the registered email address.
   - The email will contain a link to access live video streaming from the ESP32-CAM.
     
   ![Email alert and live streaming interface](https://github.com/user-attachments/assets/bf672343-9305-4d0f-b631-756d865a84ec)
   
   *Figure 6: Email alert received and the live streaming interface*
 
## Contributing
Contributions to improve the Smart Door Lock System are welcome. Please follow these steps to contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your fork.
5. Submit a pull request with a clear description of your changes.

---

This project was developed by Ridham Rangani and Neel Sheth from the Electronics and Communication department at Nirma University, Ahmedabad.

For any questions or concerns, please contact:
- 21BEC103@nirmauni.ac.in
- 21BEC116@nirmauni.ac.in

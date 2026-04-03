# Surveillance Rover: Autonomous Navigation & Face Recognition

An intelligent, multi-tier surveillance system integrating autonomous navigation, remote web-based control, and dual-sensor human detection. The system employs a distributed architecture where a Raspberry Pi 4 acts as the master controller for AI tasks, interfaced with two Arduino microcontrollers for real-time sensor processing and motor control.

## 🚀 Features

* **Edge AI Face Recognition:** Real-time facial identification using OpenCV and `face_recognition` libraries.
* **Dual-Flag Security Logic:** Reduces false positives by requiring both PIR motion and camera-based recognition to trigger alerts.
* **Autonomous Navigation:** Continuous distance monitoring via 4x HC-SR04 ultrasonic sensors with a 98% obstacle avoidance success rate.
* **Web Dashboard:** A Flask-based interface for live monitoring and manual override control via HTTP.
* **Low-Latency Communication:** Robust UART serial communication between the Pi and Arduinos with an average latency of 5ms.

## 🛠️ Hardware Specifications

* **Central Processor:** Raspberry Pi 4B.
* **Microcontrollers:** 2x Arduino Uno (Motor and Sensor Controllers).
* **Sensors:** 4x Ultrasonic Sensors (HC-SR04), 1x PIR Motion Sensor, 1x CSI Ribbon Camera.
* **Drive System:** 4x DC Motors with H-bridge driver ICs.
* **Power:** 12V Li-ion battery pack with regulated 5V supply.

## 📁 Project Structure

* `robot(py_file).txt`: The main Flask application running on the Raspberry Pi.
* `MotorCode.ino`: Arduino firmware for PWM motor control and H-bridge interfacing.
* `Capture_faces.txt` & `Encode_captures_faces_into_.pklfile.txt`: Scripts for building the authorized personnel dataset and generating facial encodings.
* `Recognize_faces.txt`: Dedicated edge AI recognition script.
* `IEEE_Report.pdf`: Comprehensive technical documentation and experimental results.

## 🔧 Installation & Setup

### 1. Arduino Configuration
Flash the `MotorCode.ino` to your Motor Controller Arduino. Ensure the baud rate is set to `9600`.

### 2. Raspberry Pi Setup
Install the required Python dependencies:
```bash
pip install flask opencv-python face_recognition pyserial requests
```

### 3. Dataset Preparation
1. Run `Capture_faces.py` to take photos of authorized users.
2. Run `Encode_faces.py` to generate the `encodings.pkl` file.

### 4. Launch
Start the main controller:
```bash
python robot.py
```
Access the dashboard at `http://<your-pi-ip>:5000`.

## 👥 Authors

* **Moiz Ud Din Kakakhel** - *Software Lead*
* **Saad Mirza** - *Hardware Architecture*

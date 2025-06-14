# 🔌 Dynamic Energy Monitoring System using ESP32

A real-time energy monitoring system built using ESP32, OLED, and analog inputs to simulate voltage and current. This simulation calculates Power (W), Energy (kWh), and Estimated Electricity Bill (৳).

---

## 🔍 Project Overview

This project simulates a **smart energy monitoring system** using:
- 📟 OLED display for real-time data
- 🎚️ Two potentiometers to simulate voltage and current
- ⚡ Real-time calculation of:
  - Voltage (V)
  - Current (A)
  - Power (W)
  - Energy (kWh)
  - Estimated Bill (৳)

✅ Fully simulated using **Wokwi** – no physical hardware needed initially!

---

## 🛠️ Components Used

| Component         | Quantity | Purpose                     |
|------------------|----------|-----------------------------|
| ESP32 Dev Module | 1        | Microcontroller             |
| OLED Display (SSD1306) | 1   | Display output              |
| Potentiometer     | 2        | Simulate voltage & current  |
| Jumper Wires      | N/A      | Connections                 |

---

## 📈 Simulation Link

🔗 [Click here to open Wokwi Simulation](https://wokwi.com/projects/433737208181535745)  
> If not loading, please make sure you are logged into Wokwi.

---

## ⚙️ How It Works

- Two potentiometers act as analog inputs for voltage and current (VP = GPIO 36, VN = GPIO 39).
- The ESP32 reads these inputs, converts them to approximate values.
- It then calculates:
  - **Power = Voltage × Current**
  - **Energy = Power × Time**
  - **Bill = Energy × Rate**
- OLED shows real-time data while also printing to Serial Monitor.

---

## 💡 Features

- Real-time voltage and current monitoring
- Power and energy usage estimation
- Electricity billing in BDT (Taka)
- OLED + Serial output
- Fully online simulation using Wokwi

---

## 🧰 Pin Configuration

### OLED Display (I2C)
| OLED Pin | ESP32 Pin |
|----------|-----------|
| GND      | GND       |
| VCC      | 3.3V      |
| SCL      | GPIO 22   |
| SDA      | GPIO 21   |

### Potentiometers

#### 🎚️ Pot 1 – Voltage (VP / GPIO 36)
| Pin | ESP32 |
|-----|-------|
| GND | GND   |
| VCC | 3.3V  |
| SIG | GPIO 36 (VP) |

#### 🎚️ Pot 2 – Current (VN / GPIO 39)
| Pin | ESP32 |
|-----|-------|
| GND | GND   |
| VCC | 3.3V  |
| SIG | GPIO 39 (VN) |

---

## 🧠 Future Scope

- 🛰️ Send data to Firebase / cloud for remote monitoring
- 📱 Display dashboard on mobile app / web interface
- 🔌 Integrate with real current sensors (ACS712/INA219)
- 🛑 Add over-voltage or over-current protection alerts

---

## 👨‍💻 Developed By

**Md. Ahasanul Islam Nafim**  
🎓 EECE Student at MIST | 💻 Full Stack Developer | 🔗 [LinkedIn](https://www.linkedin.com/in/nafim-islam-b30901281/)  

---



# 🔐 PIR Motion Sensor — Security System Simulation
### Maincrafts Technology Internship | Task 2 | Embedded Systems & IoT

![Arduino](https://img.shields.io/badge/Platform-Arduino%20UNO-blue?logo=arduino)
![Simulator](https://img.shields.io/badge/Simulator-Tinkercad-orange)
![Language](https://img.shields.io/badge/Language-C%2B%2B-brightgreen)
![Status](https://img.shields.io/badge/Status-Completed-success)

---

## 📌 Project Overview

A **PIR-based home security system** built on Arduino UNO using Tinkercad simulator. The system detects human motion using a PIR sensor and responds with:

- 🔴 **Red LED** blinking rapidly (visual alarm)
- 🔊 **Buzzer** beeping 3 times (audio alarm)
- 📟 **Serial Monitor** alerts with motion event counter
- ✅ Automatic reset after each detection cycle

This simulates real-world burglar alarms and intruder detection systems.

---

## 🧰 Components Used

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino UNO | 1 | Microcontroller |
| PIR Motion Sensor | 1 | Detects infrared radiation from humans |
| Red LED | 1 | Visual alarm indicator |
| Buzzer | 1 | Audio alarm output |
| 220Ω Resistor | 2 | Current limiting for LED |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | Several | Connections |

---

## 🔌 Circuit Connections

```
PIR Sensor:
  VCC  ──────────── Arduino 5V
  GND  ──────────── Arduino GND
  OUT  ──────────── Arduino Pin 7

Red LED:
  Anode (+) ──[220Ω]── Arduino Pin 13
  Cathode(–) ───────── Arduino GND

Buzzer:
  (+)  ──────────── Arduino Pin 8
  (–)  ──────────── Arduino GND
```

---

## 💻 How It Works

### PIR Sensor Science
> PIR = **Passive Infrared** — it doesn't emit anything, only receives.

Every human body emits **infrared radiation (heat)**. The PIR sensor has **two internal slots**:
- **No motion** → both slots detect equal IR → Output = LOW
- **Person moves** → heat shifts from slot A to slot B → difference triggers → Output = HIGH

The **white dome** (Fresnel lens) focuses IR from a wide 110°–120° field onto the internal elements.

### System Flow
```
Power ON
    │
    ▼
setup() — Initialize pins, print "Security System ACTIVE"
    │
    ▼
loop() — Runs forever
    │
    ├── PIR = HIGH (Motion!) ──► motionCount++
    │                             Print "INTRUDER ALERT!"
    │                             LED blinks + Buzzer beeps x3
    │                             LED stays ON 2 seconds
    │                             Print "System resetting..."
    │                             Wait 1 second
    │
    └── PIR = LOW (No motion) ──► Print "All clear."
                                   Wait 1 second
```

---

## 📂 File Structure

```
PIR-Security-System/
│
├── pir_security_system.ino   # Main Arduino sketch
└── README.md                 # Project documentation
```

---

## 🚀 How to Run

### On Tinkercad (Recommended)
1. Go to [tinkercad.com](https://www.tinkercad.com) → Circuits → Create New
2. Add: Arduino UNO, PIR Sensor, Red LED, Buzzer, 220Ω Resistors
3. Wire as per the connection table above
4. Click **Code** → switch to **Text** mode
5. Paste code from `pir_security_system.ino`
6. Click **Start Simulation**
7. Open **Serial Monitor** to see real-time alerts
8. Click the PIR sensor to simulate motion detection

### On Real Hardware (Arduino UNO)
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Connect components on breadboard as per circuit diagram
3. Open `pir_security_system.ino` in Arduino IDE
4. Select board: **Arduino UNO** and correct COM port
5. Click **Upload**
6. Open Serial Monitor at **9600 baud**

---

## 📊 Serial Monitor Output

```
==============================
   Security System ACTIVE     
==============================
Waiting for motion...

All clear. No motion detected.
All clear. No motion detected.
==============================
WARNING: INTRUDER ALERT!
Motion Event #: 1
==============================
System resetting...
------------------------------

All clear. No motion detected.
```

---

## 🌍 Real-World Applications

| Application | Connection to This Project |
|-------------|---------------------------|
| Home Burglar Alarm | Same PIR + buzzer + alert logic |
| Automatic Corridor Lights | Replace LED with relay for real bulbs |
| Museum Artifact Security | Motion counter tracks intrusions |
| Shopping Mall Entry Counter | motionCount variable tracks visitors |
| Warehouse Monitoring | Serial alerts can be sent via WiFi (ESP32) |

---

## 🎓 Key Learnings

- ✅ How PIR sensors detect infrared radiation from living beings
- ✅ Using `digitalRead()` to read digital sensor signals
- ✅ Implementing threshold-based triggering logic in C++
- ✅ Combining multiple outputs (LED + Buzzer) for realistic alarm behavior
- ✅ Serial Monitor for real-time debugging and monitoring
- ✅ Tinkercad circuit simulation and prototyping workflow

---

## 👤 Author

**[Your Name]**  
Embedded Systems & IoT Intern  
Maincrafts Technology  
📧 [your.email@example.com]

---

## 🏢 Organization

**Maincrafts Technology**  
🌐 [www.maincrafts.com](https://www.maincrafts.com)  
📧 hr@maincrafts.com

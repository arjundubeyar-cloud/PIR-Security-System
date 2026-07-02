# 🔐 PIR Motion Sensor — Security System Simulation
### Maincrafts Technology Internship | Task 2 | Embedded Systems & IoT


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

---

## 👤 Author

**Arjun Dubey**  
Embedded Systems & IoT Intern  
Maincrafts Technology  
📧 arjundubeyar@gmail.com

---

## 🏢 Organization

**Maincrafts Technology**  
🌐 [www.maincrafts.com](https://www.maincrafts.com)  
📧 hr@maincrafts.com

<p align="center">
  <img src="https://github.com/Muhammed-Turgut/imageRaw/blob/main/embeded_system_readme_photo/L293D_with_ardunio.jpg?raw=true" width="900"/>
</p>

<h1 align="center">🚗 DC Motor Control with Arduino UNO and L293B</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Arduino%20UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/Driver-L293B-6A0DAD?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Control-PWM-FF6B35?style=for-the-badge"/>
</p>

<p align="center">
  An Arduino project that drives a DC motor with speed and direction control using the L293B motor driver IC.
</p>

---

## 📋 Table of Contents

- [About the Project](#-about-the-project)
- [Required Components](#-required-components)
- [Circuit Connections](#-circuit-connections)
- [Code](#-code)
- [How It Works](#-how-it-works)
- [Circuit Images](#-circuit-images)

---

## 🔍 About the Project

The Arduino UNO cannot drive DC motors directly due to its limited current output. In this project, the **L293B motor driver IC** is used to achieve:

- ⚡ DC motor **speed control** (0–100% via PWM)
- 🔄 DC motor **direction control** (forward / backward)
- 🛡️ Back-EMF protection (via flyback diodes)

---

## 🛒 Required Components

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| L293B Motor Driver IC | 1 |
| DC Motor | 1 |
| 1N4007 Diode | 2 |
| Breadboard | 1 |
| Jumper Wires | Several |
| External Power Supply (9V–15V) | 1 |

---

## 🔌 Circuit Connections

```
Arduino UNO        L293B
───────────────────────────
D9  (PWM)    →    Pin 1  (EN1)
D8           →    Pin 2  (IN1)
D7           →    Pin 7  (IN2)
5V           →    Pin 16 (VCC)
GND          →    Pin 4,5 (GND)

L293B              DC Motor
───────────────────────────
Pin 3  (OUT1) →   Motor (+)
Pin 6  (OUT2) →   Motor (-)

External Power Supply
───────────────────────────
(+) → L293B Pin 8 (VS)
(-) → GND (common ground)

Diode Connections (Back-EMF Protection)
────────────────────────────────────────
D1: Anode → OUT1,  Cathode → GND
D2: Anode → OUT2,  Cathode → GND
```

> ⚠️ **Important:** The Arduino GND and the external power supply GND must be connected to a common ground!

---

## 💻 Code

```cpp
const int EN1 = 9;   // PWM - speed control
const int IN1 = 8;   // Direction pin 1
const int IN2 = 7;   // Direction pin 2

void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Motor ready!");
}

// Spin motor forward
void motorForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, speed);  // 0-255
}

// Spin motor backward
void motorBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, speed);  // 0-255
}

// Stop the motor
void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 0);
}

void loop() {
  Serial.println("Forward - slow");
  motorForward(100);    // ~39% speed
  delay(2000);

  Serial.println("Forward - full speed");
  motorForward(255);    // 100% speed
  delay(2000);

  Serial.println("Stop");
  motorStop();
  delay(1000);

  Serial.println("Backward - medium speed");
  motorBackward(180);   // ~70% speed
  delay(2000);

  Serial.println("Stop");
  motorStop();
  delay(1000);
}
```

---

## ⚙️ How It Works

### Direction Control

| IN1 | IN2 | Result |
|-----|-----|--------|
| HIGH | LOW | Motor Forward ▶ |
| LOW | HIGH | Motor Backward ◀ |
| LOW | LOW | Motor Stop ⏹ |
| HIGH | HIGH | ❌ Don't do this! |

### Speed Control

A PWM signal between **0–255** is sent to the EN1 pin via `analogWrite()`:

```
0   → Motor stopped  (0%)
128 → Half speed     (50%)
255 → Full speed     (100%)
```

### Diode Protection

When the motor is powered off, it generates **back-EMF**. The 1N4007 diodes redirect this voltage to GND, protecting the L293B from damage.

---

## 📸 Circuit Images

<p align="center">
  <img src="https://github.com/Muhammed-Turgut/imageRaw/blob/main/embeded_system_readme_photo/circuit_drawing.jpeg?raw=true" width="700"/>
  <br><i>Circuit Diagram</i>
</p>

<p align="center">
  <img src="https://github.com/Muhammed-Turgut/imageRaw/blob/main/embeded_system_readme_photo/image_1.jpeg?raw=true" width="700"/>
  <br><i>Real Circuit - View 1</i>
</p>

<p align="center">
  <img src="https://github.com/Muhammed-Turgut/imageRaw/blob/main/embeded_system_readme_photo/image_2.jpeg?raw=true" width="700"/>
  <br><i>Real Circuit - View 2</i>
</p>

---

<p align="center">
  <i>Made by Muhammed Turgut</i>
</p>

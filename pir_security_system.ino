/*
 * ============================================
 *   PIR Motion Sensor - Security System
 *   Maincrafts Technology Internship - Task 2
 *   Platform: Tinkercad (Arduino UNO)
 * ============================================
 *
 * Components:
 *   - Arduino UNO
 *   - PIR Motion Sensor (OUT -> Pin 7)
 *   - Red LED (Pin 13 via 220 ohm resistor)
 *   - Buzzer (Pin 8)
 *
 * Behavior:
 *   - Motion detected -> LED blinks + Buzzer beeps 3x -> INTRUDER ALERT on Serial
 *   - No motion       -> "All clear" printed every second
 *   - Tracks total motion count throughout session
 */

// ── Pin Definitions ──
#define PIR_PIN    7    // PIR sensor output pin
#define LED_PIN    13   // Red LED pin
#define BUZZER_PIN 8    // Buzzer pin

// ── Global Variables ──
int motionCount = 0;    // Tracks number of motion events

// ──────────────────────────────────────────
void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN,    INPUT);
  pinMode(LED_PIN,    OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("==============================");
  Serial.println("   Security System ACTIVE     ");
  Serial.println("==============================");
  Serial.println("Waiting for motion...");
  Serial.println();
}

// ──────────────────────────────────────────
void loop() {
  int motionState = digitalRead(PIR_PIN);

  if (motionState == HIGH) {
    motionCount++;

    // ── Alert on Serial Monitor ──
    Serial.println("==============================");
    Serial.println("WARNING: INTRUDER ALERT!");
    Serial.print("Motion Event #: ");
    Serial.println(motionCount);
    Serial.println("==============================");

    // ── Blink LED + Beep Buzzer 3 times ──
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN,    HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(300);
      digitalWrite(LED_PIN,    LOW);
      digitalWrite(BUZZER_PIN, LOW);
      delay(300);
    }

    // ── Keep LED ON for 2 seconds as visual hold ──
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    digitalWrite(LED_PIN, LOW);

    Serial.println("System resetting...");
    Serial.println("------------------------------");
    Serial.println();
    delay(1000);

  } else {
    Serial.println("All clear. No motion detected.");
    delay(1000);
  }
}

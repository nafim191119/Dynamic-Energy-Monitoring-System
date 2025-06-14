#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pinVolt = 36; // A0
const int pinCurr = 39; // A3

float energy = 0;
unsigned long lastTime = 0;
const float rate = 7.0; // Tk per kWh

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  lastTime = millis();
}

void loop() {
  float rawV = analogRead(pinVolt);
  float voltage = rawV / 4095.0 * 240.0;

  float rawI = analogRead(pinCurr);
  float current = (rawI / 4095.0 * 5.0 - 2.5) / 0.185; // simulate ±5A

  float power = voltage * current;

  unsigned long now = millis();
  energy += power * (now - lastTime) / (1000.0 * 3600.0); // Wh to kWh
  lastTime = now;

  float bill = energy * rate;

  // Display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("V(rms): %.1f V\nI(rms): %.2f A\nPower: %.1f W\nE: %.4f kWh\nBill: %.2f Tk",
                 voltage, current, power, energy, bill);
  display.display();

  // Serial Output
  Serial.printf("Voltage: %.1f V | Current: %.2f A | Power: %.1f W | Energy: %.4f kWh | Bill: %.2f Tk\n",
                 voltage, current, power, energy, bill);

  delay(1000);
}


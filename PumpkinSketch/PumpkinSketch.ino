/*
  Halloween Pumpkin
  Description:
  Hardware: Lightup using PIR sensor and on-board NeoPixels and Buzzer
  Library: Adafruit NeoPixel library
  Author: ROBO
  Date: October 2025 
*/

#include <Adafruit_NeoPixel.h>

#define PIXELS_PIN 8        // NeoPixels pin
#define NUMPIXELS 3         // Number of NeoPixels
#define BUZZER_PIN 9        // Buzzer pin
#define MOTION_PIN 7        // PIR motion sensor input pin
#define WAIT 500            // Cooldown after motion sequence

// Define pixel positions
#define RED_PIXEL 0
#define ORANGE_PIXEL 1
#define LIGHTORANGE_PIXEL 2

// Colors
uint32_t redColor         = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t orangeColor      = Adafruit_NeoPixel::Color(255, 55, 0);
uint32_t lightorangeColor = Adafruit_NeoPixel::Color(255, 110, 0);
uint32_t offColor         = Adafruit_NeoPixel::Color(0, 0, 0);

// Note frequencies [Hz]
int cs6 = 1109;  
int fs5 = 740;
int d6  = 1175;
int c6  = 1047;
int f5  = 698;
int b5  = 988;
int e5  = 659;
int bf5 = 932;
int ef5 = 622;
int b4  = 494;
int g5  = 784;

// Melody timing
int desired_duration = 4000;           // Total melody duration [ms]
int note_duration = 200;               // Duration per note
int numTones = round(desired_duration / note_duration);

// Melody sequence (trimmed Halloween theme)
int tones[] = {
  cs6, fs5, fs5, cs6, fs5, fs5, cs6, fs5, d6, fs5,
  cs6, fs5, fs5, cs6, fs5, fs5, cs6, fs5, d6, fs5,
  c6, f5, f5, c6, f5, f5, c6, f5, cs6, f5,
  b5, e5, e5, b5, e5, e5, b5, e5, c6, e5,
  bf5, ef5, ef5, bf5, ef5, ef5, bf5, ef5, b5, ef5,
  fs5, b4, b4, fs5, b4, b4, fs5, b4, g5, b4
};

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXELS_PIN, NEO_GRB + NEO_KHZ800);

int motionState = LOW;
unsigned long lastMotionTime = 0;
unsigned long idleFlickerTimer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MOTION_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pixels.begin();
  pixels.setBrightness(255);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, offColor);
  }
  pixels.show();
}

void loop() {
  motionState = digitalRead(MOTION_PIN);

  if (motionState == HIGH) {
    Serial.println("Motion detected!");
    playSpookySequence();
    lastMotionTime = millis();
    delay(WAIT);
  } else {
    // Subtle idle flicker (soft candle effect)
    unsigned long now = millis();
    if (now - idleFlickerTimer > 80) { // every ~80 ms
      idleFlickerTimer = now;
      softFlicker();
    }
  }
}

void softFlicker() {
  // Gentle, random low-brightness flicker for idle mode
  int flickerBrightness = random(10, 60); // between 10–60 brightness (out of 255)
  pixels.setBrightness(flickerBrightness);
  pixels.setPixelColor(RED_PIXEL, orangeColor);
  pixels.setPixelColor(ORANGE_PIXEL, lightorangeColor);
  pixels.setPixelColor(LIGHTORANGE_PIXEL, orangeColor);
  pixels.show();
}

void playSpookySequence() {
  // Turn on vivid colors
  pixels.setPixelColor(RED_PIXEL, redColor);
  pixels.setPixelColor(ORANGE_PIXEL, orangeColor);
  pixels.setPixelColor(LIGHTORANGE_PIXEL, lightorangeColor);
  pixels.show();

  for (int i = 0; i < numTones && i < (sizeof(tones) / sizeof(tones[0])); i++) {
    tone(BUZZER_PIN, tones[i]);
    
    // Dynamic flicker
    pixels.setBrightness(random(75, 255));
    pixels.show();
    delay(0.8 * note_duration);

    noTone(BUZZER_PIN);

    pixels.setBrightness(random(75, 255));
    pixels.show();
    delay(0.2 * note_duration);
  }

  // End of sequence
  noTone(BUZZER_PIN);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, offColor);
  }
  pixels.show();
}

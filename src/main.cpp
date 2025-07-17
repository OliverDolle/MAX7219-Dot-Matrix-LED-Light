#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// hardware-type | FC16_HW 
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

#define MAX_DEVICES 4  // 4 modules = 32x8 pixels

// Define connections
#define DATA_PIN  23   // DIN
#define CLK_PIN   18   // CLK
#define CS_PIN    5    // CS or LOAD

// Initialise Parola-object
MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// List of messages
const char* messages[] = {
  "You're Slow",
  "Bye",
  "See Ya" 
};

constexpr uint8_t NUM_MESSAGES = sizeof(messages) / sizeof(messages[0]);
uint8_t currentMessage = 0;

constexpr uint16_t SCROLL_DELAY_MS = 50; //Speed for animation

void setup() {
  display.begin();
  display.setIntensity(1);         // Light intensity 0-15
  display.displayClear();
  
  display.displayScroll(messages[currentMessage], PA_CENTER, PA_SCROLL_LEFT, SCROLL_DELAY_MS);

}

void loop() {
  // Animation for text
  if (display.displayAnimate()) {
    // Next message
    currentMessage = (currentMessage + 1) % NUM_MESSAGES;

    // Start of new message
    display.displayScroll(messages[currentMessage], PA_CENTER, PA_SCROLL_LEFT, SCROLL_DELAY_MS);
  
  }
}

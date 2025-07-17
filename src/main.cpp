#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Vælg hardware-type. FC16_HW er typisk for 8x8 MAX7219 moduler fra f.eks. Amazon/AliExpress.
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

#define MAX_DEVICES 4  // 4 moduler = 32x8 pixels

// Definer tilslutninger (kan ændres efter dit setup)
#define DATA_PIN  23   // DIN
#define CLK_PIN   18   // CLK
#define CS_PIN    5    // CS eller LOAD

// Initialisér Parola-objektet
MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  display.begin();
  display.setIntensity(5);         // Lysstyrke: 0-15
  display.displayClear();
  display.displayScroll("Hej fra ESP32 og MAX7219!", PA_CENTER, PA_SCROLL_LEFT, 100);
}

void loop() {
  // Skal kaldes løbende for at animere
  if (display.displayAnimate()) {
    display.displayReset();  // Gentag scroll
  }
}

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height

// Create display object with I2C address 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();             // Clear the buffer
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text
  display.setCursor(10, 10);          // Start at (x,y)
  display.println("MUSKAN THENUA");
  display.println("OLED with Arduino");
  display.println("Hello BCA 2C Section");
  display.println("How may I help You?");
  display.display();                  // Show on OLED
}

void loop() {
  // Nothing to loop
}
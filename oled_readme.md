# OLED with Arduino — Example

This repository contains a simple Arduino example that demonstrates how to drive a 128x64 I2C OLED (SSD1306) display using the Adafruit SSD1306 and Adafruit GFX libraries.

Example sketch: `oledwitharduino.ino`  
Source: https://github.com/bhawanasingh22/iot_assignments_2c_Bhawana_13/blob/1f7b4df305760dc023d1e3079f769ef80e0d5a3b/oledwitharduino.ino

## What this sketch does
- Initializes an SSD1306 128x64 I2C OLED at address 0x3C.
- Writes a few lines of text to the display:
  - "MUSKAN THENUA"
  - "OLED with Arduino"
  - "Hello BCA 2C Section"
  - "How may I help You?"
- Prints an error message to Serial if the display initialization fails.

## Hardware required
- Arduino board (Uno, Nano, Mega, etc.)
- 128x64 I2C SSD1306 OLED module (commonly labeled 0x3C)
- Female-to-male jumper wires
- USB cable to program the Arduino

## Libraries
Install the following Arduino libraries (Sketch → Include Library → Manage Libraries...):
- Adafruit SSD1306
- Adafruit GFX Library
The Wire library is part of the Arduino core and does not need separate installation.

## Wiring
Typical wiring for an Arduino Uno (I2C):
- OLED VCC → 3.3V or 5V (check your module specs)
- OLED GND → GND
- OLED SDA → A4 (Uno/Nano) or dedicated SDA pin on your board
- OLED SCL → A5 (Uno/Nano) or dedicated SCL pin on your board

Note: On many newer Arduino boards (e.g., Leonardo, Mega, Due) use the board's SDA and SCL pins rather than A4/A5.

## How to use
1. Install the required libraries (Adafruit SSD1306 and Adafruit GFX).
2. Open `oledwitharduino.ino` in the Arduino IDE.
3. Select the correct board and COM port.
4. Upload the sketch.
5. Optionally open the Serial Monitor (9600 baud) to see error messages:
   - If the display fails to initialize, the sketch prints: `SSD1306 allocation failed`.

## Important notes & common issues
- I2C address: most 128x64 modules use 0x3C. If your module uses 0x3D, change the address passed to `display.begin(...)`.
- Constructor/compatibility: the sketch uses the Adafruit_SSD1306 constructor:
  ```
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
  ```
  If you see compile errors related to the constructor signature, update the library or adapt the constructor call to your installed library version. Some versions use a different constructor signature — check the Adafruit_SSD1306 examples shipped with your library.
- Power: connect VCC to the correct voltage (module-specific). Supplying incorrect voltage may damage the module.
- Blank screen: check wiring, I2C address, and library versions. Run an I2C scanner sketch to confirm the OLED address.

## Customization
- Change text strings, sizes, and cursor positions using:
  - `display.setTextSize(x)`
  - `display.setTextColor(SSD1306_WHITE)`
  - `display.setCursor(x, y)`
  - `display.println("your text")`
- You can draw graphics using Adafruit GFX drawing functions (lines, rectangles, bitmaps, etc.).

## Expected output
After a successful upload, the OLED should display four lines of white text on a black background:
- MUSKAN THENUA
- OLED with Arduino
- Hello BCA 2C Section
- How may I help You?

## Troubleshooting checklist
- Is the correct I2C address used (0x3C vs 0x3D)?
- Are SDA/SCL connected to the correct pins for your board?
- Are the required libraries installed and up to date?
- Is the module powered with the correct voltage?
- Use an I2C scanner sketch to verify the module responds on the bus.

## License
MIT — feel free to reuse and modify the code. Include attribution if you redistribute.

## Author
Bhawana Singh (repo owner: bhawanasingh22)

File referenced: `oledwitharduino.ino`  
Permalink to referenced file:  
https://github.com/bhawanasingh22/iot_assignments_2c_Bhawana_13/blob/1f7b4df305760dc023d1e3079f769ef80e0d5a3b/oledwitharduino.ino

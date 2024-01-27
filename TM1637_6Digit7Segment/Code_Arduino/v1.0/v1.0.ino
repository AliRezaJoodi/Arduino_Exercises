#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 9
#define DIO 10

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   500

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};

TM1637Display display(CLK, DIO);

void setup(){
}

void loop(){
  int k;
  uint8_t data[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  uint8_t blank[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  display.setBrightness(7);

  // All segments on
  //display.setSegments(data, 6);
  //delay(TEST_DELAY);

  // Selectively set different digits
  data[0] = display.encodeDigit(0);
  data[1] = display.encodeDigit(1);
  data[2] = display.encodeDigit(2);
  data[3] = display.encodeDigit(3);
  data[4] = display.encodeDigit(4);
  data[5] = display.encodeDigit(5);
  display.setSegments(data, 6);
  delay(TEST_DELAY);

  display.clear();
  for(k = 3; k >= 0; k--) {
	display.setSegments(data, 2, k); delay(TEST_DELAY);
  display.clear();
	}

  display.clear();
  display.setSegments(data, 2, 2);
  delay(TEST_DELAY);

  display.clear();
  display.setSegments(data+2, 2, 1);
  delay(TEST_DELAY);

  display.clear();
  display.setSegments(data+1, 3, 1);
  delay(TEST_DELAY);

  // Show decimal numbers with/without leading zeros
  display.showNumberDec(0, false, 6); delay(TEST_DELAY); // Expect: _____0
  display.showNumberDec(0, true, 6); delay(TEST_DELAY); // Expect: 000000
	display.showNumberDec(1, false, 6); delay(TEST_DELAY); // Expect: _____1
  display.showNumberDec(1, true, 6); delay(TEST_DELAY); // Expect: 000001
  display.showNumberDec(301, false, 6); delay(TEST_DELAY); // Expect: ___301
  display.showNumberDec(301, true, 6); delay(TEST_DELAY); // Expect: 000301

  display.clear();
  display.showNumberDec(14, false, 2, 1); delay(TEST_DELAY); // Expect: _14___
  display.clear();
  display.showNumberDec(4, true, 2, 2); delay(TEST_DELAY); // Expect: __04__
 
  display.showNumberDec(-1, false, 6); delay(TEST_DELAY); // Expect: ____-1
  display.showNumberDec(-12, false, 6); delay(TEST_DELAY); // Expect: ___-12
  display.showNumberDec(-999, false, 6); delay(TEST_DELAY); // Expect: __-999

  display.clear();
  display.showNumberDec(-5, false, 6, 0); delay(TEST_DELAY); // Expect: ____-5
  display.showNumberHexEx(0xf1af, 0, false, 6, 0); delay(TEST_DELAY); // Expect: __f1Af
  display.showNumberHexEx(0x2c, 0, false, 6, 0); delay(TEST_DELAY); // Expect: ____2C
  display.showNumberHexEx(0xd1, 0, true, 6, 0); delay(TEST_DELAY); // Expect: 0000d1
  display.clear();
  display.showNumberHexEx(0xd1, 0, true, 2, 0); delay(TEST_DELAY); // Expect: d1____
 
  //display.clear(); display.showNumberDecEx(0, 0b00001000, true, 6, 0); delay(TEST_DELAY);

  // Brightness Test
  for(k = 0; k < 6; k++)
	data[k] = 0xff;
  for(k = 0; k < 7; k++) {
    display.setBrightness(k);
    display.setSegments(data, 6);
    delay(TEST_DELAY);
  }
 
  // On/Off test
  for(k = 0; k < 4; k++) {
    display.setBrightness(7, false);  // Turn off
    display.setSegments(data, 6);
    delay(TEST_DELAY);
    display.setBrightness(7, true); // Turn on
    display.setSegments(data, 6);
    delay(TEST_DELAY);  
  }

  // Done!
  display.setSegments(SEG_DONE);

  while(1);
}

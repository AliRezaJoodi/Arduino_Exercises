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
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0F);

  // All segments on
  display.setSegments(data);
  delay(TEST_DELAY);

  // Selectively set different digits
  data[0] = display.encodeDigit(0);
  data[1] = display.encodeDigit(1);
  data[2] = display.encodeDigit(2);
  data[3] = display.encodeDigit(3);
  display.setSegments(data);
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
  display.showNumberDec(0, false); delay(TEST_DELAY); // Expect: ___0
  display.showNumberDec(0, true); delay(TEST_DELAY); // Expect: 0000
	display.showNumberDec(1, false); delay(TEST_DELAY); // Expect: ___1
  display.showNumberDec(1, true); delay(TEST_DELAY); // Expect: 0001
  display.showNumberDec(301, false); delay(TEST_DELAY); // Expect: _301
  display.showNumberDec(301, true); delay(TEST_DELAY); // Expect: 0301
  display.clear();
  display.showNumberDec(14, false, 2, 1); delay(TEST_DELAY); // Expect: _14_
  display.clear();
  display.showNumberDec(4, true, 2, 2); delay(TEST_DELAY); // Expect: __04
  display.showNumberDec(-1, false); delay(TEST_DELAY); // Expect: __-1
  display.showNumberDec(-12); delay(TEST_DELAY); // Expect: _-12
  display.showNumberDec(-999); delay(TEST_DELAY); // Expect: -999

  display.clear();
  display.showNumberDec(-5, false, 3, 0); delay(TEST_DELAY); // Expect: _-5_
  display.showNumberHexEx(0xf1af); delay(TEST_DELAY); // Expect: f1Af
  display.showNumberHexEx(0x2c); delay(TEST_DELAY); // Expect: __2C
  display.showNumberHexEx(0xd1, 0, true); delay(TEST_DELAY); // Expect: 00d1
  display.clear();
  display.showNumberHexEx(0xd1, 0, true, 2); delay(TEST_DELAY); // Expect: d1__
  
	// Run through all the dots
	for(k=0; k <= 4; k++) {
		display.showNumberDecEx(0, (0x80 >> k), true);
		delay(TEST_DELAY);
	}

  // Brightness Test
  for(k = 0; k < 4; k++)
	data[k] = 0xff;
  for(k = 0; k < 7; k++) {
    display.setBrightness(k);
    display.setSegments(data);
    delay(TEST_DELAY);
  }
  
  // On/Off test
  for(k = 0; k < 4; k++) {
    display.setBrightness(7, false);  // Turn off
    display.setSegments(data);
    delay(TEST_DELAY);
    display.setBrightness(7, true); // Turn on
    display.setSegments(data);
    delay(TEST_DELAY);  
  }

  // Done!
  display.setSegments(SEG_DONE);

  while(1);
}

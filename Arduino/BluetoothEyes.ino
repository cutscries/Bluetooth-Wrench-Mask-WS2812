/* Tom's Wrench Mask forked by benzoganger and rewriten to FastLED library for WS2812 LED support */
/* Original project by https://github.com/TomMakesThings */

#include <FastLED.h>

#define NUM_LEDS_EYE_LEFT 64
#define NUM_LEDS_EYE_RIGHT 64
#define DATA_PIN_EYE_LEFT 12
#define DATA_PIN_EYE_RIGHT 5

CRGB eye_left[NUM_LEDS_EYE_LEFT];
CRGB eye_right[NUM_LEDS_EYE_RIGHT];

unsigned long transitionTime=5;
unsigned long blinkTime=200;  
unsigned long longblinkTime=400;
unsigned long shortTime=800;
unsigned long normalTime=2000;
unsigned long longTime=6000;

String currentValue = "key28";
String data = "";
int maxBrightness = 255;
int frame = 0;


// X_X
byte X[] = 
{ 
  B11000011,
  B01100110,
  B00111100,
  B00011000,
  B00111100,
  B01100110,
  B11000011,
  B00000000
};

// ^_^
byte wink[] =
{
  B00000000,
  B00011000,
  B00011000,
  B00111100,
  B00100100,
  B01100110,
  B01000010,
  B11000011
};

byte wink_blink[] =
{
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01100110,
  B11000011,
  B00000000,
  B00000000
};

// v_v
byte wink_reverse[] =
{
  B11000011,
  B01000010,
  B01100110,
  B00100100,
  B00111100,
  B00011000,
  B00011000,
  B00000000
};

// >_>
byte rightwink[] = 
{
  B10000000,
  B11100000,
  B00111000,
  B00001110,
  B00001110,
  B00111000,
  B11100000,
  B10000000
};

// <_<
byte leftwink[] = 
{
  B00000001,
  B00000111,
  B00011100,
  B01110000,
  B01110000,
  B00011100,
  B00000111,
  B00000001
};

// /_o
byte right_slash[] =
{
  B00000011,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B11000000,
  B10000000
};

// \_o
byte left_slash[] =
{
  B11000000,
  B01100000,
  B00110000,
  B00011000,
  B00001100,
  B00000110,
  B00000011,
  B00000001
};


// ?_?
byte question[] =
{
  B00111100,
  B01111110,
  B01100110,
  B00000110,
  B00011100,
  B00011000,
  B00000000,
  B00011000
};


// #_#
byte hashtag[] = 
{
  B00100100,
  B00100100,
  B11111111,
  B00100100,
  B00100100,
  B11111111,
  B00100100,
  B00100100
};

// <3
byte heart[] =
{
  B00000000,
  B01100110,
  B10011001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
};

byte heart2[] =
{
  B00000000,
  B01100110,
  B11111111,
  B11011011,
  B11000011,
  B01100110,
  B00111100,
  B00011000
};

byte heart3[] =
{
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};

// =_=
byte equal[] =
{
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000
};

// ~_o
byte tilde[] =
{
  B00000000,
  B00000000,
  B01110000,
  B11111001,
  B10011111,
  B00001110,
  B00000000,
  B00000000
};

// -_-
byte minus[] =
{
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

// $_$
byte dollar[] =
{
  B00010000,
  B00111100,
  B01010010,
  B01010000,
  B00111100,
  B00010010,
  B01010010,
  B00111100
};

// !_!
byte exclamation[] = 
{
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00011000,
  B00011000
};

// O_O
byte O[] = 
{
  B00111100,
  B01000010,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B01000010,
  B00111100
};

// o_o
byte smallo[] = 
{
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000
};

// @_@
byte at[] =
{
  B00111100,
  B01000010,
  B10011101,
  B10100101,
  B10100101,
  B10011010,
  B01000000,
  B00111110
};

// ;_;
byte semicolon[] =
{
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00001000,
  B00010000
};

byte semicolonblink[] =
{
  B00000000,
  B00111100,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00001000,
  B00010000
};

// 9_9
byte nineEye[] =
{
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011100,
  B00000100,
  B00100100,
  B00011000
};

// ¬_¬
byte negation[] = 
{
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000011,
  B00000011,
  B00000000,
  B00000000
};

// ..._...
byte tripleDot[] =
{
  B00000000,
  B00000000,
  B00000000,
  B11011011,
  B11011011,
  B00000000,
  B00000000,
  B00000000
};

byte tripleDotBlink[] =
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11011011,
  B00000000,
  B00000000,
  B00000000
};

// *_*
byte star[] =
{
  B00000000,
  B00010000,
  B01010100,
  B00111000,
  B00010000,
  B00101000,
  B01000100,
  B00000000
};

byte bracket[] =
{
  B00000000,
  B00000000,
  B10000001,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

byte bracketBlink[] =
{
  B00000000,
  B00000000,
  B00000000,
  B10000001,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

byte invader1a[] =
{
   B00011000,  // First frame of invader #1
   B00111100,
   B01111110,
   B11011011,
   B11111111,
   B00100100,
   B01011010,
   B10100101
};

byte invader1b[] =
{
  B00011000, // Second frame of invader #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

byte invader2a[] =
{
  B00100100, // First frame of invader #2
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

byte invader2b[] =
{
  B00100100, // Second frame of invader #2
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};

// T_T
byte t[] =
{
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte lenny[] =
{
  B00000000,
  B00000000,
  B01111110,
  B11001001,
  B01001000,
  B00110000,
  B00000000,
  B00000000
};

byte musicNote[] =
{
  B00001100,
  B00001110,
  B00001011,
  B00001001,
  B00001000,
  B00111000,
  B01111000,
  B00110000
};

// "_"
byte leftQuote[] =
{
  B00000000,
  B01101100,
  B01101100,
  B01001000,
  B01001000,
  B00100100,
  B00000000,
  B00000000
};

// "_"
byte rightQuote[] =
{
  B00000000,
  B00110110,
  B00110110,
  B00010010,
  B00010010,
  B00100100,
  B00000000,
  B00000000
};

// '_'
byte leftApostrophe[] =
{
  B00000000,
  B00100000,
  B00110000,
  B00011000,
  B00001000,
  B00000000,
  B00000000,
  B00000000
};

// '_'
byte rightApostrophe[] =
{
  B00000000,
  B00000100,
  B00001100,
  B00011000,
  B00010000,
  B00000000,
  B00000000,
  B00000000
};

byte leftApostropheBlink[] = 
{
  B00000000,
  B00000000,
  B00100000,
  B00010000,
  B00001000,
  B00000000,
  B00000000,
  B00000000
};

byte rightApostropheBlink[] =
{
  B00000000,
  B00000000,
  B00000100,
  B00001000,
  B00010000,
  B00000000,
  B00000000,
  B00000000
};

byte rectangle[] =
{
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100
};

// +_+
byte plus[] =
{
  B00011000,
  B00011000,
  B00011000,
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00011000
};

// <-_<-
byte leftArrow1[] =
{
  B00000000,
  B00100000,
  B01100000,
  B11111111,
  B01100000,
  B00100000,
  B00000000,
  B00000000
};

byte leftArrow2[] =
{
  B00000000,
  B00000000,
  B00100000,
  B01100000,
  B11111111,
  B01100000,
  B00100000,
  B00000000
};

// ->_->
byte rightArrow1[] =
{
  B00000000,
  B00000100,
  B00000110,
  B11111111,
  B00000110,
  B00000100,
  B00000000,
  B00000000
};

byte rightArrow2[] = 
{
  B00000000,
  B00000000,
  B00000100,
  B00000110,
  B11111111,
  B00000110,
  B00000100,
  B00000000
};

byte refresh1[] =
{
  B00111101,
  B01000011,
  B10000111,
  B10000000,
  B00000001,
  B11100001,
  B11000010,
  B10111100
};

byte refresh2[] =
{
  B11101100,
  B01100010,
  B10100001,
  B10000001,
  B10000001,
  B10000101,
  B01000110,
  B00110111
};

byte charge1[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11000001,
  B11000001,
  B11000001,
  B11111111,
  B00000000
};

byte charge2[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11100001,
  B11100001,
  B11100001,
  B11111111,
  B00000000
};

byte charge3[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11110001,
  B11110001,
  B11110001,
  B11111111,
  B00000000
};

byte charge4[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11111001,
  B11111001,
  B11111001,
  B11111111,
  B00000000
};

byte charge5[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11111101,
  B11111101,
  B11111101,
  B11111111,
  B00000000
};

byte charge6[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B00000000
};

byte tick[] =
{
  B00000000,
  B00000011,
  B00000110,
  B00001100,
  B11011000,
  B01110000,
  B00100000,
  B00000000
};

byte pacman1[] =
{
  B00111100,
  B01111110,
  B00111011,
  B00011111,
  B00001111,
  B00011111,
  B01111110,
  B00111100
};

byte pacman2[] =
{
  B00111100,
  B01111110,
  B11111011,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100
};

byte ghost1[] =
{
  B00111000,
  B01111100,
  B10010010,
  B11011010,
  B10010010,
  B11111110,
  B11111110,
  B10101010
};

byte ghost2[] =
{
  B00111000,
  B01111100,
  B10010010,
  B10110110,
  B10010010,
  B11111110,
  B11111110,
  B10101010
};

byte ghost3[] =
{
  B00111000,
  B01111100,
  B11011010,
  B10010010,
  B10010010,
  B11111110,
  B11111110,
  B10101010
};

byte colon[] =
{
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000
};

byte cute[] =
{
  B00111100,
  B01001110,
  B10011111,
  B10011111,
  B10011111,
  B10011111,
  B01001110,
  B00111100
};

byte n[] =
{
  B00111100,
  B01111110,
  B11100111,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011
};

// U_U
byte u[] =
{
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100
};

// Z_Z
byte z[] = 
{
  B11111111,
  B11111111,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01111111,
  B11111111
};

byte hollowSquare[] =
{
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11111111
};

byte aries[] =
{
  B01100110,
  B11111111,
  B10011001,
  B10011001,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte taurus[] =
{
  B00100010,
  B01010101,
  B00010100,
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00011100
};

byte gemini[] =
{
  B11111111,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B11111111
};

byte cancer[] =
{
  B01111110,
  B10010001,
  B10010001,
  B01100000,
  B00000110,
  B10001001,
  B10001001,
  B01111110
};

byte leo[] =
{
  B00011000,
  B00100100,
  B00100100,
  B00100100,
  B01100101,
  B10010010,
  B10010000,
  B01100000
};

byte virgo[] =
{
  B00000000,
  B10111010,
  B01010101,
  B01010101,
  B01010101,
  B01000110,
  B01001100,
  B00010100
};

byte libra[] =
{
  B00111100,
  B01111110,
  B01000010,
  B01000010,
  B11100111,
  B00000000,
  B11111111,
  B00000000
};

byte scorpio[] =
{
  B00000000,
  B10111000,
  B01010100,
  B01010100,
  B01010100,
  B01000101,
  B01000101,
  B00000010
};

byte sagitarius[] =
{
  B00001111,
  B00000011,
  B00000101,
  B01001001,
  B00110000,
  B00110000,
  B01001000,
  B10000000
};

byte capricorn[] =
{
  B00000000,
  B10110000,
  B01001010,
  B01001101,
  B01001001,
  B01001010,
  B01001100,
  B00011000
};

byte aquarius[] =
{
  B00000000,
  B00000000,
  B01010101,
  B10101010,
  B00000000,
  B01010101,
  B10101010,
  B00000000
};

byte pisces[] =
{
  B11000011,
  B00100100,
  B00100100,
  B11111111,
  B00100100,
  B00100100,
  B00100100,
  B11000011
};

byte female[] =
{
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00011100,
  B00001000,
  B00011100,
  B00001000
};

byte male[] =
{
  B00000111,
  B00000011,
  B00000101,
  B00111000,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte flashingSquare1[] =
{
  B11111111,
  B10000001,
  B10111101,
  B10100101,
  B10100101,
  B10111101,
  B10000001,
  B11111111
};

byte flashingSquare2[] =
{
  B00000000,
  B01111110,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B01111110,
  B00000000
};

byte roundLeft[] =
{
  B00111100,
  B01000010,
  B10110001,
  B10110001,
  B10110001,
  B10110001,
  B01000010,
  B00111100
};

byte roundCentre[] =
{
  B00111100,
  B01000010,
  B10011001,
  B10011001,
  B10011001,
  B10011001,
  B01000010,
  B00111100
};

byte roundRight[] =
{
  B00111100,
  B01000010,
  B10001101,
  B10001101,
  B10001101,
  B10001101,
  B01000010,
  B00111100
};

byte roundFull[] = 
{
  B00111100,
  B01000010,
  B10111101,
  B10111101,
  B10111101,
  B10111101,
  B01000010,
  B00111100
};

boolean controlledDelay(unsigned long delayValue) {
  for (int i = 0; i < delayValue; i++) {
    if (Serial.peek() == '(') {
      return true;
    }
    delay(1);
  }
  return false;
}

boolean inKeySet(String value)
{
  boolean valid = false;
  if (value.substring(0, 3) == "key" && value.substring(3).toInt() <= 47) {
    valid = true;
  }
  return valid;
}

void displayEyes(const byte emoticonLeft[], const byte emoticonRight[]) {
  for (int i = 0; i < 8; i++) {
    byte left = emoticonLeft[i];
    byte right = emoticonRight[i];
    int indexOffset = i * 8;
    
    for (int j = 0; j < 8; j++) {
      eye_left[indexOffset + j] = (left >> j) & 1 ? CRGB::Red : CRGB::Black;
      eye_right[indexOffset + j] = (right >> j) & 1 ? CRGB::Red : CRGB::Black;
    }
  }
  FastLED.show();
}


void sleep_eyes() {
  // Set brightness to 50%
  int targetBrightness = maxBrightness / 2;
  FastLED.setBrightness(targetBrightness);
  FastLED.show();

  // Set both eyes to (z, z)
  displayEyesSlow(z, z);
  displayEyes(z, z);

  // Gradually dim the brightness
  double step = 0.1;
  for (double j = maxBrightness; j > 0; j -= step) {
    FastLED.setBrightness(j);
    FastLED.show();
    if (controlledDelay(25)) {
      break;
    }
  }
}

void wink_eyes()
{
  if (frame == 0) {
    frame = 1;
    displayEyesSlow(tilde, wink_reverse);
    displayEyes(tilde, wink_reverse);
    controlledDelay(normalTime);
    removeEyesSlow(tilde, wink_reverse);
  }
  else {
    frame = 0;
    displayEyesSlow(wink, wink);
    displayEyes(wink, wink);
    controlledDelay(normalTime);
    removeEyesSlow(wink, wink);
  }
}

void clearDisplays() {
  for (int i = 0; i < NUM_LEDS_EYE_LEFT; i++) {
    eye_left[i] = CRGB::Black;
    eye_right[i] = CRGB::Black;
  }
  FastLED.show();
}

void shy_eyes()
{
  displayEyes(wink, wink);
  controlledDelay(longTime);
  clearDisplays();
  displayEyes(wink_blink, wink_blink);
  controlledDelay(blinkTime);
}

void displayEyesSlow(const byte emoticonLeft[], const byte emoticonRight[]) {
  int limit = 1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < limit; j++) {
      int indexOffset = 7 - (j + (8 - limit));
      eye_left[indexOffset + i * 8] = (emoticonLeft[7 - j] >> (7 - i)) & 1 ? CRGB::Red : CRGB::Black;
      eye_right[indexOffset + i * 8] = (emoticonRight[7 - j] >> (7 - i)) & 1 ? CRGB::Red : CRGB::Black;
    }
    FastLED.show();
    controlledDelay(transitionTime);
    clearDisplays();
    limit++;
  }
}

void uneven_round_eyes()
{
  if (frame == 0) {
    if (random(0, 2) == 0) {
      frame = 1;
    }
    generic_eyes(O, smallo);
  }
  else if (frame == 1) {
    frame = 2;
    generic_eyes(O, O);
  }
  else if (frame == 2) {
    if (random(0, 2) == 0) {
      frame = 3;
    }
    generic_eyes(smallo, O);
  }
  else if (frame == 3) {
    frame = 0;
    generic_eyes(O, O);
  }
}

void generic_eyes(byte eye0[], byte eye1[])
{
  displayEyes(eye0, eye1);
  controlledDelay(longTime);
  clearDisplays();
  displayEyes(minus, minus);
  controlledDelay(blinkTime);
  clearDisplays();
}

void custom_blink_eyes(byte frame1[], byte frame2[]) {
  displayEyes(frame1, frame1);
  controlledDelay(shortTime);
  clearDisplays();
  displayEyes(frame2, frame2);
  controlledDelay(shortTime);
  clearDisplays();
}

void cry_eyes()
{
  displayEyes(semicolon, semicolon);
  controlledDelay(longTime);
  clearDisplays();
  displayEyes(semicolonblink, semicolonblink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void tripleDot_eyes()
{
  displayEyes(tripleDot, tripleDot);
  controlledDelay(longTime);
  clearDisplays();
  displayEyes(tripleDotBlink, tripleDotBlink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void heart_eyes()
{
  if (frame == 0) {
    frame = 1;
    displayEyesSlow(heart, heart);
    displayEyes(heart, heart);
    controlledDelay(longblinkTime);
    clearDisplays();
  }
  else if (frame == 1) {
    frame = 2;
    displayEyes(heart2, heart2);
    controlledDelay(longblinkTime);
    clearDisplays();
  }
  else if (frame == 2) {
    frame = 3;
    displayEyes(heart3, heart3);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 3) {
    frame = 0;
    displayEyes(heart2, heart2);
    controlledDelay(longblinkTime);
    clearDisplays();
    displayEyesSlow(heart, heart);
  }
}

void bracket_eyes()
{
  displayEyes(bracket, bracket);
  controlledDelay(longTime);
  clearDisplays();
  displayEyes(bracketBlink, bracketBlink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void swear_eyes()
{
  switch(random(0,6)) {
    case 0:
    displayEyes(hashtag, hashtag);
    break;

    case 1:
    displayEyes(dollar, dollar);
    break;

    case 2:
    displayEyes(star, star);
    break;

    case 3:
    displayEyes(at, at);
    break;

    case 4:
    displayEyes(question, question);
    break;

    case 5:
    displayEyes(exclamation, exclamation);
    break;
  }
  controlledDelay(blinkTime);
  clearDisplays();
}

void charge_eyes()
{
  displayEyes(charge1, charge1);
  controlledDelay(shortTime);
  clearDisplays();
  displayEyes(charge2, charge2);
  controlledDelay(shortTime);
  clearDisplays();
  displayEyes(charge3, charge3);
  controlledDelay(shortTime);
  clearDisplays();
  displayEyes(charge4, charge4);
  controlledDelay(shortTime);
  clearDisplays();
  displayEyes(charge5, charge5);
  controlledDelay(shortTime);
  clearDisplays();
  displayEyes(charge6, charge6);
  controlledDelay(shortTime);
  clearDisplays();
}

void flashing_square_eyes()
{
  for (int i = 0; i < 5; i++) {
    displayEyes(flashingSquare1, flashingSquare1);
    controlledDelay(longblinkTime);
    clearDisplays();
    displayEyes(flashingSquare2, flashingSquare2);
    controlledDelay(longblinkTime);
    clearDisplays();
  }
  displayEyes(minus, minus);
  controlledDelay(blinkTime);
  clearDisplays();
}

void apostrophe_eyes()
{
  displayEyes(leftApostrophe, rightApostrophe);
  controlledDelay(longTime);
  clearDisplays();
  displayEyes(leftApostropheBlink, rightApostropheBlink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void round_dot_eyes()
{
  int frame = random(0, 4);
  if (frame == 0) {
    generic_eyes(roundLeft, roundLeft);
  }
  else if (frame == 1) {
    generic_eyes(roundRight, roundRight);
  }
  else {
    generic_eyes(roundCentre, roundCentre);
  }
}

void repeatEyes() {
  if (currentValue == "key1") {
    // Dead eyes X_X
    generic_eyes(X, X);
  }
  if (currentValue == "key2") {
    // Shy eyes ^_^
    shy_eyes();
  }
  if (currentValue == "key3") {
    // Normal ^_^
    // Wink ~_v
    wink_eyes();
  }
  if (currentValue == "key4") {
    // Equals sign eyes =_=
    generic_eyes(equal, equal);
  }
  if (currentValue == "key5") {
    // Hashtag eyes #_#
    generic_eyes(hashtag, hashtag);
  }
  if (currentValue == "key6") {
    // Eyes closed >_<
    generic_eyes(rightwink, leftwink);
  }
  if (currentValue == "key7") {
    // At sign eyes @_@
    generic_eyes(at, at);
  }
  if (currentValue == "key8") {
    // Crying eyes ;_;
    cry_eyes();
  }
  if (currentValue == "key9") {
    // Z eyes Z_Z
    sleep_eyes();
  }
  if (currentValue == "key10") {
    // Exclamation mark eyes !_!
    generic_eyes(exclamation, exclamation);
  }
  if (currentValue == "key11") {
    // Question mark eyes ?_?
    generic_eyes(question, question);
  }
  if (currentValue == "key12") {
    // Negation eyes ¬_¬
    generic_eyes(negation, negation);
  }
  if (currentValue == "key13") {
    // Nine eyes 9_9
    generic_eyes(nineEye, nineEye);
  }
  if (currentValue == "key14") {
    // Dot dot dot eyes ..._...
    tripleDot_eyes();
  }
  if (currentValue == "key16") {
    // Heart eyes <3_<3
    heart_eyes();
  }
  if (currentValue == "key17") {
    // Round eyes O_O
    generic_eyes(O, O);
  }
  if (currentValue == "key18") {
    // Uneven round eyes O_o
    uneven_round_eyes();
  }
  if (currentValue == "key19") {
    // Sideways bracket eyes -_-
    bracket_eyes();
  }
  if (currentValue == "key20") {
    // Star eyes *_*
    generic_eyes(star, star);
  }
  if (currentValue == "key21") {
    // T eyes T_T
    generic_eyes(t, t);
  }
  if (currentValue == "key22") {
    // Lenny eyes
    generic_eyes(lenny, lenny);
  }
  if (currentValue == "key24") {
    // Quote eyes "_"
    generic_eyes(leftQuote, rightQuote);
  }
  if (currentValue == "key25") {
    //Apostrophe eyes '_'
    apostrophe_eyes();
  }
  if (currentValue == "key26") {
    // Rectangle eyes
    generic_eyes(rectangle, rectangle);
  }
  if (currentValue == "key27") {
    // Plus eyes +_+
    generic_eyes(plus, plus);
  }
  if (currentValue == "key28") {
    // Swear eyes
    swear_eyes();
  }
  if (currentValue == "key29") {
    // U eyes U_U
    generic_eyes(u, u);
  }
  if (currentValue == "key30") {
    // Left arrow eyes <-_<-
    custom_blink_eyes(leftArrow1, leftArrow2);
  }
  if (currentValue == "key31") {
    // Right arrow eyes ->_->
    custom_blink_eyes(rightArrow1, rightArrow2);
  }
  if (currentValue == "key32") {
    // Refresh eyes
    custom_blink_eyes(refresh1, refresh2);
  }
  if (currentValue == "key33") {
    // Charge eyes
    charge_eyes();
  }
  if (currentValue == "key34") {
    // Tick eyes
    generic_eyes(tick, tick);
  }
  if (currentValue == "key36") {
    // Cute eyes
    generic_eyes(cute, cute);
  }
  if (currentValue == "key37") {
    // n eyes n_n
    generic_eyes(n, n);
  }
  if (currentValue == "key38") {
    // Square eyes
    generic_eyes(hollowSquare, hollowSquare);
  }
  if (currentValue == "key40") {
    // Female eyes
    generic_eyes(female, female);
  }
  if (currentValue == "key41") {
    // Male eyes
    generic_eyes(male, male);
  }
  if (currentValue == "key42") {
    // Flashing square eyes
    flashing_square_eyes();
  }
  if (currentValue == "key43") {
    // Round dot eyes
    round_dot_eyes();
  }
  if (currentValue == "key45") {
    // Inward slash eyes
    generic_eyes(left_slash, right_slash);
  }
  if (currentValue == "key46") {
    // Outward slash eyes
    generic_eyes(right_slash, left_slash);
  }
  if (currentValue == "key47") {
    // Round filled eyes
    generic_eyes(roundFull, roundFull);
  }
}

void removeEyes()
{
  if (currentValue == "key1") {
    // Dead eyes X_X
    removeEyesSlow(X, X);
  }
  if (currentValue == "key2") {
    // Shy eyes ^_^
    removeEyesSlow(wink_blink, wink_blink);
  }
  if (currentValue == "key4") {
    // Equals sign eyes =_=
    removeEyesSlow(equal, equal);
  }
  if (currentValue == "key5") {
    // Hashtag eyes #_#
    removeEyesSlow(hashtag, hashtag);
  }
  if (currentValue == "key6") {
    // Eyes closed >_<
    removeEyesSlow(rightwink, leftwink);
  }
  if (currentValue == "key7") {
    // At sign eyes @_@
    removeEyesSlow(at, at);
  }
  if (currentValue == "key8") {
    // Crying eyes ;_;
    removeEyesSlow(semicolon, semicolon);
  }
  if (currentValue == "key10") {
    // Exclamation mark eyes !_!
    removeEyesSlow(exclamation, exclamation);
  }
  if (currentValue == "key11") {
    // Question mark eyes ?_?
    removeEyesSlow(question, question);
  }
  if (currentValue == "key12") {
    // Negation eyes ¬_¬
    removeEyesSlow(negation, negation);
  }
  if (currentValue == "key13") {
    // Nine eyes 9_9
    removeEyesSlow(nineEye, nineEye);
  }
  if (currentValue == "key14") {
    // Dot dot dot eyes ..._...
    removeEyesSlow(tripleDot, tripleDot);
  }
  if (currentValue == "key15") {
    // Money eyes $_$
    removeEyesSlow(wink, wink);
  }
  if (currentValue == "key16") {
    // eyes <3_<3
    removeEyesSlow(wink, wink);
  }
  if (currentValue == "key17") {
    // Round eyes O_O
    removeEyesSlow(O, O);
  }
  if (currentValue == "key18") {
    // Uneven round eyes O_o
    removeEyesSlow(O, smallo);
  }
  if (currentValue == "key19") {
    // Sideways bracket eyes -_-
    removeEyesSlow(bracket, bracket);
  }
  if (currentValue == "key20") {
    // Star eyes *_*
    removeEyesSlow(star, star);
  }
  if (currentValue == "key21") {
    // T eyes T_T
    removeEyesSlow(t, t);
  }
  if (currentValue == "key22") {
    // Lenny eyes
    removeEyesSlow(lenny, lenny);
  }
  if (currentValue == "key23") {
    // Music note eyes
    removeEyesSlow(musicNote, musicNote);
  }
  if (currentValue == "key24") {
    // Quote eyes "_"
    removeEyesSlow(leftQuote, rightQuote);
  }
  if (currentValue == "key25") {
    // Apostrophe eyes '_'
    removeEyesSlow(leftApostrophe, rightApostrophe);
  }
  if (currentValue == "key26") {
    // Rectangle eyes
    removeEyesSlow(rectangle, rectangle);
  }
  if (currentValue == "key27") {
    // Plus eyes +_+
    removeEyesSlow(plus, plus);
  }
  if (currentValue == "key28") {
    // Swear eyes
    removeEyesSlow(hashtag, hashtag);
  }
  if (currentValue == "key29") {
    // U eyes U_U
    removeEyesSlow(u, u);
  }
  if (currentValue == "key30") {
    // Left arrow eyes <-_<-
    removeEyesSlow(leftArrow2, leftArrow2);
  }
  if (currentValue == "key31") {
    // Right arrow eyes ->_->
    removeEyesSlow(rightArrow2, rightArrow2);
  }
  if (currentValue == "key32") {
    // Refresh eyes
    removeEyesSlow(refresh2, refresh2);
  }
  if (currentValue == "key33") {
    // Charge eyes
    removeEyesSlow(charge6, charge6);
  }
  if (currentValue == "key34") {
    // Tick eyes
    removeEyesSlow(tick, tick);
  }
  if (currentValue == "key36") {
    // Cute eyes
    removeEyesSlow(cute, cute);
  }
  if (currentValue == "key37") {
    // n eyes n_n
    removeEyesSlow(n, n);
  }
  if (currentValue == "key38") {
    // square eyes
    removeEyesSlow(hollowSquare, hollowSquare);
  }
  if (currentValue == "key39") {
    // Zodiac eyes
    removeEyesSlow(aries, aries);
  }
  if (currentValue == "key40") {
    // Female eyes
    removeEyesSlow(female, female);
  }
  if (currentValue == "key41") {
    // Male eyes
    removeEyesSlow(male, male);
  }
  if (currentValue == "key42") {
    // Flashing square eyes
    removeEyesSlow(flashingSquare2, flashingSquare2);
  }
  if (currentValue == "key43") {
    // Round dot eyes
    removeEyesSlow(roundCentre, roundCentre);
  }
  if (currentValue == "key45") {
    // Inward slash eyes
    removeEyesSlow(left_slash, right_slash);
  }
  if (currentValue == "key46") {
    // Outward slash eyes
    removeEyesSlow(right_slash, left_slash);
  }
  if (currentValue == "key47") {
    // Round filled eyes
    removeEyesSlow(roundFull, roundFull);
  }
}

void removeEyesSlow(const byte emoticonLeft[], const byte emoticonRight[]) {
  int limit = 8;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < limit; j++) {
      int indexOffset = 7 - (j + (8 - limit));
      eye_left[indexOffset + i * 8] = (emoticonLeft[7 - j] >> (7 - i)) & 1 ? CRGB::Red : CRGB::Black;
      eye_right[indexOffset + i * 8] = (emoticonRight[7 - j] >> (7 - i)) & 1 ? CRGB::Red : CRGB::Black;
    }
    FastLED.show();
    controlledDelay(transitionTime);
    clearDisplays();
    limit--;
  }
}

void changeEyes() {
  if (currentValue == "key1") {
    // Dead eyes X_X
    displayEyesSlow(X, X);
    generic_eyes(X, X);
  }
  if (currentValue == "key2") {
    // Shy eyes ^_^
    displayEyesSlow(wink, wink);
    shy_eyes();
  }
  if (currentValue == "key3") {
    // Normal ^_^
    // Wink ~_v
    wink_eyes();
  }
  if (currentValue == "key4") {
    // Equals sign eyes =_=
    displayEyesSlow(equal, equal);
    generic_eyes(equal, equal);
  }
  if (currentValue == "key5") {
    // Hashtag eyes #_#
    displayEyesSlow(hashtag, hashtag);
    generic_eyes(hashtag, hashtag);
  }
  if (currentValue == "key6") {
    // Eyes closed >_<
    displayEyesSlow(rightwink, leftwink);
    generic_eyes(rightwink, leftwink);
  }
  if (currentValue == "key7") {
    // At sign eyes @_@
    displayEyesSlow(at, at);
    generic_eyes(at, at);
  }
  if (currentValue == "key8") {
    // Crying eyes ;_;
    displayEyesSlow(semicolon, semicolon);
    cry_eyes();
  }
  if (currentValue == "key9") {
    // Z eyes Z_Z
    sleep_eyes();
  }
  if (currentValue == "key10") {
    // Exclamation mark eyes !_!
    generic_eyes(exclamation, exclamation);
  }
  if (currentValue == "key11") {
    // Question mark eyes ?_?
    generic_eyes(question, question);
  }
  if (currentValue == "key12") {
    // Negation eyes ¬_¬
    displayEyesSlow(negation, negation);
    generic_eyes(negation, negation);
  }
  if (currentValue == "key13") {
    // Nine eyes 9_9
    displayEyesSlow(nineEye, nineEye);
    generic_eyes(nineEye, nineEye);
  }
  if (currentValue == "key14") {
    // Dot dot dot eyes ..._...
    displayEyesSlow(tripleDot, tripleDot);
    tripleDot_eyes();
  }
  if (currentValue == "key16") {
    // Heart eyes <3_<3
    displayEyesSlow(heart, heart);
    heart_eyes();
  }
  if (currentValue == "key17") {
    // Round eyes O_O
    displayEyesSlow(O, O);
    generic_eyes(O, O);
  }
  if (currentValue == "key18") {
    // Uneven round eyes O_o
    displayEyesSlow(O, smallo);
    uneven_round_eyes();
  }
  if (currentValue == "key19") {
    // Sideways bracket eyes -_-
    displayEyesSlow(bracket, bracket);
    bracket_eyes();
  }
  if (currentValue == "key20") {
    // Star eyes *_*
    displayEyesSlow(star, star);
    generic_eyes(star, star);
  }
  if (currentValue == "key21") {
    // T eyes T_T
    displayEyesSlow(t, t);
    generic_eyes(t, t);
  }
  if (currentValue == "key22") {
    // Lenny eyes
    displayEyesSlow(lenny, lenny);
    generic_eyes(lenny, lenny);
  }
  if (currentValue == "key24") {
    // Quote eyes "_"
    displayEyesSlow(leftQuote, rightQuote);
    generic_eyes(leftQuote, rightQuote);
  }
  if (currentValue == "key25") {
    //Apostrophe eyes '_'
    displayEyesSlow(leftApostrophe, rightApostrophe);
    apostrophe_eyes();
  }
  if (currentValue == "key26") {
    // Rectangle eyes
    displayEyesSlow(rectangle, rectangle);
    generic_eyes(rectangle, rectangle);
  }
  if (currentValue == "key27") {
    // Plus eyes +_+
    displayEyesSlow(plus, plus);
    generic_eyes(plus, plus);
  }
  if (currentValue == "key28") {
    // Swear eyes
    displayEyesSlow(hashtag, hashtag);
    swear_eyes();
  }
  if (currentValue == "key29") {
    // U eyes U_U
    displayEyesSlow(u, u);
    generic_eyes(u, u);
  }
  if (currentValue == "key30") {
    // Left arrow eyes <-_<-
    displayEyesSlow(leftArrow1, leftArrow1);
    custom_blink_eyes(leftArrow2, leftArrow2);
  }
  if (currentValue == "key31") {
    // Right arrow eyes ->_->
    displayEyesSlow(rightArrow1, rightArrow1);
    custom_blink_eyes(rightArrow2, rightArrow2);
  }
  if (currentValue == "key32") {
    // Refresh eyes
    displayEyesSlow(refresh1, refresh1);
    custom_blink_eyes(refresh1, refresh2);
  }
  if (currentValue == "key33") {
    // Charge eyes
    displayEyesSlow(charge1, charge1);
    charge_eyes();
  }
  if (currentValue == "key34") {
    // Tick eyes
    displayEyesSlow(tick, tick);
    generic_eyes(tick, tick);
  }
  if (currentValue == "key36") {
    // Cute eyes
    displayEyesSlow(cute, cute);
    generic_eyes(cute, cute);
  }
  if (currentValue == "key37") {
    // n eyes n_n
    displayEyesSlow(n, n);
    generic_eyes(n, n);
  }
  if (currentValue == "key38") {
    // Square eyes
    displayEyesSlow(hollowSquare, hollowSquare);
    generic_eyes(hollowSquare, hollowSquare);
  }
  if (currentValue == "key40") {
    // Female eyes
    displayEyesSlow(female, female);
    generic_eyes(female, female);
  }
  if (currentValue == "key41") {
    // Male eyes
    displayEyesSlow(male, male);
    generic_eyes(male, male);
  }
  if (currentValue == "key42") {
    // Flashing square eyes
    displayEyesSlow(flashingSquare1, flashingSquare1);
    flashing_square_eyes();
  }
  if (currentValue == "key43") {
    // Round dot eyes
    displayEyesSlow(roundCentre, roundCentre);
    round_dot_eyes();
  }
  if (currentValue == "key45") {
    // Inward slash eyes
    displayEyesSlow(left_slash, right_slash);
    generic_eyes(left_slash, right_slash);
  }
  if (currentValue == "key46") {
    // Outward slash eyes
    displayEyesSlow(right_slash, left_slash);
    generic_eyes(right_slash, left_slash);
  }
  if (currentValue == "key47") {
    // Round filled eyes
    displayEyesSlow(roundFull, roundFull);
    generic_eyes(roundFull, roundFull);
  }
}

void setup() {
  Serial.begin(9600);  // Инициализируем серийник
  FastLED.addLeds<WS2812, DATA_PIN_EYE_LEFT, GRB>(eye_left, NUM_LEDS_EYE_LEFT);
  FastLED.addLeds<WS2812, DATA_PIN_EYE_RIGHT, GRB>(eye_right, NUM_LEDS_EYE_RIGHT);
  FastLED.setBrightness(255);
  changeEyes();
}

void loop() {
    while (Serial.available()) {
    // Stores incoming data
    String data = "";
    char c = Serial.read();
    if (c == '(') {
      boolean receivingMessage = true;
      while (receivingMessage) {
        if (Serial.available()) {
          c = Serial.read();
          if (c == ')') {
            receivingMessage = false;
          }
          else {
            data += c;
          }
        }
        else {
          receivingMessage = false;
        }
      }
    }
    if (data != currentValue && inKeySet(data)) {
      removeEyes();
      if (currentValue != "key44") {
      controlledDelay(blinkTime);
      }
      currentValue = data;
      frame = 0;
      changeEyes();
    }
  }
repeatEyes();
}

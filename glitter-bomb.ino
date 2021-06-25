/*
  Title: Glitter Bomb!

  Authors:
    Rafferty Beresford
    Pete Beresford
*/

// Include libraries for our components
#include <LiquidCrystal.h>
#include <IRremote.h>
#include "IR_Receiver_Module\IR.h"

// Setup instance of the Infrared receiver and decoder
IRrecv irrecv(RECEIVER);
decode_results results;

// Initialize the LCD
const int rs = 12, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Global variables
bool glitterBombHit = false;
int numberOfPlayers = 0;
int currentPlayer = 0;
int someScore = 0;
int glitterBomb = 30;
bool skipInstructions = false;

// Make some custom characters
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

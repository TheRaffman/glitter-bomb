void setup()
{  
  // Debug logging to the serial port
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  
  // set up the LCD's number of columns and rows (16 cols x 2 rows)
  lcd.begin(16, 2);

  // Create new characters
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  
  // Print a message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Loading...");
  lcd.setCursor(0, 1);
  lcd.print("Please wait...");

  pinMode(RED_STRIP, OUTPUT);
  pinMode(GREEN_STRIP, OUTPUT);
  pinMode(BLUE_STRIP, OUTPUT);

  randomSeed(analogRead(0));
}

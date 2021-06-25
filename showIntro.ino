void showIntro()
{
  // Write to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Welcome to ");
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.print(" GLITTER BOMB ");
  lcd.write(byte(0));
  delay(2000);
}

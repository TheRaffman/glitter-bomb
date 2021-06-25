void gameOver()
{
  // Write to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ! GAME OVER ! ");
  dancingMen();
}

void dancingMen()
{
  Serial.println("Dancing men!"); 
  
  for (int i = 0; i < 10; i++)
  {
    for (int man = 1; man < 16; man += 2)
    {
      // The code loops inside here
      lcd.setCursor(man, 1);
      lcd.write(byte(3));
    }
    delay(500);
    for (int man = 1; man < 16; man += 2)
    {
      lcd.setCursor(man, 1);
      lcd.write(byte(4));
    }
    delay(500);
  }
}

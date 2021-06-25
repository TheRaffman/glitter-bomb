void gameOver(int playerScore[], int numberOfPlayers)
{
  // Write to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ! GAME OVER ! ");
  delay(2000);
  dancingMen(playerScore, numberOfPlayers);
}

void dancingMen(int playerScore[], int numberOfPlayers)
{
  Serial.println("Dancing men!"); 

  for (int player = 0; player < numberOfPlayers; player++)
  {
    lcd.setCursor(0, 0);
    lcd.print("Player: ");
    lcd.print(String(player + 1));
    lcd.print(" = ");
    lcd.print(playerScore[player]);

    for (int i = 0; i < 4; i++)
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
}

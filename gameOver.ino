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

  int highestScore = 0;
  int playerWithHighestScore = 0;

  for (int player = 0; player < numberOfPlayers; player++)
  {
    // Show the score for the player
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player: ");
    lcd.print(String(player + 1));
    lcd.print(" = ");
    lcd.print(playerScore[player]);

    // Keep track of winner
    // If a draw, set this player, if they got glittered then don't let them tie
    if (playerScore[player] == highestScore && playerThatGotGlittered != player)
    {
      highestScore = playerScore[player];
      playerWithHighestScore = player + 1;
    }    
    if (playerScore[player] > highestScore)
    {
      highestScore = playerScore[player];
      playerWithHighestScore = player + 1;
    }

    // Showing dancing men
    for (int i = 0; i < 3; i++)
    {
      for (int man = 1; man < 16; man += 2)
      {
        // The code loops inside here
        lcd.setCursor(man, 1);
        lcd.write(byte(3));
        LedStripFlash();
      }
      delay(500);
      for (int man = 1; man < 16; man += 2)
      {
        lcd.setCursor(man, 1);
        lcd.write(byte(4));
        LedStripFlash();
      }
      delay(500);
    }
  }

  // Show the winner!
  lcd.setCursor(0, 0);
  lcd.print("Player: ");
  lcd.print(String(playerWithHighestScore));
  lcd.print(" WINS!");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(String(highestScore));
  LedStripOff();
}

void LedStripFlash()
{
  if (rBright > 0)
  {
    rBright = 0;
    gBright = 255;
    bBright = 0;
  }
  else if (gBright > 0)
  {
    rBright = 0;
    gBright = 0;
    bBright = 255;
  }
  else if (bBright > 0)
  {
    rBright = 255;
    gBright = 0;
    bBright = 0;
  }
  else
  {
    rBright = 255;
    gBright = 0;
    bBright = 0;
  }
  analogWrite(RED_STRIP, rBright);
  analogWrite(GREEN_STRIP, gBright);
  analogWrite(BLUE_STRIP, bBright);
}

void LedStripOff() {
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_STRIP, brightness);
       analogWrite(RED_STRIP, brightness);
       analogWrite(BLUE_STRIP, brightness);
 
       brightness -= 1;
       delay(fadeSpeed);
   }
   brightness = 0;
    analogWrite(GREEN_STRIP, brightness);
    analogWrite(RED_STRIP, brightness);
    analogWrite(BLUE_STRIP, brightness);

}

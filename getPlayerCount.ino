int getPlayerCount()
{
  int getPlayerCount_players = 0;

  // Write to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No. of players?");
  lcd.setCursor(0, 1);
  lcd.print("(2 - 9): ");
  
  while (getPlayerCount_players < 2)
  {
    if (irrecv.decode(&results)) // have we received an IR signal?
    {
      // Process the key pressed
      getPlayerCount_players = getPlayerCount_buttonPressed(results.value);
      
      // Receive the next value
      irrecv.resume();
    }
  }

  // Pretend two players for now
  return getPlayerCount_players;
}

int getPlayerCount_buttonPressed(unsigned long keyCharacter)
{
  switch(keyCharacter)
    {       
      case KEY_2: return 2;
      case KEY_3: return 3;
      case KEY_4: return 4;
      case KEY_5: return 5;
      case KEY_6: return 6;
      case KEY_7: return 7;
      case KEY_8: return 8;
      case KEY_9: return 9;
      default:
        return 0;
    }
}

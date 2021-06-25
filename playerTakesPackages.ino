int playerTakesPackages(int currentPlayer)
{
  int packagesTaken = -1;

  // Write to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Player: ");
  lcd.print(String(currentPlayer));
  lcd.setCursor(0, 1);
  lcd.print("Take Packs (0-9)");

  while (packagesTaken < 0)
  {
    if (irrecv.decode(&results)) // have we received an IR signal?
    {
        // Process the key pressed
        packagesTaken = playerTakesPackages_buttonPressed(results.value);
        
        // Receive the next value
        irrecv.resume();
    }
  }

  return packagesTaken;
}

int playerTakesPackages_buttonPressed(unsigned long keyCharacter)
{
  switch(keyCharacter)
    {       
      case KEY_0: return 0;
      case KEY_1: return 1;
      case KEY_2: return 2;
      case KEY_3: return 3;
      case KEY_4: return 4;
      case KEY_5: return 5;
      case KEY_6: return 6;
      case KEY_7: return 7;
      case KEY_8: return 8;
      case KEY_9: return 9;
      default:
        return -1;

    }
}

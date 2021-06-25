void loop()
{
  // Reset values and inputs
  glitterBombHit = false;
  numberOfPlayers = 0;
  currentPlayer = 1;
  someScore = 0;
  glitterBomb = random(20,60);
  clearIrInputs();

  // Show intro
  showIntro();

  // Show instructions
  if (!skipInstructions)
  {
    showInstructions();
    skipInstructions = true;
  }

  // Get number of players
  numberOfPlayers = getPlayerCount();

  // Show that...
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No. Players: ");
  lcd.print(String(numberOfPlayers));
  delay(2000);

  // Main loop
  while (!glitterBombHit)
  {
    // Take packages and score it
    someScore += playerTakesPackages(currentPlayer);

    // Show the score...
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score is: ");
    lcd.print(String(someScore));    

    if (someScore >= glitterBomb)
    {
      lcd.setCursor(0, 1);
      lcd.print("Hit Bomb: ");
      lcd.print(String(glitterBomb));
      glitterBombHit = true;
      delay(1000);
    }
    delay(1000);

    // Next player
    currentPlayer++;
    if (currentPlayer > numberOfPlayers)
    {
      currentPlayer = 1;
    }
  }

  // Game Over!
  gameOver();
}

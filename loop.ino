void loop()
{
  // Loop variables that are reset each time the loop starts
  int numberOfPlayers = 0;          // How many people are playing in this game
  int currentPlayer = 1;            // The current player having a turn
  int packagesTakenThisTurn = 0;    // Packages taken by the player on their turn
  int playerScore[9];               // Store score for each player
  int totalRunningScore = 0;        // The running total score

  // Drain any stray IR inputs 
  clearIrInputs();

  // Show introduction screen
  showIntro();

  // Show instructions (only on first power-on)
  if (!skipInstructions)
  {
    showInstructions();
    skipInstructions = true;
  }

  // Get the number of players this time around (are people joining / leaving)
  numberOfPlayers = getPlayerCount();
  for (int i = 0; i < numberOfPlayers; i++)
  {
    playerScore[i] = 0;
  }
  int glitterBomb = random(numberOfPlayers * 20, numberOfPlayers * 60);  // Which package is the GLITTER BOMB!

  // Confirm number of players
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No. Players: ");
  lcd.print(String(numberOfPlayers));
  delay(2000);

  // Main loop
  while (totalRunningScore < glitterBomb)
  {
    // Take packages and score it
    packagesTakenThisTurn = playerTakesPackages(currentPlayer);
    totalRunningScore += packagesTakenThisTurn;

    // Still safe, not taken the glitter bomb
    if (totalRunningScore < glitterBomb)
    {
      // Array starts at ZERO so -1 from player number and store their score
      playerScore[currentPlayer - 1] += packagesTakenThisTurn;
    }

    // Show the current scores so people can get tactical!
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score is: ");
    lcd.print(String(totalRunningScore));

    // Player has taken the glitter bomb
    if (totalRunningScore >= glitterBomb)
    {
      playerThatGotGlittered = currentPlayer -1;
      lcd.setCursor(0, 1);
      lcd.print("Hit Bomb: ");
      lcd.print(String(glitterBomb));
      lcd.print(" !!");
      delay(3000);

      // Break out of the loop - GAME OVER!
      break;
    }

    // Let use see the screen score briefly before going to the next player
    delay(1000);

    // Next player, looping back to player 1 after everyone has had a go
    currentPlayer++;
    if (currentPlayer > numberOfPlayers)
    {
      currentPlayer = 1;
    }
  }

  // Game Over!
  gameOver(playerScore, numberOfPlayers);
}

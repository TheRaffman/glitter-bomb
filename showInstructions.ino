void showInstructions()
{
  // We can have multiple "pages" of instructions
  //                    1234567890123456
  writeInstructionPage("You take turns ", 
                       "to take as many");
  writeInstructionPage("packages as you", 
                       "can, BUT watch ");
  writeInstructionPage("out for the:   ", 
                       "GLITTER BOMB!! ");
  writeInstructionPage("If you take it ", 
                       "then you're out");
  writeInstructionPage("and game over! ", 
                       "Good luck!");
}

void writeInstructionPage(String line1, String line2)
{
  // Write to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(2000);
}

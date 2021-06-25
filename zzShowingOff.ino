// void mega_playerTakesPackages_buttonPressed(unsigned long keyCharacter)
// {
//   switch(keyCharacter)
//     {
//       case KEY_POWER:
//         showingOff();
//         break;

//       case KEY_FUNC_STOP :
//         loveRaff();
//         break;

//       case KEY_VOL_ADD:
//         wipeAndWrite("VOL+"); 
//         break;

//       case KEY_FAST_BACK:
//         wipeAndWrite("FAST BACK");
//         break;
      
//       case KEY_PAUSE:
//         dancingMen();
//         break;

//       case KEY_FAST_FORWARD:
//         wipeAndWrite("FAST FORWARD");
//         break;
        
//       case KEY_DOWN:
//         wipeAndWrite("DOWN");    
//         break;
        
//       case KEY_VOL_DE:
//         wipeAndWrite("VOL-");
//         break;

//       case KEY_UP:
//         wipeAndWrite("UP");
//         break;
        
//       case KEY_EQ:
//         wipeAndWrite("EQ");    
//         break;
        
//       case KEY_ST_REPT:
//         wipeAndWrite("ST/REPT");    
//         break;
        
//       case KEY_0: wipeAndWrite("0");    break;
//       case KEY_1: wipeAndWrite("1");    break;
//       case KEY_2: wipeAndWrite("2");    break;
//       case KEY_3: wipeAndWrite("3");    break;
//       case KEY_4: wipeAndWrite("4");    break;
//       case KEY_5: wipeAndWrite("5");    break;
//       case KEY_6: wipeAndWrite("6");    break;
//       case KEY_7: wipeAndWrite("7");    break;
//       case KEY_8: wipeAndWrite("8");    break;
//       case KEY_9: wipeAndWrite("9");    break;
      
//       case KEY_REPEAT: Serial.println("REPEAT"); break;  
//       default: 
//         wipeAndWrite("  other button  ");
//     }
// }

// void wipeAndWrite(String message)
// {
//   // Debug
//   Serial.println(message);

//   // Write to LCD
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print(message);
// }

// void showingOff()
// {
//   // Debug
//   Serial.println("Showboat Mode!");

//   // Write to LCD
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.write(byte(0));
//   lcd.write(byte(1));
//   lcd.write(byte(2));
//   lcd.write(byte(3));
//   lcd.write(byte(4));
// }

// void loveRaff()
// {
//   // Debug
//   Serial.println("I love Raff!");

//   // Write to LCD
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("I ");
//   lcd.write(byte(0));
//   lcd.print(" Rafferty!!");
// }

// void dancingMen()
// {
//   Serial.println("Dancing men!"); 
  
//   lcd.clear();

  

//   for (int i = 0; i < 20; i++)
//   {
//     // The code loops inside here
//     lcd.setCursor(0, 0);
//     lcd.write(byte(3));
//     delay(500);
//     lcd.setCursor(0, 0);
//     lcd.write(byte(4));
//     delay(500);
//   }

// }

#include <DigiKeyboard.h>

int sequence0_wait = 1000; //This allows you to set the time delay for sequence 0
int sequence1_wait = 5000; //This allows you to set the time delay for sequence 1

int i;

long randomtime;
long randomsequence;
long randomstop; 
long randominput;
long randomon;
long randomweb;

void setup() {
  DigiKeyboard.update();
}

void loop() {

  //Random Number generators
  randomtime = random(1000, 5000); //Sets a random delay before start between 1000-4999 milseconds
  randomstop = random(5000, 10000); //Sets a random delay at the end of the script between 5000-9999 miliseconds
  randomsequence = random(6); //Sets the random number to pick the prank
  randominput = random(3); //sets the random number for the notepad prank
  randomon = random(11); //sets the random time the caps lock prank goes for
  randomweb = random(3);//sets random number for website picking
  
  if (randomsequence == 0){ //Caps lock on off prank
    DigiKeyboard.sendKeyStroke(0);
    for (i = randomon; i = 0; i--){ //randomizer for the amount of times it does it for
      DigiKeyboard.sendKeyStroke(57);
      DigiKeyboard.delay(sequence0_wait);
      DigiKeyboard.sendKeyStroke(57);
    }   
  }

  else if (randomsequence == 1){ //scren orintion prank
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN, MOD_CONTROL_LEFT + MOD_ALT_LEFT);
    DigiKeyboard.delay(sequence1_wait);
    DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_CONTROL_LEFT + MOD_ALT_LEFT);
    DigiKeyboard.delay(sequence1_wait);
    DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, MOD_CONTROL_LEFT + MOD_ALT_LEFT);
    DigiKeyboard.delay(sequence1_wait);
    DigiKeyboard.sendKeyStroke(KEY_ARROW_UP, MOD_CONTROL_LEFT + MOD_ALT_LEFT);
  }

  else if (randomsequence == 2){ //starts notepad and types something into it
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    delay(1000);
    DigiKeyboard.println("notepad.exe");
    
    if (randominput == 0){
      DigiKeyboard.delay(1000);
      DigiKeyboard.println("Hellos world");
      DigiKeyboard.println("I know how to do some serious damage!!");
    }

    else if (randominput == 1){
      DigiKeyboard.delay(1000);
      DigiKeyboard.println("Hellos persons");
      DigiKeyboard.println("I've been watching you for a while....");
    }

    else if (randominput == 2){
      DigiKeyboard.delay(1000);
      DigiKeyboard.println("I've been infecting you...");
      DigiKeyboard.delay(5000);
      DigiKeyboard.println("Only Joking!");
    }
  }

  else if (randomsequence == 3){ //goes to random website
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(1000);

    if (randomweb == 0){
      DigiKeyboard.println("https://sortedfood.com");
    }

    else if (randomweb == 1){
      DigiKeyboard.println("https://kickstarter.com");
    }

    else if (randomweb == 2){
      DigiKeyboard.println("https://vlee.me.uk");
    }
  }

  else if (randomsequence == 4){ //Locks the computer
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
  }

  else if (randomsequence == 5){ //Minimizes all the windows
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_M, MOD_GUI_LEFT);
  }

  delay(randomstop);
}

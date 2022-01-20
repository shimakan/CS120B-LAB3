 // C++ code

/*        Your Name & E-mail: David Gonzalez, dgonz162@ucr.edu
*          Lab Section: 021
*         Assignment: Lab 3  Exercise 1
*         Exercise Description: Turns on a LED when the button is being pressed.
*         I acknowledge all content contained herein, excluding template or example code, is my own original work.
*         Demo Link: 
*/

#define B0 2
#define B1 3

enum SM_states { SM_SMStart, B0_ON, B1_ON_PRESS, B1_ON, B0_ON_PRESS} SM_state;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(B0, OUTPUT);
  pinMode(B1, OUTPUT);
}

void TickFct_SM()
{
  switch(SM_state){
    case SM_SMStart:
     SM_state = B0_ON;
    break;
      
    case B0_ON:
      SM_state = digitalRead(A0) ? B1_ON_PRESS : B0_ON;
    break;

    case B1_ON_PRESS:
      SM_state = digitalRead(A0) ? B1_ON_PRESS : B1_ON;
    break;

    case B1_ON:
      SM_state = digitalRead(A0) ? B0_ON_PRESS : B1_ON;
    break;
    
    case B0_ON_PRESS:
      SM_state = digitalRead(A0) ? B0_ON_PRESS : B0_ON;
    break;
        
    default:
      SM_state = SM_SMStart;
  }//transitions
  
  switch(SM_state){
    case B0_ON:
      digitalWrite(B0, HIGH);
      digitalWrite(B1, LOW);
    break;

    case B1_ON_PRESS:
      digitalWrite(B0,LOW);
      digitalWrite(B1,HIGH)
    break;

    case B1_ON:
      digitalWrite(B0,LOW);
      digitalWrite(B1,HIGH);
    break;
    
    case B0_ON_PRESS:
      digitalWrite(B0, HIGH);
      digitalWrite(B1, LOW);
    break;
    
    default:
    break;
  }//actions
}

void loop()
{
  TickFct_SM();
}

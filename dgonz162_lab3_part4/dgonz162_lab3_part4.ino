// C++ code

/*        Your Name & E-mail: David Gonzalez, dgonz162@ucr.edu
*          Lab Section: 021
*         Assignment: Lab 3  Exercise 4
*         Exercise Description: Lock system: password is "#Y". A0 is X, A1 is Y, A2 is #, and A4 is to lock.
*         I acknowledge all content contained herein, excluding template or example code, is my own original work.
*         Demo Link: 
*/
#define b2 2
String str = "";

unsigned char bp = 0; //button press

enum SM_states {Start, ON, LOCK, UNLOCK, X, Y, SHARP} SM_State;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A4,INPUT);
  pinMode(b2,OUTPUT);

  Serial.begin(9600);
}

void TickFct_SM(){
  switch(SM_State){
    case Start:
      SM_State = ON;
    break;

    case ON:
      if(bp == 2){
      if(str == "#Y"){
              SM_State = UNLOCK; 
            }
            bp = 0;
            str = "";
      }else if(digitalRead(A4) && !digitalRead(A2) && !digitalRead(A1) && !digitalRead(A0)){
          SM_State = LOCK;
        }else if(digitalRead(A0) && !digitalRead(A1) && !digitalRead(A2) && !digitalRead(A4)){
          SM_State = X;
        }else if(digitalRead(A1) && !digitalRead(A0) && !digitalRead(A2) && !digitalRead(A4)){
          SM_State = Y;
        }else if(digitalRead(A2) && !digitalRead(A0) && !digitalRead(A1) && !digitalRead(A4)){
          SM_State = SHARP;
        }else{
          SM_State = ON; 
        }
    break;

    default:
      SM_State = ON;
    break;
  }//transitions  
      
  delay(150);
  
  switch(SM_State){
    case ON:
    break;
    
    case UNLOCK:
      Serial.println("Unlocked");
      digitalWrite(b2,HIGH);
      //SM_State = ON;
    break;

    case LOCK:
      str = "";
        bp++;
      Serial.println("Locked");
      digitalWrite(b2,LOW);
    break;
    
    case X:
      str = str + 'X';
      Serial.print("current input:");
      Serial.println(str);
      bp++;
    break;
    
    case Y:
      str = str + 'Y';
      Serial.print("current input:");
      Serial.println(str);
        bp++;
    break;
    
    case SHARP:
      str = str + '#';
      Serial.print("current input:");
      Serial.println(str);
        bp++;
    break;
    
    default:
    //Serial.println("IN DEFAULT");
    break;
  }//actions

}

void loop()
{
  TickFct_SM();
}

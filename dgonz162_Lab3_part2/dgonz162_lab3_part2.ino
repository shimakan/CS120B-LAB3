// C++ code

/*        Your Name & E-mail: David Gonzalez, dgonz162@ucr.edu
*          Lab Section: 021
*         Assignment: Lab 3  Exercise 2
*         Exercise Description: cycles through five different light shows
*         I acknowledge all content contained herein, excluding template or example code, is my own original work.
*         Demo Link: 
*/

#define b0 2
#define b1 3
#define b2 4
#define b3 5
#define b4 6
#define b5 7
#define b6 8
#define b7 9

unsigned char cnt = 0;
unsigned char a = 0x80;
unsigned char b = 0x01;
unsigned char c = 0x00;
//for edge detection
unsigned char buttonState = 0;
int lastButtonState = 0;

enum SM_states {Start, lights} SM_state;
void setup()
{
  SM_state = Start;
  pinMode(A0,INPUT);
  pinMode(b0,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(b3,OUTPUT);
  pinMode(b4,OUTPUT);
  pinMode(b5,OUTPUT);
  pinMode(b6,OUTPUT);
  pinMode(b7,OUTPUT);
  Serial.begin(9600);
}

void resetB()
{
  digitalWrite(b7,LOW);
  digitalWrite(b6,LOW);
  digitalWrite(b5,LOW);
  digitalWrite(b4,LOW);
  digitalWrite(b3,LOW);
  digitalWrite(b2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b0,LOW);
}

void writeToB(unsigned char temp)
{
  if ((temp>>7) & 0x01){digitalWrite(b7,HIGH);}
  if ((temp>>6) & 0x01){digitalWrite(b6,HIGH);}
  if ((temp>>5) & 0x01){digitalWrite(b5,HIGH);}
  if ((temp>>4) & 0x01){digitalWrite(b4,HIGH);}
  if ((temp>>3) & 0x01){digitalWrite(b3,HIGH);}
  if ((temp>>2) & 0x01){digitalWrite(b2,HIGH);}
  if ((temp>>1) & 0x01){digitalWrite(b1,HIGH);}
  if (temp & 0x01){digitalWrite(b0,HIGH);}
}

void TickFct_SM(){
  buttonState = digitalRead(A0);
  if(buttonState != lastButtonState){

    if(buttonState == HIGH){
      if(cnt < 5){
        cnt++;
      }else{
        cnt = 1; 
      }
    
      switch(SM_state){
        case Start:
            SM_state = lights;
        break;

        case lights:
            if(digitalRead(A0) == LOW){
                SM_state = lights;
            }
        break;

        default:
            SM_state = Start;
        break;
      }//transitions
    
    }
    delay(50);
  }
  
  lastButtonState = buttonState;
  
  switch(SM_state){
    case Start:
    resetB();
    break;
    
    case lights:
    
        switch(cnt){
            case 1:
                resetB();
                digitalWrite(b0,HIGH);
                digitalWrite(b2,HIGH);
                digitalWrite(b4,HIGH);
                digitalWrite(b6,HIGH);
                delay(150);
              resetB();
                digitalWrite(b1,HIGH);
                digitalWrite(b3,HIGH);
                digitalWrite(b5,HIGH);
                digitalWrite(b7,HIGH);
              delay(150);
            break;

            case 2:
                resetB();
              for(int i = 0; i < 8; i++){
                resetB();
                  writeToB(b);
                  b = b << 1;
                  delay(150);
                }
              b = 0x01;
            break;

            case 3:
                resetB();
              b = 0x80;
              for(int i = 7; i >= 0; i--){
                resetB();
                  writeToB(b);
                  b = b >> 1;
                  delay(150);
                }
            break;

            case 4:
                resetB();
                b = 0x01;
              for(int i = 0; i < 8; i++){
                  writeToB(b);
                  b = b << 1;
                  delay(150);
                }
            break;

            case 5:
            resetB();
            a = 0x80;
            b = 0x01;
            c = 0x00;
            for(int i = 0; i < 8; i++){
              resetB();
                c = a | b;
                writeToB(c);
              if(i < 4){
                a = a >> 1;
                b = b << 1;
              }else{
                a = a << 1;
                b = b >> 1;
              }
              delay(150);
            }
            break;

            default:
            break;
        }

      break;

      default:
      break;
    }//actions

}

void loop()
{
  TickFct_SM();
}

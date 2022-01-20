// C++ code

/*        Your Name & E-mail: David Gonzalez, dgonz162@ucr.edu
*          Lab Section: 021
*         Assignment: Lab 3  Exercise 2
*         Exercise Description: lights display a visual representation of binary numbers 0-10.
                A0 increments until 10 and A1 decrements until 0.
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
unsigned char b = 0x07;

enum SM_states {Start, zero, one, two, three, four, five, six, seven, eight, nine, ten} SM_state;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
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
  switch(SM_state){
        case Start:
            SM_state = seven;
        break;

       case zero:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = zero;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = one;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = zero;
            }
       break;
    
       case one:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = one;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = two;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = zero;
            }
        break;
    
       case two:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = two;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = three;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = one;
            }
        break;
    
       case three:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = three;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = four;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = two;
            }
        break;
    
       case four:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = four;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = five;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = three;
            }
        break;
    
       case five:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = five;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = six;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = four;
            }
        break;
    
       case six:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = six;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = seven;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = five;
            }
        break;
    
        case seven:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = seven;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = eight;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = six;
            }
        break;
    
        case eight:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = eight;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = nine;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = seven;
            }
        break;
    
        case nine:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = nine;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = ten;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = eight;
            }
        break;
    
        case ten:
            if(digitalRead(A0) == LOW && digitalRead(A1) == LOW){
                SM_state = ten;
            }else if(digitalRead(A0) == HIGH && digitalRead(A1) == LOW){
              SM_state = ten;
            }else if(digitalRead(A0) == LOW && digitalRead(A1) == HIGH){
                SM_state = nine;
            }
        break;

        default:
            SM_state = seven;
        break;
      }//transitions  
      
  delay(150);
  switch(SM_state){
    case zero:
      resetB();
    break;
    
    case one:
      resetB();
      b = 0x01;
      writeToB(b);
    break;
    
    case two:
      resetB();
      b = 0x02;
      writeToB(b);
    break;
    
    case three:
      resetB();
      b = 0x03;
      writeToB(b);
    break;
    
    case four:
      resetB();
      b = 0x04;
      writeToB(b);
    break;
    
    case five:
      resetB();
      b = 0x05;
      writeToB(b);
    break;
    
    case six:
      resetB();
      b = 0x06;
      writeToB(b);
    break;
    
    case seven:
      resetB();
      b = 0x07;
      writeToB(b);
    break;
    
    case eight:
      resetB();
      b = 0x08;
      writeToB(b);
    break;
    
    case nine:
      resetB();
      b = 0x09;
      writeToB(b);
    break;
    
    case ten:
      resetB();
      b = 0x0a;
      writeToB(b);
    break;
    
    default:
    Serial.println("IN DEFAULT");
    break;
  }//actions

}

void loop()
{
  TickFct_SM();
}

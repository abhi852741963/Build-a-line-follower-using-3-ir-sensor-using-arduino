
  const int pin1mot1=4;
  const int pin2mot1=5;
  const int pin1mot2=6;
  const int pin2mot2=7;
  const int pwm1=9;
  const int pwm2=11;
  const int capfront=A1;
  const int capright=A2;
  const int capleft=A0;
  
 
void setup() {
  
  pinMode(pin1mot1,OUTPUT);
  pinMode(pin2mot1,OUTPUT);
  pinMode(pin1mot2,OUTPUT);
  pinMode(pin2mot2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(capfront,INPUT);
  pinMode(capright,INPUT);
  pinMode(capleft,INPUT);
}

void avancer_moteur_left()
{
  digitalWrite(pin2mot1,HIGH);
    digitalWrite(pin1mot1,LOW);
 }
 void avancer_moteur_right()
 {
  digitalWrite(pin2mot2,HIGH);
  digitalWrite(pin1mot2,LOW);
 }
 void reculer_moteur_left()
 {
  digitalWrite(pin2mot1,LOW);
    digitalWrite(pin1mot1,HIGH);
  }
  void reculer_moteur_right()
 {
  digitalWrite(pin2mot2,LOW);
  digitalWrite(pin1mot2,HIGH);
 }
 
 
  void turn_right_forward(int v)
  {
    analogWrite(pwm1,v);
    analogWrite(pwm2,0);
    avancer_moteur_left();
    digitalWrite(pin2mot2,LOW);
    digitalWrite(pin1mot2,LOW);
    
  }
void turn_right_backward (int v)
  {
    analogWrite(pwm1,v);
    analogWrite(pwm2,0);
    reculer_moteur_left();
     digitalWrite(pin2mot2,LOW);
    digitalWrite(pin1mot2,LOW);
  }
  void turn_left_forward(int v)
  {
     analogWrite(pwm2,v);
     analogWrite(pwm1,0);
     avancer_moteur_right();
    digitalWrite(pin2mot1,LOW);
    digitalWrite(pin1mot1,LOW);
  }
  void turn_left_backward(int v)
  {
    analogWrite(pwm2,v);
    analogWrite(pwm1,0);
    reculer_moteur_right();
    digitalWrite(pin2mot1,LOW);
    digitalWrite(pin1mot1,LOW);
  }
  void go_forward(int v1,int v2)
  {
     analogWrite(pwm1,v1);
    analogWrite(pwm2,v2);
    avancer_moteur_left();
    avancer_moteur_right();
  }
  void go_backward(int v1,int v2)
  {
     analogWrite(pwm1,v1);
    analogWrite(pwm2,v2);
    reculer_moteur_left();
    reculer_moteur_right();  
    
}
 void trun_around_right(int v1,int v2)
  {
     analogWrite(pwm1,v1);
    analogWrite(pwm2,v2);
    avancer_moteur_left(); 
   reculer_moteur_right();
   
    
}
 void trun_around_left(int v1,int v2)
  {
     analogWrite(pwm1,v1);
    analogWrite(pwm2,v2);
     avancer_moteur_right();
    reculer_moteur_left();
   
    
}
void arret()
{   analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    digitalWrite(pin2mot1,LOW);
    digitalWrite(pin1mot1,LOW);
    digitalWrite(pin2mot2,LOW);
    digitalWrite(pin1mot2,LOW);}
int v1=65;
int v2=57;
int v=60;
void loop() { 
      
if(!digitalRead(capfront) && !digitalRead(capright)&& !digitalRead(capleft))
     { go_forward(v1,v2);delay(8);}

/*if(!digitalRead(capfront) && !digitalRead(capright)&& digitalRead(capleft))
    
      { arret();delay(10);
        while(!digitalRead(capfront)){go_forward(v1,v2);delay(8);}
         turn_right_forward(110);delay(8);
       if( digitalRead(capfront))
          {while(digitalRead(capfront))
             {trun_around_right(v1,v2);delay(5);}}
             go_forward(v1,v2); 
        }*/
       

if(!digitalRead(capfront) && digitalRead(capright)&& !digitalRead(capleft))
       { arret();delay(10);
            while(!digitalRead(capfront)) { go_forward(v1,v2);delay(6);}
            turn_left_forward(100);delay(8);
      if( digitalRead(capfront))
        {while(digitalRead(capfront))
             {trun_around_left(v1,v2);delay(6);}
         }
             go_forward(v1,v2); 
       }
 
if((!digitalRead(capfront)) && (!digitalRead(capright)) && digitalRead(capleft))
          {turn_right_forward(v1);delay(2); }
          
if(!digitalRead(capfront) && digitalRead(capright)&& !digitalRead(capleft))
        {turn_left_forward(v2);delay(2); }

       
if(!digitalRead(capfront)&& digitalRead(capright)&& digitalRead(capleft))
      { arret();
       go_forward(v1,v2); delay(4);
       arret();delay(20); 
       }
        if(!digitalRead(capright)&& digitalRead(capleft))
          { while(digitalRead(capfront))
            {turn_left_forward(v2);delay(6);}
           }
        if(!digitalRead(capleft)&& digitalRead(capright))
       { while(digitalRead(capfront)){turn_right_forward(v1);delay(6);}
       }
       // }
   

if(digitalRead(capfront)&&  !digitalRead(capright)&& !digitalRead(capleft))
          {go_forward(v1,v2);delay(5);
         }
       
  
if( digitalRead(capfront) &&  !digitalRead(capright) && digitalRead(capleft)){   
          arret();delay(10);turn_right_forward(v1);delay(3);
          }
   
 
if( digitalRead(capfront) &&  digitalRead(capright) && !digitalRead(capleft)){ 
          arret();delay(10);turn_left_forward(v2);delay(3);
       }


}
       



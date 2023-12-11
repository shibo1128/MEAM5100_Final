#ifndef __IR__
#define __IR__

#define leftIR 4
#define rightIR 5

uint32_t us;
int oldstate = 0;
uint32_t oldtime = 0;

int senseBeacon(){
  us = micros();
  int temp = digitalRead(leftIR);
  // Serial.println(temp);
  if(temp != oldstate && temp){
    
    int t = us - oldtime;
    if (t >1780 && t<1840)
    {
      printf("time gap: %d",t);
      printf("  detected 550Hz trophy\n");
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      return 550;
    }
    else if (t >42000 && t<45000)
    {
      printf("time gap: %d",t);
      printf("  detected 23Hz fake\n");
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      return 23;
    }
    else{
        return 0;
    }
    
    oldtime = us;
  }
  else{return 0;}
  oldstate = temp;
}


#endif
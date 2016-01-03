//Cirstmas Mode LED lrumination dessin.
//Hitoshi.Momma  momma@nifty.com
//2015.11.24
//Set white ball still and clored ball to PWM mode
//Sync ball to be network activities.
//1/f fluctuation by interval Caos
int value = 0;   // variable to keep the actual value 
float x = 0.1;
float x1[]={0.10,0.10,0.10,0.10};
int   x2[]={11,10,6,5};

void setup() {
//Serial.begin(9600);//for debug
// turn the LED on (HIGH is the voltage level)
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
digitalWrite(13, HIGH);   
digitalWrite(12, HIGH); 
digitalWrite(8, HIGH);  
digitalWrite(7, HIGH);  
//PWM
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
}

// 1/f fluctuation by interval Caos
//
void loop() {
  for(int i=0;i<4;i++){
  x = x1[i];  
  if(x < 0.5){x = x + 2 * x * x;
  } 
  else {x = x - 2 * (1.0 - x) * (1.0 - x);
  }
  if(x < 0.08){
    x = (float)(random(20,80))/256;
  }
  if(x > 0.995){
    x = (float)(random(128,253))/256;
  }
  x1[i] = x;
  x = x * 255;
  value= (unsigned int)x;
  analogWrite(x2[i], 255-value);
  delay(13);
  }
}



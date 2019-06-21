/* Karolina Pyryt, Daniel Nowak 2019 */
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif

#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

int i=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);


pinMode(X_ENABLE_PIN,OUTPUT);
digitalWrite(X_ENABLE_PIN,LOW);
pinMode(Y_ENABLE_PIN,OUTPUT);
digitalWrite(Y_ENABLE_PIN,LOW);
pinMode(Z_ENABLE_PIN,OUTPUT);
digitalWrite(Z_ENABLE_PIN,LOW);

pinMode(X_DIR_PIN,OUTPUT);
digitalWrite(X_DIR_PIN,HIGH);
pinMode(Y_DIR_PIN,OUTPUT);
digitalWrite(Y_DIR_PIN,HIGH);
pinMode(Z_DIR_PIN,OUTPUT);
digitalWrite(Z_DIR_PIN,HIGH);

pinMode(X_STEP_PIN,OUTPUT);
pinMode(Y_STEP_PIN,OUTPUT);
pinMode(Z_STEP_PIN,OUTPUT);

pinMode(X_MAX_PIN,INPUT_PULLUP);
pinMode(Y_MAX_PIN,INPUT_PULLUP);
pinMode(Z_MAX_PIN,INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.print("a\n");



if(digitalRead(X_MAX_PIN)==0)
{
digitalWrite(X_STEP_PIN,HIGH);
}
if(digitalRead(Y_MAX_PIN)==0)

digitalWrite(Y_STEP_PIN,HIGH);
if(digitalRead(Z_MAX_PIN)==0)
digitalWrite(Z_STEP_PIN,HIGH);

delay(1);
digitalWrite(X_STEP_PIN,LOW);
digitalWrite(Y_STEP_PIN,LOW);
digitalWrite(Z_STEP_PIN,LOW);
delay(1);
i++;
if(i==1500)
  {
    digitalWrite(X_DIR_PIN,LOW);
    digitalWrite(Y_DIR_PIN,LOW);
    digitalWrite(Z_DIR_PIN,LOW);
    
  }
if(i==3000)
  {
  digitalWrite(X_DIR_PIN,HIGH);
  digitalWrite(Y_DIR_PIN,HIGH);
  digitalWrite(Z_DIR_PIN,HIGH);
  i=0;
  }

Serial.println(digitalRead(X_MAX_PIN));

Serial.println(digitalRead(Y_MAX_PIN));

Serial.println(digitalRead(Z_MAX_PIN));
  
}

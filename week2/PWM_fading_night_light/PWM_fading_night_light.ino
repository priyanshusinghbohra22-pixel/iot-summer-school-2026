/*
Author: Priyanshu Singh Bohra

PWM Fading Night Light

Mode 1 : Slow Breathing
Mode 2 : Fast Pulse
Mode 3 : SOS Pattern

LED    -> GPIO21
Button -> GPIO33
*/

const int LED = 21;
const int BTN = 33;

int mode = 1;

void setup() {

  pinMode(BTN, INPUT_PULLUP);

  Serial.begin(115200);

  ledcAttach(LED, 5000, 8);

  Serial.println("Mode 1 : Slow Breathing");

}

void slowBreathing() {

  for(int i=0;i<=255;i++){

    ledcWrite(LED,i);

    delay(6);

  }

  for(int i=255;i>=0;i--){

    ledcWrite(LED,i);

    delay(6);

  }

}

void fastPulse(){

  for(int i=0;i<=255;i++){

    ledcWrite(LED,i);

    delay(1);

  }

  for(int i=255;i>=0;i--){

    ledcWrite(LED,i);

    delay(1);

  }

}

void sos(){

  for(int i=0;i<3;i++){

    ledcWrite(LED,255);

    delay(200);

    ledcWrite(LED,0);

    delay(200);

  }

  for(int i=0;i<3;i++){

    ledcWrite(LED,255);

    delay(600);

    ledcWrite(LED,0);

    delay(200);

  }

  for(int i=0;i<3;i++){

    ledcWrite(LED,255);

    delay(200);

    ledcWrite(LED,0);

    delay(200);

  }

  delay(1000);

}

void loop() {

  if(digitalRead(BTN)==LOW){

    mode++;

    if(mode>3){

      mode=1;

    }

    if(mode==1){

      Serial.println("Mode 1 : Slow Breathing");

    }

    else if(mode==2){

      Serial.println("Mode 2 : Fast Pulse");

    }

    else{

      Serial.println("Mode 3 : SOS Pattern");

    }

    delay(300);

  }

  if(mode==1){

    slowBreathing();

  }

  else if(mode==2){

    fastPulse();

  }

  else{

    sos();

  }

}


const int port  = 0;
const int led   = 8;
int valor       = 0;

void setup() {
  
    Serial.begin(9600);
    pinMode(led, OUTPUT);
}

void loop() {

    Serial.println("run arduino...");


    //acender e apagar led
    if(Serial.available()){

        switch(Serial.read()){
          
            //ON Led
            case 'a':
              digitalWrite(led, HIGH);
              Serial.println("ON");
              break;

            //OFF Led
            case 'b':
              digitalWrite(led, LOW);
              Serial.println("OFF");              
              break;
        }
    }

    delay(2000);
}

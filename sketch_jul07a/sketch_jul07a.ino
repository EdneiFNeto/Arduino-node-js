

#include <IRremote.h>

IRsend irsend;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("run android");
}
//
//void dump(decode_results *results) {
//    // Dumps out the decode_results structure.
//    // Call this after IRrecv::decode()
//    int count = results->rawlen;
//    if (results->decode_type == UNKNOWN) {
//        Serial.print("Unknown encoding: ");
//    } else if (results->decode_type == NEC) {
//        Serial.print("Decoded NEC: ");
//
//    } else if (results->decode_type == SONY) {
//        Serial.print("Decoded SONY: ");
//    } else if (results->decode_type == RC5) {
//        Serial.print("Decoded RC5: ");
//    } else if (results->decode_type == RC6) {
//        Serial.print("Decoded RC6: ");
//    } else if (results->decode_type == PANASONIC) {
//        Serial.print("Decoded PANASONIC - Address: ");
//        Serial.print(results->address, HEX);
//        Serial.print(" Value: ");
//    } else if (results->decode_type == LG) {
//        Serial.print("Decoded LG: ");
//    } else if (results->decode_type == JVC) {
//        Serial.print("Decoded JVC: ");
//    } else if (results->decode_type == AIWA_RC_T501) {
//        Serial.print("Decoded AIWA RC T501: ");
//    } else if (results->decode_type == WHYNTER) {
//        Serial.print("Decoded Whynter: ");
//    } else if (results->decode_type == BOSEWAVE) {
//        Serial.print("Decoded Bose Wave Radio / CD: ");
//    }
//    Serial.print(results->value, HEX);
//    Serial.print(" (");
//    Serial.print(results->bits, DEC);
//    Serial.println(" bits)");
//    Serial.print("Raw (");
//    Serial.print(count, DEC);
//    Serial.print("): ");
//
//    for (int i = 1; i < count; i++) {
//        if (i & 1) {
//            Serial.print(results->rawbuf[i] * MICROS_PER_TICK, DEC);
//        } else {
//            Serial.write('-');
//            Serial.print((unsigned long) results->rawbuf[i] * MICROS_PER_TICK, DEC);
//        }
//        Serial.print(" ");
//    }
//    Serial.println();
//}

void loop() {
  Serial.println("run arduino...");
//  if (irrecv.decode(&results)) {
//        Serial.println(results.value, HEX);
//        dump(&results);
//        irrecv.resume(); // Receive the next value
//   }

   send();

   delay(2000);
}

void send(){

  if(Serial.available()){
    switch(Serial.read()){
      case 'a': 
        irsend.sendNEC(0x20FF6897, 32); 
        Serial.println("Button 1");
        break;//button 1
      case 'b': 
        irsend.sendNEC(0x20FF9867, 32); 
        Serial.println("Button 2");
        break;//button 2
      case 'c': 
        irsend.sendNEC(0x20FFB04F, 32);
        Serial.println("Button 3");
        break;//button 3
    }
  }

}

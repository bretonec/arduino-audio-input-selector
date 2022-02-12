#include <IRremote.h>
const int receiver = 5;
const int rel1_PIN = 6;
const int rel2_PIN = 7;

int buttonNew;
int buttonOld=1;
IRrecv irrecv(receiver); // create instance of 'irrecv'
 decode_results results;

void setup() {
  irrecv.blink13(true);
  irrecv.enableIRIn();
  Serial.begin(9600);
  Serial.print("start");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(rel1_PIN, OUTPUT);
  pinMode(rel2_PIN, OUTPUT);
  digitalWrite(rel1_PIN, LOW);
  digitalWrite(rel2_PIN, LOW);
}

 
void loop() {

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
      }
  if (results.value == 0x838) {
    relay_one();
    delay(500);
    }
  if (results.value == 0x38) {
    relay_one();
    delay(500);
    }
} 

void relay_one() {
  static int m = HIGH;
  m = !m;
  digitalWrite(rel1_PIN, m);
  digitalWrite(rel2_PIN, m);
  delay(500);
} 

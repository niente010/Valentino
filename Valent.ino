int relay = 8;
int switchPin = 2;  // Define the pin where the switch is connected

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(switchPin, INPUT_PULLUP);  // Set the switch pin as an input
}

void loop() {
  int switchState = digitalRead(switchPin);  // Read the state of the switch
  int speedValue = analogRead(A1);
  int speedSec = map (speedValue, 0, 650, 60, 200);
  
  Serial.println(speedSec);

  if (switchState == LOW) {  // Check if the switch is in the ON position
    //Serial.println("Clock ON!");
    digitalWrite(relay, LOW);  // Turn relay ON
    delay(speedSec);

    digitalWrite(relay, HIGH);  // Turn relay OFF
    delay(speedSec);
  } else {
    digitalWrite(relay, HIGH);  // Ensure relay is OFF when switch is not ON
    //Serial.println("Clock OFF!");
  }


}

unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

int touch;
int touchToggle = 0;
int powerToggle = 0;
int gateToggle = 0;

void setup() {
  pinMode(3, INPUT_PULLUP); //touch
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); //green1
  pinMode(7, OUTPUT); //green2
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

}

void loop() {

  unsigned long currentMillis = millis();

  touch = digitalRead(3); //read the value of the digital interface 3 assigned to val

  if (touch == LOW and touchToggle == 0) {
    touchToggle = 1;
    previousMillis3 = currentMillis + 10000;
    previousMillis = currentMillis + 70000;
    previousMillis1 = currentMillis + 72000;
    previousMillis2 = currentMillis + 98000;
    
  }

  if (touch == HIGH) {
    touchToggle = 0;
  }

  switch (touchToggle) {
    case 1:
      if (currentMillis >= previousMillis3 and gateToggle == 0 and touch == LOW) {
        digitalWrite(5, HIGH);
      }
      if (currentMillis >= previousMillis and powerToggle == 0 and touch == LOW) {
        digitalWrite(6, HIGH);
      }
      if (currentMillis >= previousMillis1 and powerToggle == 0 and touch == LOW) {
        digitalWrite(6, LOW);
        powerToggle = 1;
      }
      if (currentMillis >= previousMillis2 and gateToggle == 0 and touch == LOW) {
        digitalWrite(7, HIGH);
        digitalWrite(5, LOW);
        gateToggle = 1;
      }   
      break;

    case 0:
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      powerToggle = 0;
      gateToggle = 0;

      break;
  }
}

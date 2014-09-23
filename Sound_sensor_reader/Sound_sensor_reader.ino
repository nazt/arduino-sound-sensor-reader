int sensorPin = A1;
int sensorValue = 0;

unsigned int looper = 0;
unsigned int counter = 0;
unsigned long int accum = 0;
void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  looper++;
  sensorValue = analogRead(sensorPin);

  if (sensorValue > 20) {
    counter++;
    accum+=sensorValue;
  }

  if (looper == 600) {
    Serial.print(counter);
    Serial.print(":");
    Serial.println(accum);
    looper = 0;
    counter = 0;
    accum = 0;
  }
}

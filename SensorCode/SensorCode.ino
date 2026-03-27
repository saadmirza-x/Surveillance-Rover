int ledPin=12;
#define TRIG_FRONT 2
#define ECHO_FRONT 3
#define TRIG_RIGHT 4
#define ECHO_RIGHT 5          //sensoir vcode
#define TRIG_LEFT 6
#define ECHO_LEFT 7
#define TRIG_REAR 8
#define ECHO_REAR 9

void setup() {

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Serial.begin(9600);
  pinMode(TRIG_FRONT, OUTPUT); pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT); pinMode(ECHO_RIGHT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT); pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_REAR, OUTPUT); pinMode(ECHO_REAR, INPUT);
}

long readDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH, 30000);
  return duration * 0.034 / 2; // cm
}

void loop() {

    if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "TRIGGER") {
      digitalWrite(ledPin, HIGH);
      delay(500);  // LED on 0.5s
      digitalWrite(ledPin, LOW);
    }
  }

  long f = readDistance(TRIG_FRONT, ECHO_FRONT);
  long r = readDistance(TRIG_RIGHT, ECHO_RIGHT);
  long l = readDistance(TRIG_LEFT, ECHO_LEFT);
  long b = readDistance(TRIG_REAR, ECHO_REAR);

  Serial.print("F:"); Serial.print(f);
  Serial.print(",R:"); Serial.print(r);
  Serial.print(",L:"); Serial.print(l);
  Serial.print(",B:"); Serial.println(b);

  delay(100);
}

char command = 'S';
int speed = 0;

// Motor pins
// Front Right
#define FR_IN1 2
#define FR_IN2 3
#define FR_EN 5
// Front Left
#define FL_IN1 4
#define FL_IN2 7
#define FL_EN 6
// Rear Left
#define RL_IN1 8
#define RL_IN2 11
#define RL_EN 9
// Rear Right
#define RR_IN1 12
#define RR_IN2 13
#define RR_EN 10

void setup() {
  Serial.begin(9600);

  // Set all pins as OUTPUT`
  pinMode(FR_IN1, OUTPUT); pinMode(FR_IN2, OUTPUT); pinMode(FR_EN, OUTPUT);
  pinMode(FL_IN1, OUTPUT); pinMode(FL_IN2, OUTPUT); pinMode(FL_EN, OUTPUT);
  pinMode(RL_IN1, OUTPUT); pinMode(RL_IN2, OUTPUT); pinMode(RL_EN, OUTPUT);
  pinMode(RR_IN1, OUTPUT); pinMode(RR_IN2, OUTPUT); pinMode(RR_EN, OUTPUT);

  // Stop motors initially
  stopMotors();
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    int commaIndex = cmd.indexOf(',');
    if (commaIndex > 0) {
      command = cmd.substring(0, commaIndex).charAt(0);
      speed = cmd.substring(commaIndex + 1).toInt();
      if (speed < 0) speed = 0;
      if (speed > 100) speed = 100;
    }

    // Execute command
    switch (command) {
      case 'F': moveForward(speed); break;
      case 'B': moveBackward(speed); break;
      case 'L': turnLeft(speed); break;
      case 'R': turnRight(speed); break;
      case 'S': stopMotors(); break;
    }
  }
}

// ---- Motor functions with proper PWM scaling ----
void moveForward(int sp) {
  int pwm = map(sp, 0, 100, 0, 255);
  analogWrite(FR_EN, pwm); digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  analogWrite(FL_EN, pwm); digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  analogWrite(RL_EN, pwm); digitalWrite(RL_IN1, HIGH); digitalWrite(RL_IN2, LOW);
  analogWrite(RR_EN, pwm); digitalWrite(RR_IN1, HIGH); digitalWrite(RR_IN2, LOW);
}

void moveBackward(int sp) {
  int pwm = map(sp, 0, 100, 0, 255);
  analogWrite(FR_EN, pwm); digitalWrite(FR_IN1, LOW); digitalWrite(FR_IN2, HIGH);
  analogWrite(FL_EN, pwm); digitalWrite(FL_IN1, LOW); digitalWrite(FL_IN2, HIGH);
  analogWrite(RL_EN, pwm); digitalWrite(RL_IN1, LOW); digitalWrite(RL_IN2, HIGH);
  analogWrite(RR_EN, pwm); digitalWrite(RR_IN1, LOW); digitalWrite(RR_IN2, HIGH);
}

void turnLeft(int sp) {
  int pwm = map(sp, 0, 100, 0, 255);
  analogWrite(FR_EN, pwm); digitalWrite(FR_IN1, LOW); digitalWrite(FR_IN2, HIGH);
  analogWrite(FL_EN, pwm); digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  analogWrite(RL_EN, pwm); digitalWrite(RL_IN1, HIGH); digitalWrite(RL_IN2, LOW);
  analogWrite(RR_EN, pwm); digitalWrite(RR_IN1, LOW); digitalWrite(RR_IN2, HIGH);
}

void turnRight(int sp) {
  int pwm = map(sp, 0, 100, 0, 255);
  analogWrite(FR_EN, pwm); digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  analogWrite(FL_EN, pwm); digitalWrite(FL_IN1, LOW); digitalWrite(FL_IN2, HIGH);
  analogWrite(RL_EN, pwm); digitalWrite(RL_IN1, LOW); digitalWrite(RL_IN2, HIGH);
  analogWrite(RR_EN, pwm); digitalWrite(RR_IN1, HIGH); digitalWrite(RR_IN2, LOW);
}

void stopMotors() {
  analogWrite(FR_EN, 0); analogWrite(FL_EN, 0);
  analogWrite(RL_EN, 0); analogWrite(RR_EN, 0);
}

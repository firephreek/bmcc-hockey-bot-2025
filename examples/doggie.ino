#include <Servo.h>
#include<Pixy2.h>
#include<PID_v1.h>

// Initialize servo objects
Servo leftServo;
Servo rightServo;
Pixy2 pixy;

double Kp = 1.0, Ki = .1, Kd = .05;
double Setpoint = 160; //center of frame = target
double Input, Output; //for pid

PID pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT); //direct is how output responds to error

// Define servo pins
const int leftServoPin = 7;
const int rightServoPin = 8;

// Servo positions
// const int servoStop = 0;      // Neutral position to stop servos
// const int servoForward = 1700;  // Forward position (adjust as needed)

void setup() {
  Serial.begin(9600);

  pixy.init();

  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(0, 200);

  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);

  // Stop the servos
  leftServo.write(1500);
  rightServo.write(1500);

  pinMode(5, OUTPUT);
}

int blockType = 0;
int goMode = 0;

void loop() {
  if (Serial.available()) {                 // Check if data is available from HC-05
    String received = Serial.readString();  // Read the incoming data
    blockType = received.toInt();
    Serial.print("Received: ");
    Serial.println(blockType);  // Print the received data to Serial Monitor
    goMode = 1;
  }


  if (goMode == 1){
    pixy.ccc.getBlocks();
    if (pixy.ccc.numBlocks > 0) { // Ensure there's at least one block
      if ((pixy.ccc.blocks[0].m_width < 200) && (pixy.ccc.blocks[0].m_signature == blockType)) { // Check if the block isn't too close
        Input = pixy.ccc.blocks[0].m_x; //gets x coords of block
        pid.Compute();
        setMotorSpeeds(Output);
        delay(10);
      }
    }
    else{
      stopRobot();
      delay(10);
    }
  }


}

void setMotorSpeeds(double output){
  int leftServoSpeed = constrain(1700 - output, 1500, 1700);
  int rightServoSpeed = constrain(1500 - output, 1300, 1500);


  // Serial.print(leftServoSpeed);
  // Serial.print(" | ");
  // Serial.println(rightServoSpeed);

  leftServo.write(leftServoSpeed);
  rightServo.write(rightServoSpeed);
}


void stopRobot() {
  leftServo.write(1500);
  rightServo.write(1500);
}
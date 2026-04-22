int JoyStick_X = A0; //x-axis
int JoyStick_Y = A1; //y-axis

const int selectPin = 5;
const int deletePin = 3;
const int ledPin = 4;

int selectLastState = HIGH;
int deleteLastState = HIGH;
 
 
void setup() {
  // put your setup code here, to run once:
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
 
  Serial.begin(9600);

  pinMode(selectPin, INPUT_PULLUP);
  pinMode(deletePin, INPUT_PULLUP);
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  Serial.println("r");
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int X_Value = analogRead(A0);
  // left = 0, middle = 512, right = 1023
  int Y_Value = analogRead(A1);
  int selectState = digitalRead(selectPin);
  int deleteState = digitalRead(deletePin);
  // down = 0, middle = 512, up = 1023
  if (X_Value < 400) {
    Serial.println("MOVE_RIGHT");
  }
  if (X_Value > 600) {
    Serial.println("MOVE_LEFT");
  }
  if (Y_Value > 600) {
    Serial.println("MOVE_UP");
  }
  if (Y_Value < 400) {
    Serial.println("MOVE_DOWN");
  }

  if (selectState == LOW && selectLastState == HIGH) {
    Serial.println("SELECT_PRESSED");
    delay(50); 
  }
  selectLastState = selectState;

  if (deleteState == LOW && deleteLastState == HIGH) {
    Serial.println("DELETE_PRESSED");
    delay(50);
  }
  deleteLastState = deleteState;
 
  delay(100);
 
}
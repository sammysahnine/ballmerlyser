//sensor
const int AOUTpin = A0;//the analogue pin of the alcohol sensor goes into analog  pin A0 of the arduino

//leds
const int yellow = D5;
const int green = D6;
const int red = D7;
const int white = D1;

const int wait = 10000;
int value;


void  setup() {
  //sensor
  Serial.begin(9600);//sets the baud rate
  pinMode(AOUTpin, INPUT);
  
  //leds
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
}

void loop()
{

  value = analogRead(AOUTpin);//reads  the analaog value from the alcohol sensor's AOUT pin
  Serial.print("Alcohol value:  ");
  Serial.println(value);

  if (value < 400){
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  } else if (value > 550){
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  } else {
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }

}
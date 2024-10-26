//the code is entirely created by: SHEEKAR BANERJEE (at December 2017) 
//Dept. of CSE, IUBAT 
//AI-ML-IOT Solution Engineer and Researcher 
const int AOUTpin= A0; 
const int DOUTpin= D3; 

const int out0 = D0;
const int out1 = D2;

int limit; 
int value; 

void setup() { 
	   Serial.begin(9600);//sets the baud rate 
	   pinMode(DOUTpin, INPUT); 
     pinMode(out0, OUTPUT);
     pinMode(out1, OUTPUT);
} 

void loop() 
{ 
  value = analogRead(AOUTpin); 

  Serial.print("Alcohol value: "); 
  Serial.println(value); 

  if (value < 400) {
    Serial.println("1000 DRACULAS? MORE LIKE 1000 BEERS. GET DRINKING!");
    digitalWrite(out0, LOW);
    digitalWrite(out1, LOW);
  } else if (value > 600) {
    Serial.println("*CAR CRASH SFX* DON'T GET NEAR A VEHICLE - YOU'VE HAD TOO MUCH!");
    digitalWrite(out0, HIGH);
    digitalWrite(out1, HIGH);
  } else {
    Serial.println("BALLMER PEAK ACHIEVED !! OPEN VSCODE NOW");
    digitalWrite(out0, HIGH);
    digitalWrite(out1, LOW);
  }

  delay(1000); 
}
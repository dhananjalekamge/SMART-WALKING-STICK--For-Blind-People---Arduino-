

int trigPin = 9;
int echoPin = 10;
int motor=7;


void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  // put your setup code here, to run once:
  pinMode(motor,OUTPUT);

}

void loop() {

  int mois=analogRead(A0);
  Serial.print("the moisture is ");
  Serial.println(mois);
  delay(100);

  
  
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  
  
 if((distance<80) || (mois<600))
  {
    digitalWrite(motor, HIGH);
}
   else if(distance>=80 || (mois>600)) 
   {
     digitalWrite(motor, LOW);
   } 
 
 
}


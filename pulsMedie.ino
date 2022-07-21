
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);  // baud
}

void loop() {
  static     int ravValue = 0;
  static     int oldValue = 0;
  static unsigned long  oldTime = 0;
 static unsigned long n = 0 ;
 static  double medie = 0;
  unsigned long  t;
 ravValue = analogRead (A0);
 t= millis();
 if(ravValue)
  medie=(n*medie+ravValue)/++n;
  double pulse=0;
 if(ravValue<medie && oldValue>=medie){
    pulse = (t-oldTime)==0 ? 0: 60000/(t-oldTime);//beats per minute

    oldTime = t ;
 }
  Serial.print (t);
  Serial.print (", ");
  Serial.print (ravValue);
  Serial.print (", ");
  Serial.println (pulse);
  
  oldValue = ravValue ;
  delay (50);
}


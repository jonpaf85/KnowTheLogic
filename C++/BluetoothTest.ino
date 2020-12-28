char blueValue = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  digitalWrite(13,HIGH);
  delay(5000);
  digitalWrite(13,LOW);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    blueValue = Serial.read();
    Serial.println (blueValue);
    if (blueValue == '1'){
      digitalWrite(13,HIGH);}
    else if (blueValue == '0'){
      digitalWrite(13,LOW);}
    else {}        
    }
}  

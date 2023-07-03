/*
	Tinkercad
	https://www.tinkercad.com/things/bHize6dhmeP?sharecode=RFAhDR5s5c-FGv8iam1U-pq7xnRovr-DimkXeZ64mLE
*/

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
}

void loop()
{
  
  
  int anVal = analogRead(A0);
  if(anVal < 10)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if(anVal > 0 && anVal < 255)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if(anVal > 255 && anVal < 512)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if(anVal > 512 && anVal < 800)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else 
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

}
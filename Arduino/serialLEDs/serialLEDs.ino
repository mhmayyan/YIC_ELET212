/*
	Tinkercad
	https://www.tinkercad.com/things/3ODXixQoARR?sharecode=5WSiAhQgv_qWiVeDqb6c876DUIp2MzrehZFa7e5R3Ao
*/

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    char recChar = Serial.read();
    if(isAlphaNumeric(recChar))
    {
      if(isDigit(recChar))
      {
        hex2LEDs(recChar-'0');
      } else
      {
        switch(recChar)
        {
          case 'a':
          case 'A':
          {
            hex2LEDs(10);
            break;
          }
          case 'b':
          case 'B':
          {
            hex2LEDs(11);
            break;
          }
          case 'c':
          case 'C':
          {
            hex2LEDs(12);
            break;
          }
          case 'd':
          case 'D':
          {
            hex2LEDs(13);
            break;
          }
          case 'e':
          case 'E':
          {
            hex2LEDs(14);
            break;
          }
          case 'f':
          case 'F':
          {
            hex2LEDs(15);
            break;
          }
          default:
          	Serial.print("You entered ");
    		Serial.print(recChar);
    		Serial.println(" but only hexa numbers are acceptable!");
        }
      }
    }
  }
}

void hex2LEDs(uint8_t myChar)
{
  digitalWrite(2, myChar&0x01);
  digitalWrite(3, (myChar&0x02)>>1);
  digitalWrite(4, (myChar&0x04)>>2);
  digitalWrite(5, (myChar&0x08)>>3);
  delay(1000);
  // clean the RX buffer
  while(Serial.available()) Serial.read();
}
/*
Tutorial
https://www.instructables.com/How-to-use-the-TMP36-temp-sensor-Arduino-Tutorial/

Datasheet
https://cdn-learn.adafruit.com/assets/assets/000/010/131/original/TMP35_36_37.pdf

Tinkercad
https://www.tinkercad.com/things/8KZaxiPgAvW?sharecode=bPr3kMheUwSwkv9oEiKX0iHkARAwPzZi4m_wNfHCN2g

*/

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  float voltage, degreesC, degreesF;
  
  voltage = analogRead(A0) *0.0048875f; // 5.0f/1023.0f = 0.0048875
  
  // Now we'll convert the voltage to degrees Celsius.
  // This formula comes from the temperature sensor datasheet:

  degreesC = (voltage - 0.5f) * 100.0f;
  
  // While we're at it, let's convert degrees Celsius to Fahrenheit.
  // This is the classic C to F conversion formula:
  // 250 mV @ 25°C 
  
  degreesF = degreesC * (9.0/5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage,3);
  Serial.print("  deg C: ");
  Serial.print(degreesC,3);
  Serial.print("  deg F: ");
  Serial.println(degreesF,3);

  delay(1000); // repeat once per second (change as you wish!)
}


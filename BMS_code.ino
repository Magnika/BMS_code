float input_voltage = 0.0;
float temp=0.0;
float r1=91300.0;
float r2=33100.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
  pinMode(2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog_value = analogRead(A0);
  float temp = (analog_value * 5.0) / 1024.0;   
  float input_voltage = temp / (r2/(r1+r2));
  Serial.println(input_voltage);
  Serial.println(analog_value);

  if (input_voltage > 11.7)
    {
      digitalWrite(2, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
      digitalWrite(2, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(1000);
}

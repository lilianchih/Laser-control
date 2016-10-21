int modulation = DAC; //input to current controller
int trigger = D2; //for RF driver
int control = A2; //output from current controller
int steptime = 10000;
float levelToCurrent_a = 0.0425;
float levelToCurrent_b = -1.0213;
float frequencyToLevel = 12.28/253.0;
int offset = 160;

const int n = 3;
int freq[n] = {200, 500, 800}; //frequencies written to RF driver
int i = 0;
void setup()
{
pinMode(modulation, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(control, INPUT);
digitalWrite(trigger, HIGH);
analogWrite(modulation, offset);
}

void loop()
{
digitalWrite(trigger, LOW);
float current = analogRead(control)*levelToCurrent_a + levelToCurrent_b;
String current_string = String(current, 4);
Particle.publish(current_string);
int level = freq[i%n]*frequencyToLevel + offset;
analogWrite(modulation, level);
delay(1000);
digitalWrite(trigger, HIGH);
delay(steptime-1000);
i++;
}
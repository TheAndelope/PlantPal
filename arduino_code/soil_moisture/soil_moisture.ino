/****************** code made by PARTH SANTOSH KUNNIR************/
/****************** code is subjected to copy right**************/

int moistPin = A0;
int moistVal = 0;

void setup()
{
  Serial.begin(115200);
}
void loop()
{
  moistVal = analogRead(moistPin);

  int percent = 2.718282 * 2.718282 * (.008985 * moistVal + 0.207762); //calculate percent for probes about 1 - 1.5 inches apart
  Serial.println(percent);

  delay(250); // for stability 
}

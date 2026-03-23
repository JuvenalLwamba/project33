// Project #33: Addressing Areas on the Touchscreen

int x,y = 0;
int LED1 = 9;   // LED connected to pin 9
int LED2 = 6;  // LED connected to pin 6
int LED3 = 7; //  LED connected to pin 7
int LED4 = 8; // LED connected to pin 8


int readX()   // returns the value of the touchscreen's x-axis
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);

  digitalWrite(A1, LOW);   // set A1 to GND
  digitalWrite(A3, HIGH);  // set A3 as 5V

  delay(5);
  xr = analogRead(A0);     // stores the value of the x-axis
  return xr;
}

int readY()   // returns the value of the touchscreen's y-axis
{
  int yr=0;

  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);

  digitalWrite(A0, LOW);   // set A0 to GND
  digitalWrite(A2, HIGH);  // set A2 as 5V

  delay(5);
  yr = analogRead(A1);     // stores the value of the y-axis
  return yr;
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);   // LED output
  pinMode(LED2, OUTPUT);  // LED output
  pinMode(LED3, OUTPUT); // LED output
  pinMode(LED4, OUTPUT); // LED output
}

void loop()
{
  x = readX();
  y = readY();

  Serial.print("x=");
  Serial.print(x);
  Serial.print(" y=");
  Serial.println(y);

  // Turn off all LEDs first
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  // Divide screen into 4 zones
   if (x > 1000 && y > 1000)
   {}
  else if (x < 500 && y < 500)
 
  {
    digitalWrite(LED1, HIGH); // Top Left
  }

  else if (x >= 500 && y < 500)
  {
    digitalWrite(LED2, HIGH); // Top Right
  }

  else if (x < 500 && y >= 500)
  {
    digitalWrite(LED3, HIGH); // Bottom Left
  }

  else if (x >= 500 && y >= 500)
  {
    digitalWrite(LED4, HIGH); // Bottom Right
  }

  delay(150);
}

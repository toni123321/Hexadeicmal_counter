#define led_0 0
#define led_1 1
#define led_2 2
#define led_3 3
#define button 4

int current_num[]  = {0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(button, INPUT);

  //start with first two diodes on
  digitalWrite(led_0, HIGH);
  digitalWrite(led_1, HIGH);
  delay(10*1000);
  digitalWrite(led_0, LOW);
  digitalWrite(led_1, LOW);

}
void light_diodes()
{
  for(int i=0;i<=3;i++)
  {
    digitalWrite(i, HIGH);
  }
}
void blinking_diodes()
{
  for(int i=0;i<3;i++)
  {
    light_diodes();
    delay(1000);
    off_diodes();
    delay(1000);
  }
}
void off_diodes()
{
  for(int i=0;i<=3;i++)
  {
       digitalWrite(i, LOW);
  }
}

void hexadecimal_decoder(int num)
{  
  for(int i=3;i>=0;i--)
  {
    //digitalWrite(1, HIGH);
    if(num >= 0 && num < 16)
    {
      int remainder = num % 2;
      num/=2;
      current_num[i] = remainder;  
    }
  } 
}

int current_count = 0;
void loop() {  
  // put your main code here, to run repeatedly:
  if (digitalRead(4) == LOW)
  {
    delay(2000);
    hexadecimal_decoder(current_count); 
    for(int i=0;i<4;i++)
    {
      //digitalWrite(2, HIGH);
      digitalWrite(i, current_num[i]); 
    }    
    current_count++;
    delay(1000);
  }
  if(current_count == 16) {
    delay(2000);
    off_diodes();  
    current_count = 0;
    for(int i=0;i<4;i++)
    {
      current_num[i] = 0;
    }
    delay(1000);
    blinking_diodes();
  }
}

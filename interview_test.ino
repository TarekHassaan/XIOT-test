
int LED=3; // define pin 3 on Arduino as " LED "
int SW=5; // define pin 5 on Arduino as " SW "
int TEMP_PIN=A0; //define pin A0 on Arduino as "TEMP_PIN"
int temp; // value of the analog read
int tempC; // value of C degree
int flag=0;
int Time=0; //the difference between the currenty time and previous time
long int CurrentlyTime=0,PrevTime=0;//2 variables for the time before and after printing the temp on serial monitor
void setup() 
{
pinMode(LED,OUTPUT); // setting pin 3 as output
pinMode(SW,INPUT); // setting pin 5 as input
pinMode(TEMP_PIN,INPUT); // setting pin A0 as analog input
Serial.begin(9600); // adjust the speed of communication between PC and Arduino
}

void loop() {
 SW=digitalRead(5); // reading from the input pin
 if (SW==1 && flag == 0) //assuming pull up resistor is using
 {
digitalWrite(LED,LOW); // LED is OFF
Serial.println(" unpressed ");
Serial.println("LED is OFF");
flag=1;
delay(500); //delay 500ms
 }
  if (SW==0 && flag == 1) //assuming pull up resistor is using
 {
 digitalWrite(LED,HIGH); //LED is ON
Serial.println (" pressed ");
Serial.println("LED is ON");
flag=0;
delay(500); //delay 500ms
 }
 CurrentlyTime=millis();
 Time=CurrentlyTime-PrevTime;
 if (Time>=3000){ //checking Temp every 3 Sec
Temp();
Time=0;
PrevTime=CurrentlyTime;
}}
void Temp(){
temp = analogRead(TEMP_PIN);//reading the signal from the sensor on pin A0
tempC = temp *((5000/10)/1024);// 5000mV divided by 10 ( 10mV for each C degree ) then the total divided by 1024 (it's the digital value which can the Arduino read on analog pins )
Serial.print("TEMPRATURE = ");
Serial.print(tempC);
Serial.print(TEMP_PIN);
Serial.println("*C");
}

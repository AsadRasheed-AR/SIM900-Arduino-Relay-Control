#include <SoftwareSerial.h>

// Configure software serial port
SoftwareSerial SIM900(7, 8);

// Variable to store text message
String textMessage;

// Create a variable to store Lamp state
String lampState = "HIGH";

// Relay connected to pin 12
const int relay = 2;

void setup() {
  
  // Set relay as OUTPUT
  pinMode(relay, OUTPUT);

  // By default the relay is off
  digitalWrite(relay, HIGH);
  
  // Initializing serial commmunication
  Serial.begin(9600); 
  SIM900.begin(9600);

  // Give time to your GSM shield log on to network
  delay(20000);
  Serial.print("SIM900 ready...");

  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop(){
  if(SIM900.available()>0){
    textMessage = SIM900.readString();
    Serial.print(textMessage); 
    if (textMessage.indexOf("RING") != -1) {
      switchRelay();
      SIM900.println("ATH");
    }   
    delay(10);
  } 
  
  if(textMessage.indexOf("ON")>=0){
    //Switch Relay State
    switchRelay();
  }

  if(textMessage.indexOf("STATE")>=0){
    String message = "Gate is " + lampState;
    sendSMS(message);
    Serial.println("Gate state resquest");
    textMessage = "";
  }
}  

// Function that sends SMS
void sendSMS(String message){
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT+CMGS=\"+ZZxxxxxxxxxxx\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  delay(100);
  // Send the SMS
  SIM900.print(message); //text content 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.write(26); 
  // Give module time to send SMS
  delay(5000);  
}

//Function to Switch Relay
void switchRelay(){
// Turn on relay and save current state
    digitalWrite(relay, LOW);
    lampState = "open"; 
    textMessage = "";   
    delay(1000);
    digitalWrite(relay, HIGH);
    lampState = "close"; 
    textMessage = ""; 
    }

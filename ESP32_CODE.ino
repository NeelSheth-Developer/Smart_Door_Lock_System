#include <LiquidCrystal.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <EMailSender.h>
#include <WiFi.h>

const char* ssid = "wifi name";
const char* pass = "wifi password";

EMailSender emailSend("sender mail id", "App password");


// Door Lock variables
String password = "";   // the user defined password
String input = "";      // the user's input
bool unlocked = false;  // whether the door is unlocked or not
byte count = 0;         // represents no of elements entered for displaying each as '*' on LCD
byte false_counter = 0; // represents no of false attempts to alert by buzzer

// Define the address in EEPROM to store the password
int address = 0;

// Define the pins for the LCD and keypad
const byte ROWS = 4, COLS = 4; // 4*4 keypad
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {13, 12, 14, 27}; // Digital pins 
byte colPins[COLS] = {26, 25, 33, 32}; // Digital pins 

// Initialize the LCD and keypad
LiquidCrystal lcd(15, 2, 4, 16, 17, 5); 
Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(115200);
  lcd.begin(16, 2);         // Set up the LCD
  keypad.setDebounceTime(50); // Set up the keypad
}

void loop()
{
  doorLock();
}

void sendmail()
{
  WiFi.begin(ssid, pass);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  EMailSender::EMailMessage message;
  message.subject = "Security Alert! ";
  message.message = "Someone has just tried to unlock the door you can access the camera from the give link\n (“ local ip of wifi which we got from cam module”)";

  EMailSender::Response resp = emailSend.send("receiver mail id", message);
}

void doorLock()
{
  char key = keypad.getKey();
  // If a key is pressed, then only add it to the input
  if (key)
  {
    if (password == "")
    {
      lcd.setCursor(0, 0);
      lcd.print("Enter new passW: ");
    }
    input += key;            // accumulate keys to input
    lcd.setCursor(count, 1); // move cursor to show each new char as secret ‘*’
    lcd.print("*");
    count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
    if (key == '#')
    { // to clear input
      input = "";
      count = 0;
      if (password == "")
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter new passW: ");
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter password: ");
      }
      lcd.setCursor(0, 1);
      //key = keypad.getKey();
    }
  }
  // Check if the input is complete
  if (input.length() == 4)
  { // change this 4 to different values
    count = 0;
    // If the password has not been set yet, store the input as the new password
    if(input == "****")
    {
      input="";
      password="";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter new passW: ");
      lcd.setCursor(0,1);
    }
else if (password == "")
    {
      password = input;
      storePassword(password); // in EEPROM
      lcd.clear();
      lcd.print("Password set");
      delay(1000);
      lcd.clear();
      lcd.print("Enter password:");
      input = "";
    }
    // Otherwise, directly check if the input matches the password
    else
    {
      // If the input matches, unlock the door
      if (input == password)
      {
        unlocked = true;
        false_counter = 0;
        lcd.clear();
        lcd.print("Door unlocked");
        delay(2000);
        lcd.clear();
        lcd.print("Enter password:");
        input = ""; // make input null string again to retake input
      }
      // Otherwise, display an error message and reset the input
      else
      {
        false_counter++;
        lcd.clear();
        lcd.print("Incorrect");
        delay(1000);
        if (false_counter == 3)
        {
          lcd.clear();
          lcd.print("3 penalties");
          lcd.setCursor(0, 1);
          lcd.print("Beware");
          delay(5000);
          false_counter = 0; // reset false attempts
          sendmail();
        }
        lcd.clear();
        lcd.print("Enter password:");
        input = ""; // make input null string again to retake input
      }
      count = 0;
    }
  }
  // If the door is unlocked, display a message
  if (unlocked)
  {
    lcd.clear();
    lcd.print("Welcome!");
    delay(2000);
    lcd.clear();
    lcd.print("Enter password:");
    unlocked = false;
  }
}

// Function to store the password in EEPROM
void storePassword(String password)
{
  for (int i = 0; i < 4; i++)
  { // password length is 4
    EEPROM.write(address + i, password[i]);
  }
}


#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); //(RX,TX)
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); 
MFRC522::MIFARE_Key key; 
 byte nuidPICC[4];

void setup() {
   mySerial.begin(9600);
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

 delay(100); 
  }

void loop() {
 
   if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
if (rfid.uid.uidByte[0] != nuidPICC[0])
{
       // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.println(F("The UID tag is:"));
    Serial.print(F("In dec: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    
  }
     
if (rfid.uid.uidByte[0]=21); //Predefined tag ID onlychecking first string

{
  int a=100,b;
 
  
  if (Serial.available())
  {
    int x,c,y;
     x=Serial.parseInt();
    switch (x)
    {
      case 1:
      Serial.println("Boarding point A");
      Serial.println("Enter destination:");
      Serial.println("1\n2\n3\n4");
      c=Serial.parseInt();
      if(c==1){
        y=10;
      } else if(c==2){
        y=20;
      }
      else if(c==3){
        y=30;
      }
      else if(c==4){
        y=40;
      }
     break;
       case 2:
      Serial.println("Boarding point B");
      Serial.println("Enter destination:");
      Serial.println("1\n2\n3\n4");
      c=Serial.parseInt();
      if(c==1){
        y=10;
      } else if(c==2){
        y=20;
      }
      else if(c==3){
        y=30;
      }
      else if(c==4){
        y=40;
      }
     break;
     case 3:
      Serial.println("Boarding point C");
      Serial.println("Enter destination:");
      Serial.println("1\n2\n3\n4");
      c=Serial.parseInt();
      if(c==1){
        y=10;
      } else if(c==2){
        y=20;
      }
      else if(c==3){
        y=30;
      }
      else if(c==4){
        y=40;
      }
     break;
     case 4:
      Serial.println("Boarding point D");
      Serial.println("Enter destination:");
      Serial.println("1\n2\n3\n4");
      c=Serial.parseInt();
      if(c==1){
        y=10;
      } else if(c==2){
        y=20;
      }
      else if(c==3){
        y=30;
      }
      else if(c==4){
        y=40;
      }
     break;
      
    }b=a-y;
    Serial.println("COST: ");
    Serial.println(y);
    mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+919677891676\"\r"); 
  delay(1000);
  mySerial.println("COST: ");
  mySerial.println(y);
  delay(100);
  mySerial.println("BALANCE:");
  mySerial.println(b);
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }
    rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  }
} 

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) 
  {
     Serial.print(buffer[i], DEC);
  }
}

#include <EEPROM.h>
#include <HardwareSerial.h>
unsigned long startTime;
unsigned long endTime;
HardwareSerial SerialPort(2);
void setup() {
  Serial.begin(9600);
  SerialPort.begin (9600, SERIAL_8N1,16, 17);
}

void loop() {
while(1){
  String text = "Finance Minister Arun Jaitley Tuesday hit out at former RBI governor Raghuram Rajan for predicting that the next banking crisis would be triggered by MSME lending, saying postmortem is easier than taking action when it was required. Rajan, who had as the chief economist at IMF warned of impending financial crisis of 2008, in a note to a parliamentary committee warned against ambitious credit targets and loan waivers, saying that they could be the sources of next banking crisis. Government should focus on sources of the next crisis, not just the last one.* In particular, government should refrain from setting ambitious credit targets or waiving loans. Credit targets are sometimes achieved by abandoning appropriate due diligence, creating the environment for future NPAs,\" Rajan said in the note.\" Both MUDRA loans as well as the Kisan Credit Card, while popular, have to be examined more closely for potential credit risk. Rajan, who was RBI governor for three years till September 2016, is currently.";


   SerialPort.print(text);
  if (SerialPort.available()) {
    for (int i = 0; i < 1000; i++) {
      char incomingChar = SerialPort.read();
      EEPROM.write(i, incomingChar);
    }
    
    Serial.println("Data saved to EEPROM.");
    Serial.println("Reading from EEPROM:");
    for (int i = 0; i < 1000; i++) {
      char dataChar = EEPROM.read(i);
      Serial.print(dataChar);
    }

    startTime = millis();
    Serial.println("Sending data back to PC:");
    for (int i = 0; i < 1000; i++) {
      char dataChar = EEPROM.read(i);
      SerialPort.print(dataChar);
    }
    endTime = millis();

    unsigned long transmissionTime = endTime - startTime;
    Serial.print("Transmission time: ");
    Serial.print(transmissionTime);
    Serial.println(" milliseconds");
    
  }
  }
}

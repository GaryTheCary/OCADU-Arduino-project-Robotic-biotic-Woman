
   //get the ping sensor control code from arduino.cc
   //using SdFat.h && SFEMP3Shield.h to play music
    #include <SPI.h>
    #include <SdFat.h>
    #include <SdFatUtil.h>
    #include <SFEMP3Shield.h>

     SFEMP3Shield MP3player;
     SdFat sd;
     
     int pingPin = 4;
     int distance[10]; 
     int myDis = 0;
     int maxNum = 0;
     boolean active = false;


    void setup() {
      Serial.begin(9600);
      sd.begin(SD_SEL, SPI_HALF_SPEED);
      MP3player.setVolume(0x0000, 0x0000);
      MP3player.begin();
    
     
    }

    void loop() {
  
        int duration, cm;
        pinMode(pingPin, OUTPUT);
        digitalWrite(pingPin, LOW);
        delayMicroseconds(2);
        digitalWrite(pingPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(pingPin, LOW);
        
        pinMode(pingPin, INPUT);
        duration = pulseIn(pingPin, HIGH);
  
        cm = microsecondsToCentimeters(duration);
        
        //denoise
        for(int i = 0;i<10;i++)
        {
          distance[i] = cm;
          delay(10);
        }
        
        for(int j=0; j<9;j++)
        {
          for(int i = 0; i<10-j;j++)
          {
            if(distance[i]>=distance[i+1])
            {
              maxNum = distance[i];
              distance[i] = distance[i+1];
              distance[i+1] = maxNum;
            }
          }
        }
        
        
       
        
      
        myDis = (distance[4]+distance[5])/2;
  

        Serial.print(myDis);
        Serial.print("distance");
        Serial.println();

        if(myDis<50)
        {
          MP3player.playTrack(3); 
          analogWrite(3, 255);
          analogWrite(5, 255);
        }
        
        else
        {
          MP3player.playTrack(4);
          analogWrite(3, 0);
          analogWrite(5, 0);
        }
       
        delay(100);  
      }
    
    int microsecondsToInches(int microseconds)
   {
 
      return microseconds / 74 / 2;
   }

    int microsecondsToCentimeters(int microseconds)
   {
  
      return microseconds / 29 / 2;
   }


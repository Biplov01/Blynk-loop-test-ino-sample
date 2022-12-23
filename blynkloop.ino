#include <WiFi.h>
#define BLYNK_TEMPLATE_ID "TMPLCoOpSAEG"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#include <BlynkSimpleEsp32.h>

//--------------------------------------
// Constants
//--------------------------------------

#define BLYNK_AUTH_TOKEN "pdv0tMruBTQGD7aHBnOd4XUXniSuzkVc"
char ssid[] = "RAMESH_NTFiber";
char pass[] = "9849981596";
int sensval = 0;
const int senspin = 2;




BlynkTimer timer;

void myTimerEvent()
{
  if (sensval < 1000)
  sensval += 1;
  Blynk.virtualWrite(V6, sensval);
 
}

void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid,pass); //Comment this if you're using Local Server
  //If you have your Local Blynk Server then uncomment this statement --> Blynk.begin(auth, wifi, ssid, pass, "Your_Machine's_IP_Address", 8080);   //Use your server's port if this doesn't work

  timer.setInterval(100L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); 
  }
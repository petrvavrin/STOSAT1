#include <SD.h>
#include <ESP8266WiFi.h>
#include "ESP8266FtpServer.h"

// variables
const char* ssid = "STOSAT1_COM";
const char* password = "STOSAT1_SYS";
const char* ftpUsername = "STOSAT1_FTP";
const char* ftpPassword = "passwordisSTOSAT1";

// config static IP
IPAddress apIP(10, 0, 0, 1);  
IPAddress gateway(10, 0, 0, 1);
IPAddress subnet(255, 255, 255, 0); 


FtpServer STOSAT1_FTP;//set #define FTP_DEBUG in ESP8266FtpServer.h to see ftp verbose on serial

//-----------------------
//-------S E T U P-------
void setup(void){

  Serial.begin(115200);
  Serial.println("STOSAT1: Initialization start in 5s");
  delay(5000);

  //Setting the Ip address for the WiFi connectivity
  WiFi.config(apIP, gateway, subnet);
  Serial.println();
  Serial.print("STOSAT1: Configuring APM");
  //Setting the esp to softaccess point mode
  WiFi.mode(WIFI_AP);
  WiFi.disconnect();
  delay(100);

  //changing softAP config and starting the Start AP
  WiFi.softAPConfig(apIP, gateway, subnet);
  WiFi.softAP(ssid, password);

  //2 indicates the Chip select pin
  if (SD.begin(2)) {
    Serial.println("STOSAT1: FMC opened");
    STOSAT1_FTP.begin(ftpUsername, ftpPassword);    //username, password for ftp.  set ports in ESP8266FtpServer.h  (default 21, 50009 for PASV)
  }

  Serial.println("STOSAT1: Initialization completed");
  delay(100);
  Serial.println("STOSAT1: COM end");
}

//-----------------------
//--------L O O P--------
void loop(void){

  STOSAT1_FTP.handleFTP();        //make sure in loop you call handleFTP()!!   

}
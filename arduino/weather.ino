#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define WIFI_SSID "Federer"
#define WIFI_PASSWORD "91DDEF4D24"
#define JSON_MEMORY_BUFFER 1024*2

const char* API_KEY = "a053086bb6e741a096a231029262007";
WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "server 0.us.pool.ntp.org"); 
 
float lat = 27.234°;
float lon = -82.474°;
 
String weather_url = "https://weatherapi-com.p.rapidapi.com/current.json?q=" + String(lat) + "%2C" + String(lon);

String current_time;
String hour;
String minute;
String alternative;
String weekDay;
String month;
int day;
int year;
int temp;

String weekDays[7]={"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
String months[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

unsigned long lastTime = 0;
unsigned long fetch_delay = 5000;

void setup(void){

  Serial.begin(9600); 
  tft.init(240, 240);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  timeClient.begin();
  timeClient.setTimeOffset(19800);
  tft.fillScreen(0);
  tft.setTextColor(ST77XX_CYAN);
  tft.setTextSize(2);
  String loading = ".";
  while(WiFi.status() != WL_CONNECTED){  
    tft.setCursor(40, 90);
    tft.println("Connecting to ");
    tft.setCursor(40, 125);
    tft.print(WIFI_SSID);
    tft.println(loading);
    loading += ".";
    delay(500);
  }
  tft.fillScreen(0);
  tft.setCursor(60, 110);
  tft.println("Connected!");
  delay(3000);
  tft.fillRect(60, 110, 130, 50, ST77XX_BLACK);
  fetchTemp();
}

void loop(){
  timeClient.update();
  if((millis() - lastTime) > fetch_delay){
    currentTime();
    fetchTemp();
    lastTime = millis();
  }
  display();
}

void display(){
  int font_w = 6;
  int font_h = 8;

  int time_size = 6;
  int alt_size = 2;
  int day_size = 3;

  int display_w = 240;
  int display_h = 240;

  int padding = 8;

  tft.setTextSize(time_size); 
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);

  int time_x = (display_w/2) - ((font_w*time_size)*5)/2 - (font_w * alt_size);
  int time_y = 40;

  tft.setCursor(time_x, time_y);
  tft.println(current_time);
  tft.setTextSize(alt_size);
  tft.setCursor((time_x + (font_w*time_size)*5), time_y);
  tft.println(alternative);
  tft.drawBitmap((time_x + (font_w*time_size)*4 + 14), (time_y + (font_h*time_size) + padding), wifi, 31, 24, ST77XX_WHITE);
  tft.setTextSize(day_size);
  tft.setCursor(20, time_y+(font_h*time_size) + padding + 10);
  tft.println(weekDay);
  tft.setCursor(20, time_y+(font_h*time_size) + (font_h*day_size) + padding * 2 + 10);
  tft.println(day);
  tft.setCursor(20 + (font_w * day_size)*2 + padding, time_y+(font_h*time_size) + (font_h*day_size) + padding * 2 + 10);
  tft.println(month);
  tft.setTextSize(4);
  tft.setCursor(20,  time_y+(font_h*time_size) + (font_h*day_size) * 2 + padding * 3 + 10);
  tft.println(year);
  int temp_x = display_w - (font_w * 4)*2 - padding - (font_w * alt_size);
  tft.setCursor(temp_x,  time_y+(font_h*time_size) + (font_h*day_size) + padding * 2 + 10);
  tft.println(temp);
  tft.setTextSize(alt_size);
  tft.setCursor(temp_x +(font_w * 4) *2 , time_y+(font_h*time_size) + (font_h*day_size) + padding * 2 + 10);
  tft.println("o");
  tft.setTextSize(4);
  tft.setCursor(temp_x + 10 ,time_y+(font_h*time_size) + (font_h*day_size) * 2 + padding * 3 + 10);
  tft.println("C");
}

void currentTime(){
  hour = String(timeClient.getHours());
  minute = String(timeClient.getMinutes());
  weekDay = weekDays[timeClient.getDay()];
  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  day = ptm->tm_mday;
  int current_month = ptm->tm_mon+1;
  month = months[current_month-1];
  year = ptm->tm_year+1900;
  if(hour.toInt() >= 12){
    alternative = "PM";
  }else{
    alternative = "AM";
  }
  if(hour.toInt() > 12){
    hour = map(hour.toInt(), 13, 24, 1, 12);
  }
  if(hour.toInt() < 10){
    hour = "0" + hour;
  }
  if(minute.toInt() < 10){
    minute = "0" + minute;
  }
  current_time = String(hour) + ":" + minute;
}

void fetchTemp(){
  WiFiClientSecure client;
  HTTPClient https;
  client.setInsecure();
  https.useHTTP10(true);
  if(https.begin(client, weather_url.c_str())){
    https.addHeader("x-rapidapi-key", API_KEY);
    https.addHeader("x-rapidapi-host", API_HOST);

    int httpCode = https.GET();
    if(httpCode > 0){
      if(httpCode == 200){
        DynamicJsonDocument doc(JSON_MEMORY_BUFFER);
        DeserializationError error = deserializeJson(doc, https.getStream());
        Serial.print(https.getStream());
        if(error){
          Serial.println("deserialization error");
          Serial.println(error.f_str());
          temp = -1;
        }else{
          temp = doc["current"]["temp_c"].as<int>();
        }
      }
    }
  }
  https.end();
}
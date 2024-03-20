#include <WiFi.h>
#define NTP_SERVER "pool.ntp.org" // server NTP
#define UTC_OFFSET 0 //setting timezone
#define UTC_OFFSET_DST 0 //daylight saving time
int utc7 = 25200;

void setup() {
  Serial.begin(115200);
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(250);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Online");
  Serial.println("Updating time...");
  configTime(utc7, UTC_OFFSET_DST, NTP_SERVER);
  // fungsi untuk setting jam internal esp32
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Connection Err");
    return;
  }
  Serial.println(&timeinfo, "%H:%M:%S");
  Serial.println(&timeinfo, "%d/%m/%Y");
  delay(250);
}
#include <WiFi.h>
#include <HTTPClient.h>

#define WIFI_STA_NAME "ICM 1"
#define WIFI_STA_PASS "1234567890"

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_STA_NAME);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_STA_NAME, WIFI_STA_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(13, !digitalRead(13));
  }

  digitalWrite(13, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  String url = "https://jsonplaceholder.typicode.com/users/1234";
  Serial.println();
  Serial.println("Get content from " + url);
  
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  String content = http.getString();
  Serial.println(content);
  Serial.println("-----------------");

//  if (httpCode == 200) {
//    String content = http.getString();
//    Serial.println("Content ---------");
//    Serial.println(content);
//    Serial.println("-----------------");
//  } else {
//    Serial.println("Fail. error code " + String(httpCode));
//  }
  Serial.println("END");
}

void loop() {}

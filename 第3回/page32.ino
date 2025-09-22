#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

// ---- 書き換えポイント ----
const char* WIFI_SSID = "ここにwifiのSSID";
const char* WIFI_PASS = "ここにwifiのパスワード";
const char* GAS_URL  = "ここにGASのデプロイのURL";

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) ;
  Serial.println("WiFi connected.");
}

void loop() {
  int data1 = 300;
  int data2 = 400;

  String url = String(GAS_URL) + "?data1=" + data1 + "&data2=" + data2;
  Serial.println(url);

  WiFiClientSecure client;
  client.setInsecure();
  
  HTTPClient http;
  http.begin(client, url);
  http.GET();
  http.end();

  delay(30000); // 30秒ごと
}
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>


const char* ssid = "";
const char* password = "";

String serverName = "http://18.135.31.88:8080/api";
JSONVar response;

int ledPin = 2;
void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  digitalWrite(ledPin, LOW);
  delay(500);

  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    http.begin(serverName.c_str());
    http.addHeader("Content-Type", "application/json");
    JSONVar request;
    request["something"] = "hey";
    Serial.println(JSONVar::stringify(request));
    int httpResponseCode = http.POST(JSONVar::stringify(request));

    if(httpResponseCode > 0){
      response = JSON.parse(http.getString());
      Serial.println(response);
    }
    else{
      Serial.println("Error occured");
    }
    http.end();
    
  }
  
  digitalWrite(ledPin, HIGH);
  delay(500);
}

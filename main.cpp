#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "OPPOA92"; // Enter your WiFi name
const char *password = "12345678990";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "tubesiot/cahaya";
const char *mqtt_username = "hikari";
const char *mqtt_password = "12345";
const int mqtt_port = 1883;
const int ldr = A0;

WiFiClient espClient;
PubSubClient client(espClient);
uint32_t counter;
char str[80];

long now = millis();
long lastMeasure = 0;
long lastMsg = 0;
char msg[50];
int value = 0;

void callback(char *topic, byte *payload, unsigned int length) {
 String string; 
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
 for (int i = 0; i < length; i++) {
     Serial.print((char) payload[i]);
     string += ((char)payload[i]);
 }
 Serial.println();
 Serial.println("-----------------------");

 if ((char)payload[0] == '0') {
  Serial.println("LAMPU MATI");
  digitalWrite(D2, LOW);
 }
 else if ((char)payload[0] == '1') {
  Serial.println("LAMPU NYALA");
  digitalWrite(D2, HIGH);
 }
}

void setup() {
 pinMode(D8, OUTPUT);
 digitalWrite(D8, LOW);
 // Set software serial baud to 115200;
 Serial.begin(115200);
 // connecting to a WiFi network
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Connecting to WiFi..");
 }
 Serial.println("Connected to the WiFi network");
 //connecting to a mqtt broker
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);
 while (!client.connected()) {
     String client_id = "esp32-client-";
     client_id += String(WiFi.macAddress());
     Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
     if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
         Serial.println("Public emqx mqtt broker connected");
     } else {
         Serial.print("failed with state ");
         Serial.print(client.state());
         delay(2000);
     }
 }
 // publish and subscribe
 client.publish(topic, "Hi EMQX I'm esp ^^");
 client.subscribe(topic);
}

void loop() {
 client.loop();   
 now = millis();
 if (now - lastMeasure > 3000) {
  lastMeasure = now;
  int nilai = analogRead(ldr);

  static char intensitasCahaya[7];
  dtostrf(nilai,6,2,intensitasCahaya);

  client.publish(topic, intensitasCahaya);

  Serial.print("Cahaya = ");
  Serial.print(nilai);
  Serial.println("V");
 }
 
}
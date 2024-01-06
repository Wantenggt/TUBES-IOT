#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFiaa
const char *ssid = "OPPOA92"; // Enter your WiFi name
const char *password = "12345678990";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "hikari";
const char *mqtt_username = "hikari";
const char *mqtt_password = "hikari";
const int mqtt_port = 1883;
const int ldr = A0;
const int relayPin = D4;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length) {
 String string;
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
 for (int i = 0; i < length; i++) {
     Serial.print((char) payload[i]);
     string += ((char)payload[i]);
 }
 Serial.println(string);
  if ((char)payload[0] == '0')  {
    Serial.println("LAMPU MATI");
    digitalWrite(D4, LOW);

  }
  else if ((char)payload[0] == '1')  {
    Serial.println("LAMPU NYALA");
    digitalWrite(D4, HIGH);

    }
  Serial.println();
 Serial.println("-----------------------");
}

void setup() {
 // Set software serial baud to 115200;
 Serial.begin(115200);
 // connecting to a WiFi network
 pinMode(relayPin, OUTPUT);
 pinMode(relayPin, LOW);
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
     String client_id = "mqttx_1cf3c425";
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
 int ldrValue = analogRead(ldr);
  if (ldrValue < 300) { 
    digitalWrite(relayPin, HIGH); // Nyalakan lampu
    client.publish(topic, "Light is ON");
  } else {
    digitalWrite(relayPin, LOW); // Matikan lampu
    client.publish(topic, "Light is OFF");
  }
  delay(2000);
}
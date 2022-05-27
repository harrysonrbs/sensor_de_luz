#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//declaração de variáveis de ssid e password de rede de conexão wifi
const char* ssid = "Home 2.4G";
const char* password = "HtA@$19749697";

//declaração de variáveis das informações de comunicação com Broker público, endereço e porta
const char* mqtt_server = "broker.mqttdashboard.com";
const int mqtt_server_port = 1883;

#define MSG_BUFFER_SIZE (500)
WiFiClient client;
PubSubClient mqtt_client(client);
long lastMsg = 0;

//declaração de variáveis de configuração dos tópicos, global, sensor, atuador e mensagens
String clientID = "ESP8266Client-";
String topicoPrefixo = "MACK20000243";
String topicoTodos = topicoPrefixo + "/#";
String topico_0 = topicoPrefixo + "Hello, World";
String mensagem_0 = "NodeMCU Conectado";
String topico_1 = topicoPrefixo + "/sensor1"; //ldu
String mensagem_1 = "";
String topico_2 = topicoPrefixo + "/atuador1"; //led
String mensagem_2 = "";
String mensagemTemp = "";

//função que estabelece a conexão com a rede wifi utilizando as variáveis de ssid e password
void setup_wifi() {
  Serial.print("Conectando para ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado, IP address ");
  Serial.println(WiFi.localIP());
}

//função de reconexão constante com o Broker público
void reconnect() {
  while (!mqtt_client.connected()) {
    Serial.print("MQTT Connection...");

    randomSeed(micros());
    clientID += String(random(0xffff), HEX);

    if (mqtt_client.connect(clientID.c_str())) {
      Serial.print("Conectado.");
      mqtt_client.publish(topico_0.c_str(), mensagem_0.c_str());
      mqtt_client.subscribe(topicoTodos.c_str());
    } else {
      Serial.print("Falha, rc=");
      Serial.print(mqtt_client.state());
      Serial.println(" try again in 5 seconds");

      delay(500);
    }
  }
}

//função para o recebimento de mensagens conforme a ação do atuador
void callback(char* topic, byte* payload, unsigned int length) {
  mensagemTemp = "";
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    mensagemTemp += (char)payload[i];
  }

  if (String(topic) == topico_2) {
    mensagem_2 = mensagemTemp;
  }
  
  Serial.println();
  
  if ((char)payload[0] != NULL) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

//declaração de variáveis dos pinos utilizados de NodeMCU ESP8266 para o funcionamento correto do circuito
const int ledPin = D2;
const int ldrPin = A0;

//função setup que declaramos todas as função que utilizaremos
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  setup_wifi();
  mqtt_client.setServer(mqtt_server, mqtt_server_port);
  mqtt_client.setCallback(callback);
}

//função loop é basicamente o funcionamento do nosso circuito
void loop() {
  if (!mqtt_client.connected()) {
    reconnect();
    }
    
  mqtt_client.loop();

  int ldrStatus = analogRead(A0);
  if (ldrStatus <= 200) {
    digitalWrite(ledPin, HIGH);
    mensagem_2 = "LED ON";
    Serial.println(ldrStatus);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println(ldrStatus);
      mensagem_2 = "LED OFF";
      }

    long now = millis();
    if (now - lastMsg > 2000) {
      lastMsg = now;
      mqtt_client.publish(topico_2.c_str(), mensagem_2.c_str());
    }
    if (ldrStatus <= 200) {
      digitalWrite(D2, 1);
      } else {
        digitalWrite(D2, 0);
        }
}

#include <WiFi.h>
#include <PubSubClient.h>

// Brotas Alerta — protótipo educativo
// Wokwi costuma oferecer a rede de simulação "Wokwi-GUEST".
const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

const char* MQTT_SERVER = "broker.hivemq.com";
const int MQTT_PORT = 1883;

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;

// Ajuste esta altura à montagem simulada. É uma referência didática.
const float ALTURA_REFERENCIA_CM = 100.0;

WiFiClient espClient;
PubSubClient mqtt(espClient);

unsigned long lastPublish = 0;

void conectarWiFi() {
  Serial.print("Conectando ao Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  unsigned long inicio = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - inicio < 20000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWi-Fi ainda não conectou. Será tentado novamente.");
  }
}

bool conectarMQTT() {
  if (mqtt.connected()) return true;

  String clientId = "BrotasAlerta-";
  clientId += String((uint32_t)ESP.getEfuseMac(), HEX);

  Serial.print("Conectando ao MQTT...");
  if (mqtt.connect(clientId.c_str())) {
    Serial.println(" conectado!");
    return true;
  }

  Serial.print(" falhou, estado = ");
  Serial.println(mqtt.state());
  return false;
}

float medirDistanciaCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Timeout para evitar que a leitura fique presa.
  unsigned long duracao = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duracao == 0) return -1.0;

  return (duracao * 0.0343f) / 2.0f;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  conectarWiFi();
  mqtt.setServer(MQTT_SERVER, MQTT_PORT);
  mqtt.setBufferSize(256);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    conectarWiFi();
  }

  if (!mqtt.connected()) {
    conectarMQTT();
  }
  mqtt.loop();

  if (millis() - lastPublish >= 3000) {
    lastPublish = millis();

    float distancia = medirDistanciaCm();
    if (distancia < 0) {
      Serial.println("Sem leitura válida do sensor. Confira a ligação.");
      return;
    }

    // O sensor fica acima da água: menor distância significa nível mais alto.
    float percentual = (ALTURA_REFERENCIA_CM - distancia) / ALTURA_REFERENCIA_CM * 100.0f;
    percentual = constrain(percentual, 0.0f, 100.0f);
    float alturaAgua = ALTURA_REFERENCIA_CM - distancia;
    alturaAgua = constrain(alturaAgua, 0.0f, ALTURA_REFERENCIA_CM);

    char textoPercentual[16];
    char textoCm[16];
    snprintf(textoPercentual, sizeof(textoPercentual), "%.1f", percentual);
    snprintf(textoCm, sizeof(textoCm), "%.1f", alturaAgua);

    Serial.print("Distância: ");
    Serial.print(distancia);
    Serial.print(" cm | Nível estimado: ");
    Serial.print(percentual);
    Serial.println("%");

    if (mqtt.connected()) {
      mqtt.publish("iot-brotas/agua/percentual", textoPercentual, true);
      mqtt.publish("iot-brotas/agua/nivel_cm", textoCm, true);
    }
  }
}

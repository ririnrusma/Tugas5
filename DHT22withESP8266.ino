#include <DHT.h>
#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const int lampu = 13;
float hum;
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(lampu, OUTPUT);
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  ");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C \n");


  if (temp >= 35 || hum >= 50) {
    digitalWrite(lampu, HIGH);
  } else {
    digitalWrite(lampu, LOW);
  }

  delay(2000);

}

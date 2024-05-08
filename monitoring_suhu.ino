#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
int lcdColumns = 16;
int lcdRows = 2;
const int redLedPin = 23;
const int greenLedPin = 18;
const int buzzerPin = 19; 

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();  
  lcd.begin(16, 2);
  lcd.init();                     
  lcd.backlight();
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT); // Atur pin buzzer sebagai output
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    lcd.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Humidity: "));
  lcd.print(h);
  lcd.print(F("%"));
  
  lcd.setCursor(0,1);
  lcd.print(F("Suhu: "));
  lcd.print(t);
  lcd.print(F(" C")); 
  
  
  if (t >= 40) {
    digitalWrite(redLedPin, HIGH);   
    digitalWrite(greenLedPin, LOW);  
    tone(buzzerPin, 1000); 
    delay(1000); 
    noTone(buzzerPin); 
  } else {
    digitalWrite(redLedPin, LOW);    
    digitalWrite(greenLedPin, HIGH); 
    noTone(buzzerPin);
  }
}

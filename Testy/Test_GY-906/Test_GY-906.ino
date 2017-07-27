#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>

//Adafruit_MLX90614mlx=Adafruit_MLX90614(0x5A);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  mlx.begin();
  lcd.init();
  lcd.backlight();
  lcd.noDisplay();
  lcd.display();
}

void loop()
{
  /*Serial.print("Ta=");
    Serial.print(mlx.readAmbientTempC());
    Serial.print("*C\nTo=");
    Serial.print(mlx.readObjectTempC());
    Serial.print("*C");*/
  lcd.setCursor(0, 0);
  lcd.print("Ta=");
  lcd.print(mlx.readAmbientTempC());
  lcd.print("*C");

  lcd.setCursor(0, 1);
  lcd.print("To=");
  lcd.print(mlx.readObjectTempC());
  lcd.print("*C");
  delay(500);
}

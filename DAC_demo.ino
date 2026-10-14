/*====================================================
                      DAC DEMO 
======================================================
Description:
  This code reads the potentiometer’s analog value, 
  converts it into voltage, displays both values on 
  the Serial Monitor, and outputs an analog voltage 
  through the ESP32’s DAC pin (GPIO 25).

Programmer:
  De Asis, Felicity M.
  Dela Torre, Shanna Dale R.
  Galpo, Rhile L.

Date:
  14 October 2026
----------------------------------------------------*/
//GPIO Pins
const byte POT = 36;
const byte DAC_PIN = 25;

//variables
int adc_val = 0; //3102
float voltage_in = 0; // 2.5v <- result calc (not the input read)

void setup() {
  //adc pin
  pinMode(POT, INPUT);
  analogReadResolution(8);  //8-bit

  //DAC pin
  pinMode(DAC_PIN, OUTPUT);

  Serial.begin(9600);  //baud rate bps
}

void loop() {
  // 8-bit ADC numerical value
  adc_val = analogRead(POT);
  Serial.printf("ADC Numeric Value: %d\n", adc_val);  // % placeholder
  delay(500);

  //Convert 8-bit ADC to actual voltage
  voltage_in = (adc_val/255.0)*3.3;
  Serial.printf("Input Voltage: %.2f\n", voltage_in);
  delay(500);

  // Use multimeter to verify the actual voltage
  dacWrite(DAC_PIN, adc_val); // 1.8 val - 2.3
}
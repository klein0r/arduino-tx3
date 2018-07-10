#include "Arduino.h"

#define TX3_MODELID  0x0A    // Fix defines a TX3 Sensor
#define TX3_COM_TEMP 0x0     // Command key for Transmitting Temperature
#define TX3_COM_HUM  0xE     // Command key for Transmitting Humidity

#define TX3_LONG_PULSE 975
#define TX3_SHORT_PULSE 250
#define TX3_DELAY 1450

class TX3 {
public:
  TX3(int pin, int sensorId);

  void sendTemperature(float t);
  void sendHumidity(float h);
  void setRepeatTransmit(int n);

private:
  int dataPin, sensorId, nRepeatTransmit;

  void O();
  void I();
  void sendNibbles(int type, int tens, int ones, int tenths);
  void sendNibble(int i);
};

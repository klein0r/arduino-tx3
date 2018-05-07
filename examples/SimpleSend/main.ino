#include <TX3.h>

#define PIN_SEND 5      // what digal pin 433 Sender is connected
#define SENSORID 110    // Values from 1 to 127 are valid

TX3 tx3(PIN_SEND, SENSORID);

void setup() {
}

void loop() {
  tx3.sendHumidity(55.3);
  tx3.sendTemperature(35.1);

  delay(5000);
}

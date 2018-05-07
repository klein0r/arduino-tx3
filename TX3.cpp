#include "TX3.h"

TX3::TX3(int pin, int id)
{
  dataPin = pin;
  sensorId = id;

  pinMode(dataPin, OUTPUT);
}

void TX3::sendTemperature(float t)
{
  sendNibles(
    TX3_COM_TEMP,
    (int(t) / 10) + 5,
    (int(t) % 10),
    (int(t * 10) % 10)
  );
}

void TX3::sendHumidity(float h)
{
  sendNibles(
    TX3_COM_HUM,
    (int(h) / 10),
    (int(h) % 10),
    (int(h * 10) % 10)
  );
}

void TX3::sendNibles(int type, int tens, int ones, int tenths)
{
  int idr, checksum, parity;
  int nible1, nible2, nible3, nible4, nible5, nibble6, nibble7, nibble8, nibble9, nibble10;

  // left  nible of Model
  nible1 = TX3_MODELID / 0x10;

  // right  nible of Model
  nible2 = TX3_MODELID & 0xF;

  nible3 = type;

  // Nible 4 is the left part of the Id
  // 1101 111?
  // 0110 1111
  nible4 = sensorId / 0x08;

  nibble6 = tens;
  nibble7 = ones;
  nibble8 = tenths;

  nibble9 = tens;
  nibble10 = ones;

  // For Parity we need the last 3 bits of the Sensor ID
  idr = sensorId & 0x7;

  // Parity bit makes even parity for sum
  parity = (nible4 + idr + nibble6 + nibble7 + nibble8 + nibble9 + nibble10) & 0x1;

  // nible 5 is last 3 digits of Sensor and parity bit
  nible5 = ((idr * 0x2) + parity) & 0xF;

  // Checksum nible of all nibles
  checksum = (nible1 + nible2 + nible3 + nible4 + nible5 + nibble6 + nibble7 + nibble8 + nibble9 + nibble10) & 0xF;

  for (int r = 0; r < 2; r++) {
    sendNibble(nible1);
    sendNibble(nible2);
    sendNibble(nible3);
    sendNibble(nible4);
    sendNibble(nible5);
    sendNibble(nibble6);
    sendNibble(nibble7);
    sendNibble(nibble8);
    sendNibble(nibble9);
    sendNibble(nibble10);
    sendNibble(checksum);
    delay(20);
  }
}

void TX3::sendNibble(int i)
{
  if (i & 8) I(); else O();
  if (i & 4) I(); else O();
  if (i & 2) I(); else O();
  if (i & 1) I(); else O();
}

void TX3::O()
{
  // sends zero
  digitalWrite(dataPin, HIGH);
  delayMicroseconds(TX3_LONG_PULSE);
  digitalWrite(dataPin, LOW);
  delayMicroseconds(TX3_DELAY);
}

void TX3::I()
{
  // sends one
  digitalWrite(dataPin, HIGH);
  delayMicroseconds(TX3_SHORT_PULSE);
  digitalWrite(dataPin, LOW);
  delayMicroseconds(TX3_DELAY);
}

#ifndef LED_UTILS_H_
#define LED_UTILS_H_

void setLedColor(const uint8_t r, const uint8_t g, const uint8_t b);

void flashLed(const uint8_t r, const uint8_t g, const uint8_t b, unsigned long interval);

#endif // LED_UTILS_H_
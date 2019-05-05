#ifndef AUGMENT_HAND_PIN_CONFIG_H_
#define AUGMENT_HAND_PIN_CONFIG_H_

// I2C
// GY-521s
const uint8_t ACC_1_I2C_ADDRESS = 0x68;
const uint8_t ACC_2_I2C_ADDRESS = 0x69;
const uint8_t MPU_ADDRESSES[2] = { ACC_1_I2C_ADDRESS, ACC_2_I2C_ADDRESS };

// Realtime clock
const uint8_t RTC_I2C_ADDRESS = 0x56;

// Inputs
const uint8_t DIG_PIN_BUTTON = 8;

const uint8_t ANA_PIN_TILT_SWITCH = 1;
const uint8_t ANA_PIN_BRIGHTNESS = 2;
const uint8_t ANA_PIN_FLEX = 3;

// Outputs
const uint8_t DIG_PIN_BUZZER = 10;
const uint8_t DIG_PIN_LED_R = 11;
const uint8_t DIG_PIN_LED_G = 12;
const uint8_t DIG_PIN_LED_B = 13;

// GY-61 accelerometers
const uint8_t DIG_PIN_ACC_3_X = 0;
const uint8_t DIG_PIN_ACC_3_Y = 1;
const uint8_t DIG_PIN_ACC_3_Z = 2;
const uint8_t DIG_PIN_ACC_4_X = 3;
const uint8_t DIG_PIN_ACC_4_Y = 4;
const uint8_t DIG_PIN_ACC_4_Z = 5;

#endif // AUGMENT_HAND_PIN_CONFIG_H_
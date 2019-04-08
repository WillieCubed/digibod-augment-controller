#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>

#include <Wire.h>
#include <string>

const int xpin = 1; // x-axis of the accelerometer
const int ypin = 2; // y-axis
const int zpin = 3; // z-axis (only on 3-axis models)

const uint8_t AUGMENT_HUB_I2C_ADDRESS = 0x16;
const uint8_t ACC_1_I2C_ADDRESS = 0x68;
const uint8_t ACC_2_I2C_ADDRESS = 0x69;

const uint8_t ANA_PIN_SEND_SNAPSHOT = 0;
const uint8_t ANA_PIN_TILT_SWITCH = 1;
const uint8_t ANA_PIN_BRIGHTNESS = 2;
const uint8_t ANA_PIN_FLEX = 3;

const uint8_t DIG_PIN_ACC_3_X = 0;
const uint8_t DIG_PIN_ACC_3_Y = 1;
const uint8_t DIG_PIN_ACC_3_Z = 2;
const uint8_t DIG_PIN_ACC_4_X = 3;
const uint8_t DIG_PIN_ACC_4_Y = 4;
const uint8_t DIG_PIN_ACC_4_Z = 5;
const uint8_t DIG_PIN_LED_R = 10;
const uint8_t DIG_PIN_LED_G = 11;
const uint8_t DIG_PIN_LED_B = 12;
const uint8_t DIG_PIN_BUZZER = 13;

const uint8_t FINGER_SENSORS_ANA_IDS[2][3] = {
    {DIG_PIN_ACC_3_X,
     DIG_PIN_ACC_3_Y,
     DIG_PIN_ACC_3_Z},
    {DIG_PIN_ACC_4_X,
     DIG_PIN_ACC_4_Y,
     DIG_PIN_ACC_4_Z}};

const uint8_t *FINGER_SENSORS_I2C_IDS[2] = {ACC_1_I2C_ADDRESS, ACC_2_I2C_ADDRESS};

bool constantCollectionEnabled = false;

// A single recording of accelerometer data.
struct AccelerometerSnapshot
{
    float x;
    float y;
    float z;
};

// A single recording of flex sensor reistance.
struct FlexSensorSnapshot
{
    float resistance;
};

// A single recording of tilt sensor bias.
struct TiltSensorSnapshot
{
    float resistance;
};

// A single recording of brightness data.
struct LightSensorSnapshot
{
    float value;
};

// A container for sensor data sent over I2C.
struct AugmentSnapshot
{
    // An array with sensor values for each finger, size 5.
    AccelerometerSnapshot *accelerometerSnap;
    // A singular sensor value
    FlexSensorSnapshot flexSnap;
    TiltSensorSnapshot tiltSnap;
    LightSensorSnapshot lightSnap;
};

// Data sent from the connected Augment Hub.
//
// Used for actions like:
//  - Turning on or off data for training
struct HubFeedback
{
    bool enableCollectionForTraining;
};

// Compiles all sensor data into a usable form.
AugmentSnapshot getAugmentSnapshot()
{
    AugmentSnapshot snap = {};
    // TODO: Handle multiple sensors
    AccelerometerSnapshot accSnaps[5] = {};
    for (int i = 0; i < 2; ++i) // Only the first two fingers use these sensors
    {
        AccelerometerSnapshot accSnap = {};
        for (int j = 0; i < sizeof(FINGER_SENSORS_ANA_IDS); ++i)
        {
            accSnap.x = analogRead(FINGER_SENSORS_ANA_IDS[j][0]);
            accSnap.y = analogRead(FINGER_SENSORS_ANA_IDS[j][1]);
            accSnap.z = analogRead(FINGER_SENSORS_ANA_IDS[j][2]);
        }
    }
    for (int i = 0; i < 2; ++i) {
        // Now get the ones for I2C
    }
    return snap;
}

  ~ConnectionManager()
  {
  }

  /**
   * Connects to a Digibod Augment Hub.
   */
  void connectToHub()
  {
  }

  void registerCallback()
  {
  }

  void removeCallbacks()
  {
  }

  void sendDataToHub(string sensorName, byte date[])
  {
    // Wire.
  }

private:
};

}

ConnectionManager manager;

void setup()
{
  // put your setup code here, to run once:
  // TODO: Setup connectivity via wire or Bluetooth)

  manager = new ConnectionManager();
}

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // TODO: Gather inputs
  // TODO: Expose data to Augment Hub via I2C, later wirelessly
  SensorSnapshot snap = {}
  int x = analogRead(xpin); //read from xpin
  int y = analogRead(ypin); //read from ypin
  int z = analogRead(zpin); //read from zpin
  snap.x = x
  snap.y = y;
  snap.z = z;
  float zero_G = 512.0; //ADC is 0~1023  the zero g output equal to Vs/2
                        //ADXL335 power supply by Vs 3.3V
  float scale = 102.3;  //ADXL335330 Sensitivity is 330mv/g
                        //330 * 1024/3.3/1000
  Serial.print(((float)x - 331.5) / 65 * 9.8); //print x value on serial monitor
  Serial.print("\t");
  Serial.print(((float)y - 329.5) / 68.5 * 9.8); //print y value on serial monitor
  Serial.print("\t");
  Serial.print(((float)z - 340) / 68 * 9.8); //print z value on serial monitor
  Serial.print("\n");
  delay(500);
  manager.sendDataToHub("", data);
}

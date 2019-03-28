#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>

#include <Wire.h>
#include <string>

const int xpin = 1; // x-axis of the accelerometer
const int ypin = 2; // y-axis
const int zpin = 3; // z-axis (only on 3-axis models)


using namespace std;

/**
 * For now, this uses I2C to send data back to the Augment Hub.
 */
class ConnectionManager
{

public:
  ConnectionManager()
  {

    // Start observing I2C
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

struct SensorSnapshot {
  int x;
  int y;
  int z;
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

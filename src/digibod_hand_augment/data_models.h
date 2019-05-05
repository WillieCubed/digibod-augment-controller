/**
 * Various data models for serialization and deserialization.
 */

// A single recording of accelerometer data.
struct AccelerometerSnapshot
{
    float x;
    float y;
    float z;
};

struct GyroscopeSnapshot
{
    float x;
    float y;
    float z;
};

struct TemperatureSnapshot
{
    // Measured in degrees celsius
    float temp;
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
    // An array with sensor values for four fingers, size 4.
    AccelerometerSnapshot *accSnaps;
    // An array with sensor values for two chips, size 2
    GyroscopeSnapshot *gyroSnaps;
    FlexSensorSnapshot *flexSnaps;
    TiltSensorSnapshot *tiltSnaps;
    TemperatureSnapshot *tempSnaps;
    LightSensorSnapshot *lightSnaps;
};
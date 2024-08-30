#ifndef LIBRARIES_SENSORS_HID_H
#define LIBRARIES_SENSORS_HID_H

#ifndef LIBRARIES_SENSORS_H
# include <libraries/sensors.h>
#endif

/* STRING, HID device name */
#define SENSORS_HID_Name                        (SENSORS_Dummy + 2000)

/* ULONG, HID device Vendor ID */
#define SENSORS_HID_Vendor                      (SENSORS_Dummy + 2001)

/* ULONG, HID device Produce ID */
#define SENSORS_HID_Product                     (SENSORS_Dummy + 2002)

/* STRING, HID device's serial number, if non-empty, it may be used
** to serialize per-controller settings */
#define SENSORS_HID_Serial                      (SENSORS_Dummy + 2003)

/*
** Sensors in the HIDInput class are always child sensors of a SENSORS_HID
** sensor. Each SENSORS_HID sensor corresponds to a single physical device
** like a pad, joystick, etc. In case of devices like the Xbox Wireless
** Controller PC adapter, which can handle up to 4 pads, a SENSORS_HID sensor
** will be created for each pad synchronized with the receiver.
**
** Pads may disappear at any time, resulting in a removal of the sensor!
**
** It is good practice to implement a learning mechanism for the inputs.
*/

/* This section describes input values associated with the sensor */

/* DOUBLE *, current state of the input for HID_Trigger and HID_Analog
** sensors */
#define SENSORS_HIDInput_Value                  (SENSORS_Dummy + 2200)

/* DOUBLE *, current state of the input in the N-S direction of 
** HID_Stick and HID_AnalogStick inputs */
#define SENSORS_HIDInput_NS_Value               (SENSORS_Dummy + 2201)

/* DOUBLE *, current state of the input in the E-W direction of 
** HID_Stick and HID_AnalogStick inputs */
#define SENSORS_HIDInput_EW_Value               (SENSORS_Dummy + 2202)

/* 3D Analog sticks may report a whole lot more values, they're all DOUBLE */
#define SENSORS_HIDInput_X_Index                (SENSORS_Dummy + 2203)
#define SENSORS_HIDInput_Y_Index                (SENSORS_Dummy + 2204)
#define SENSORS_HIDInput_Z_Index                (SENSORS_Dummy + 2205)

#define SENSORS_HIDInput_X_Rotation             (SENSORS_Dummy + 2206)
#define SENSORS_HIDInput_Y_Rotation             (SENSORS_Dummy + 2207)
#define SENSORS_HIDInput_Z_Rotation             (SENSORS_Dummy + 2208)

#define SENSORS_HIDInput_X_Vector               (SENSORS_Dummy + 2209)
#define SENSORS_HIDInput_Y_Vector               (SENSORS_Dummy + 2210)
#define SENSORS_HIDInput_Z_Vector               (SENSORS_Dummy + 2211)

#define SENSORS_HIDInput_X_BodyRelVector        (SENSORS_Dummy + 2212)
#define SENSORS_HIDInput_Y_BodyRelVector        (SENSORS_Dummy + 2213)
#define SENSORS_HIDInput_Z_BodyRelVector        (SENSORS_Dummy + 2214)

/* This section contains other properties of the input sensor, namely ones
** that do not change based on user input */

/* ULONG, HID controller's input trigger's unique identifier, may be handy
** if the device has several similar inputs like analog sticks */
#define SENSORS_HIDInput_ID                     (SENSORS_Dummy + 2300)

/* STRING, Human readable description of the input. In English */
#define SENSORS_HIDInput_Name                   (SENSORS_Dummy + 2301)

/* STRING, Human readable description of the input. Localized */
#define SENSORS_HIDInput_Name_Translated        (SENSORS_Dummy + 2302)

/* ULONG, XXRRGGBB, color of the input trigger, if known */
#define SENSORS_HIDInput_Color                  (SENSORS_Dummy + 2303)

/* ULONG, Sensor_HIDInput_Limb, for controllers held in both hands,
** tells which hand controls the given input, etc */
#define SENSORS_HIDInput_Limb                   (SENSORS_Dummy + 2304)



/* Rumble control sensors */

/* Controlling a rumble in a pad is relatively simple. Once a client
** locates a rumble sensor, it can call SetSensorAttr in order to power
** the motors on. To power on a motor, one has to set both the Power and
** Duration attributes pairs. */

/* DOUBLE *, sets the rumble motor power, values between 0.0 and 1.0.
** This attribute follows the SENSORS_AllowSetAttr paradigm */
#define SENSORS_HIDInput_Rumble_Power           (SENSORS_Dummy + 2401)

/* ULONG, ms, the time to power the rumble on for
** This attribute follows the SENSORS_AllowSetAttr paradigm */
#define SENSORS_HIDInput_Rumble_Duration        (SENSORS_Dummy + 2402)



/* Trigger sensors may sometimes have leds */
/* DOUBLE *, sets the backlight level, 0 for off, 1 for fully on (usually
** values between will result as 'on') */
#define SENSORS_HIDInput_Trigger_Led            (SENSORS_Dummy + 2501)

/* ULONG, triggers a blinking mode for the trigger led */
#define SENSORS_HIDInput_Trigger_Blinking       (SENSORS_Dummy + 2502)

/* values for the main HID class controller */
typedef enum
{
	SensorType_HID_Unknown                   = -1,
	/* A gamepad will have a certain, well defined set of features */
	SensorType_HID_Gamepad                   = 0,
	/* Generic is usually a USB HID device with all HID design pitfalls and limitations */
	SensorType_HID_Generic                   = 1,
	/* A music-purpose device */
	SensorType_HID_Music                     = 2,
} SensorType_HID;

/* values returned by SENSORS_Type for HID class input sensors */
typedef enum
{
	SensorType_HIDInput_Unknown              = -1,
	SensorType_HIDInput_Trigger              = 0, /* single digital button, reports either 0.0 or 1.0 */
	SensorType_HIDInput_Analog               = 1, /* single axis analog button, reports values between 0.0 and 1.0 */
	SensorType_HIDInput_Stick                = 2, /* bidirectional digital stick, reports -1.0 for N, W and 1.0 for S, E */
	SensorType_HIDInput_AnalogStick          = 3, /* bidirectional analog stick, reports values between -1.0 and 0.0 for N, W and 0.0 to 1.0 for S, E */
	SensorType_HIDInput_Battery              = 4, /* wireless controllers often report battery state, 0.0 to 1.0 */
	SensorType_HIDInput_Rumble               = 5, /* rumble motors control */
	SensorType_HIDInput_3DStick              = 6, /* an analog stick that has an additional Z index, rotations and vectors */
	SensorType_HIDInput_Wheel                = 7, /* reports relative movements between -1.0 and 1.0 */
	SensorType_HIDInput_Knob                 = 8, /* reports abs values between -1.0 and 1.0 */
} SensorType_HIDInput;

typedef enum
{
	Sensor_HIDInput_Limb_Unknown             = -1,
	Sensor_HIDInput_Limb_LeftHand            = 0,
	Sensor_HIDInput_Limb_RightHand           = 1,
	Sensor_HIDInput_Limb_EitherHand          = 2,
	Sensor_HIDInput_Limb_LeftLeg             = 3,
	Sensor_HIDInput_Limb_RightLeg            = 4,
	Sensor_HIDInput_Limb_EitherLeg           = 5,
} Sensor_HIDInput_Limb;

#endif

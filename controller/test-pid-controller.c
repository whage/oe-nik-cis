#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PID/PID.c"

#define PID_KP  20.0f
#define PID_KI  0.5f
#define PID_KD  0.25f
#define PID_TAU 0.02f
#define PID_LIM_MIN -2500.0f
#define PID_LIM_MAX  2500.0f
#define PID_LIM_MIN_INT -5.0f
#define PID_LIM_MAX_INT  5.0f
#define SAMPLE_TIME_S 0.01f // TODO: should be based on loop cycle time

#define PID_DESIRED_FORCE 50.0f // TODO: 

bool openPin;
bool closePin;

long long_sensor1_data;
long long_sensor2_data;

float setpoint = PID_DESIRED_FORCE;

int ForceControl(PIDController *pid, bool openPin, bool closePin, long long_sensor1_data, long long_sensor2_data) {
    // take average of the two measurements
    float measurement = (long_sensor1_data + long_sensor2_data) / 2;

    // openPin XOR closePin
    // so that we adjust the setpoint if just one of them is pressed at a time
    if (openPin != closePin) {
        if ( ! openPin) {
            setpoint = PID_DESIRED_FORCE;
        }
        if ( ! closePin) {
            setpoint = 0;
        }
    }

    // compute new control signal
    float controller_output = PIDController_Update(pid, setpoint, measurement);

    return (int)controller_output;
}

int main() {
    PIDController pid = {
        PID_KP,
        PID_KI,
        PID_KD,
        PID_TAU,
        PID_LIM_MIN,
        PID_LIM_MAX,
        PID_LIM_MIN_INT,
        PID_LIM_MAX_INT,
        SAMPLE_TIME_S
    };

    PIDController_Init(&pid);

    printf("#\tMeasurement\tControllerOutput\r\n");

    // fake measurements
    float test_measurements[] = {0,10,20,25};

    // fake main loop
    for (int i = 0; i < sizeof(test_measurements)/sizeof(test_measurements[0]); i++) {
        //ForceControl(&pid, openPin, closePin, long_sensor1_data, long_sensor2_data);
        ForceControl(&pid, openPin, closePin, test_measurements[i], test_measurements[i]);
        printf("%d\t%f\t%f\n", i, test_measurements[i], pid.out);
    }

    return 0;
}

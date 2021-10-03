# Force control of soft-tissue gripper based on strain-measurement

Sallai András - 2021

---

# The challenge - overview
Goal: write the code that implements the force control for a soft-tissue gripper

- learn about the hardware
- set up development environment
- find force control algorithm -> Control theory
- write C code for an embedded device
- test the results

---

# The device

![Soft-tissue gripper](images/soft-tissue-gripper.png) <!-- .element height="35%" width="35%" -->

---

# The device

- soft-tissue gripper
- can be mounted on a robot arm
- stepper motor controls the claws

---

# The controller
- Espressif ESP32 microcontroller: a computer on an integrated circuit
- dual-core with two Harvard Architecture CPUs, up to 480Mhz, 32Kb cache each
- 448 KB Internal ROM
- 520 KB Internal SRAM

---

# Development environment
- ESP-IDF (Espressif IoT Development Framework)
- [good documentation](esp-docs)

---

# Force control

- naive solutions
- from proportional (P) to proportional–integral–derivative (PID) controllers
- fuzzy 

---

# Code
The main program is already done, only the force control implementation is missing:

```
int ForceControl(
	bool openPin,
	bool closePin,
	long long_sensor1_data,
	long long_sensor2_data
) {
     // Implement force control here:
     // return motor speed
}
```

---

# The ForceControl function

- `openPin`: active-low button for opening
- `closePin`: active-low button for closing
- `long_sersor1_data`: measured force on one claw `[0..100]`
- `long_sensor2_data`: measured force on other claw `[0..100]`
- return value: `[-2500, 2500]`

---

[esp-docs]: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/index.html

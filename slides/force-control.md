# Force control of soft-tissue gripper based on strain-measurement

Sallai András - 2021

---

# The challenge - overview
- learn about the hardware
- set up development environment
- find force control algorithm -> Control theory
- coding - embedded device, implementation in C

---

# The hardware
- Espressif ESP32 microcontroller: a micro-computer on an integrated circuit
- dual-core system with two Harvard Architecture CPUs
- 448 KB Internal ROM
- 520 KB Internal SRAM

---

# Development environment
- good [documentation](esp-docs)
-

---

# Code

```
int ForceControl(bool openPin, bool closePin, long long_sensor1_data, long long_sensor2_data)
{
     // TODO: implement force control here
     return motorSpeed
}
```

- `openPin` & `closePin`: active-low button for opening/closing - 0 means the button is pushed 
- `long_sersor1_data` & `long_sensor2_data`: measured force on the arm ``[0..100]`
- return value: `[-2500, 2500]`

---

# Control theory

[esp-docs]: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html

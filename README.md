## WindLogger

Program to measure and analog voltage, convert the value to a wind speed and send the measured values 
via the serial port.

## Required Hardware
1. UDOO X86  
   https://www.udoo.org/discover-udoo-x86-ii/
2. Wind sensor, e.g.   
   https://www.kiwi-electronics.com/nl/windmeter-anemometer-met-analoge-voltage-output-1631
3. Proto shield, cable and connectors

Other Arduino boards can also be used but require adjustments to the build scripts.

### Compile, upload and test
The scripts:
```bash
build.sh
upload.sh
monitor.sh
```
are provided to build, upload and print the output of the program.

### TODO
1. test current code by connecting a potentiometer and measure a voltage in the range 0 to 3.3 V
2. add conversion to wind speed
3. use 10 bits instead of 8 bits
4. adjust the measurement interval to 1 Hz

### Contact
For questions, send an email to uwe.fechner.msc@gmail.com


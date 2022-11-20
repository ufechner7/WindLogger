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
1. adjust the measurement interval to 1 Hz

### Contact
For questions, send an email to uwe.fechner.msc@gmail.com


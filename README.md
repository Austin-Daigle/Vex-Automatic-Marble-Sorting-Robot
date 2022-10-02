## Vex-Automatic-Marble-Sorting-Robot
I originally developed this automatic sorting robot in compliance with the PLTW 3.3 Materials Sorter guidelines. I built this marble sorting machine from the VEX EDR platform guided by the VEX EDR Cortex Microcontroller computer. The criteria for this project is for the machine to automatically separate three different colors of three marbles made of different materials (wood, clear acrylic, and steel). 

![PLTW 3 3 1 (Part 1)](https://user-images.githubusercontent.com/100094056/193431783-90d63613-5928-450c-a24a-9ffd0606ca0c.JPG)

## How the machine works
Marbles are released on top of the utmost track to roll down to a secondary track with a locking gate, the gate by default is closed, and there is an infrared sensor below it. Infrared sensors functions on the premise of measuring the amount of infrared light being reflected off nearby surfaces (infrared sensors return their values as a variable indicating greyscale, this means that the sensor does not see in color but instead the ratio of detected reflected light); the amount of infrared light is reflected from the surface will change depending on the color of the surface and the ambient lighting conditions. Different colors will reflect the different ranges of infrared; taking this premise into account, it is possible to associate the three colors of marbles with their respective sensor greyscale ranges. 

During option, the marble gate will remain closed until a marble of one of the recognized colors rolls down the track and is stopped by the gate; the infrared sensor reads the color within the thresholds of the marble's color, and the sorting tray shift into correct color position and the gate opens releasing the marble into the correct, prealigned receptacle. The gate closes, and the process repeats when the sensor autodetects another marble. The microcontroller that runs the sorting robot will run into perpetuity until power is cycled off; there is no programmatic/logical limit to its operation. 

## Demonstration Video:
[Marble Sorting Machine Demonstration](https://youtu.be/pG1oyW3Acg8)

## Photo Album
  * [Project Image Directory](https://github.com/Austin-Daigle/Vex-Automatic-Marble-Sorting-Robot/tree/main/ProjectPhotos)
  * [Google Photo Album](https://photos.app.goo.gl/zmqFyDaRjab8gpZy7)


## Final Script Source Code (Uncompiled RobotC)
[Marble Sorter Program Version 2.0.c](https://github.com/Austin-Daigle/Vex-Automatic-Marble-Sorting-Robot/blob/main/Marble%20Sorter%20Program%20Version%202.0.c)

## Development Code
This script was written to assist in developing the final automation program. This program just illuminates a LED bulb for the detected color from the infrared sensor.  
[Marble Color Detection Script.c](https://github.com/Austin-Daigle/Vex-Automatic-Marble-Sorting-Robot/blob/main/Marble%20Color%20Detection%20script%20Concept.c)

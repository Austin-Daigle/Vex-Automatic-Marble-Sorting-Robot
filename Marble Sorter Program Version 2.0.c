#pragma config(Sensor, in1,    colorDector,    sensorLineFollower)
#pragma config(Sensor, dgtl1,  detectA,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  detectB,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  detectC,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  detectD,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl5,  distanceRange,  sensorSONAR_mm)
#pragma config(Motor,  port2,           gate,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port3,           systemMotor,   tmotorVex393_MC29, openLoop)
/*	Vex Marble Sorter Program (Version 2.0)

Project Title: PLTW Lesson 3.3 Design Problem: Materials Sorter (Final Project)

Team Members:
Austin Daigle (Programmer and Lead Designer)
Keba Simelane (testing and production)
Alec Sterne		(production)
Andrew Pinckney (design and production)

Task Description:
Design, build, and Program a machine from Vex Robotics that can sort three types of marbles.

Date: 5-19-2017

Coarse: Engineering II (Second Period)

Notes about Program:
This program has been fully tested to be functional for sorting marbles in the given design.
This design does not include any devices or scripts to regulate marble intake and therefore each
marble must be entered by hand. This script can also be customized to accommodate for a hopper and/or a
forth marble category
*/

//Global System Variables
int marbleColor = 0;
int operation = 0;
int minV = 0;
int maxV = 0;
int boxV = 0;
int marblesortCount = 0;

//Turn off LED's
void clearLeds()
{
turnLEDOff(detectA);
turnLEDOff(detectB);
turnLEDOff(detectC);
turnLEDOff(detectD);
}

//Open and Close Sensor Gate
void final()
{
setServo(gate, -90);
wait(1);
setServo(gate, -125);
wait(1);
marblesortCount = marblesortCount + 1;
//Add Hopper function call HERE!
}

//Sorter function disable
void clear()
{
operation = 0;
stopMotor(systemMotor);
}

//Sorting function
void shiftBox()
{
operation = 1;
while(operation == 1)
	{
	waitUntil(operation == 1);
	if(SensorValue(distanceRange) < boxV /*selected abs middle*/&& operation == 1)
		{
			motor[systemMotor] = 127; //minimum speed to opperate is 18
		}
	if(SensorValue(distanceRange) >  boxV /*selected abs middle*/&& operation == 1)
		{
			motor[systemMotor] = -127;
		}
	if(SensorValue(distanceRange) > minV /* min */&& SensorValue(distanceRange) < maxV /*max*/)
		{
		clear();
		wait(1);
		final();
		}
	}
}

//Marble Color Analysis
void analyzemarbleColor()
{
	//Marble Auto-detect Script
	wait(1);
	if(SensorValue(colorDector) > 3000 && (SensorValue(colorDector) < 3050))
		{
		marbleColor = 0;
		clearLeds();
		}
	else
	{
	//Acrylic Indicator
		if(SensorValue(colorDector) > 2780 && (SensorValue(colorDector) < 2850))
				{
				marbleColor = 1;
				turnLEDOff(detectA);
				turnLEDOff(detectB);
				turnLEDOff(detectC);
				turnLEDOff(detectD);
				turnLEDOn(detectA);
				minV = 47;
				maxV = 50;
				boxV = 49;
				shiftBox();
				}
	//Aluminum Indicator
		if(SensorValue(colorDector) > 1100 && (SensorValue(colorDector) < 1650))
				{
				marbleColor = 2;
				turnLEDOff(detectA);
				turnLEDOff(detectB);
				turnLEDOff(detectC);
				turnLEDOff(detectD);
				turnLEDOn(detectB);
				minV = 105;
				maxV = 110;
				boxV = 107;
				shiftBox();
				}
	//Wood Indicator
		if(SensorValue(colorDector) > 150  && (SensorValue(colorDector) < 160))
				{
				marbleColor = 3;
				turnLEDOff(detectA);
				turnLEDOff(detectB);
				turnLEDOff(detectC);
				turnLEDOff(detectD);
				turnLEDOn(detectC);
				minV = 163;
				maxV = 169;
				boxV = 165;
				shiftBox();
				}
	/*
	//Extra Indicator (add values and uncomment to activate the extra catagory)
		if(SensorValue(colorDector) > (insert min Value here) && (SensorValue(colorDector) < (insert max Value here) ))
				{
				marbleColor = 4;
				turnLEDOff(detectA);
				turnLEDOff(detectB);
				turnLEDOff(detectC);
				turnLEDOff(detectD);
				turnLEDOn(detectD);
				minV = 225;
				maxV = 237;
				boxV = 231;
				shiftBox();
				}
			*/
	}
}
//Primary Loop
task main()
{
clearLeds();
setServo(gate, -123);
while(true)
	{
	analyzemarbleColor();
	}
}

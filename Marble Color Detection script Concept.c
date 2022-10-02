#pragma config(Sensor, in1,    colorSensor,    sensorLineFollower)
#pragma config(Sensor, dgtl1,  acrylicLed,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  aluminumLed,    sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  woodLed,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  gateLed,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  hopper,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  gate,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, sort1,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, sort2,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, sort3,          sensorLEDtoVCC)
#pragma config(Motor,  port5,           gateMotor,     tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int marbleColor = 0;


//Clear LED's uppon startup
void clearLeds()
{
turnLEDOff(acrylicLed);
turnLEDOff(aluminumLed);
turnLEDOff(woodLed);
turnLEDOff(sort1);
turnLEDOff(sort2);
turnLEDOff(sort3);
turnLEDOff(hopper);
}

//dispence marble from hopper
void dispencenewMarble()
{
turnLEDOn(hopper);
wait(1);
turnLEDOff(hopper);
}

//dispence marble from hopper
void cleargate()
{
turnLEDOn(gate);
wait(1);
turnLEDOff(gate);
}


//Execute sort
void executeSort()
{
if(marbleColor == 1)
	{
	turnLEDOn(sort1);
	wait(1);
	cleargate();
	dispencenewMarble();

	}
if(marbleColor == 2)
	{
	turnLEDOn(sort2);
	wait(1);
	dispencenewMarble();
	}
if(marbleColor == 3)
	{
	turnLEDOn(sort3);
	wait(1);
	dispencenewMarble();
	}
}


void colorAnalysis()
{
//clear color variable
marbleColor = 0;

//Acrylic	Indicator
	if(SensorValue(colorSensor) > 2810 && (SensorValue(colorSensor) < 2899))
			{
			marbleColor = 1;
			turnLEDOn(acrylicLed);
			wait(2);
			executeSort();
			}
/*	else
			{
			turnLEDOff(acrylicLed);
			}*/
//Aluminum Indicator
	if(SensorValue(colorSensor) > 1220 && (SensorValue(colorSensor) < 1510))
			{
			marbleColor = 2;
			turnLEDOn(aluminumLed);
			wait(2);
			executeSort();
			}
/*	else
			{
			turnLEDOff(aluminumLed);
			} */
//Wood Indicator
	if(SensorValue(colorSensor) > 130 && (SensorValue(colorSensor) < 190))
			{
			marbleColor = 3;
			turnLEDOn(woodLed);
			wait(2);
			executeSort();
			}
/*	else
			{
			turnLEDOff(woodLed);
			} */
}







task main()
{
clearLeds();
wait(2);
while(true)
	{
	clearLeds();
	colorAnalysis();
	}
}

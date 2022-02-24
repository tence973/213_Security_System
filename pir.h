#ifndef PIR_H
#define PIR_H
const int sensor = 21;              // sensor pin, make CONSTANT?
const int state = LOW;             // by default, no motion detected

void sensorSetup();
int motionTrigger();

#endif

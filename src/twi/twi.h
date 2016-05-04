
#ifndef ComputerAided_twi_h
#define ComputerAided_twi_h

void twiEnable();


void twiStart();


void twiStop();


void twiSend();


uint8_t readACK();


uint8_t readNoAck();


void waitForTWIComplete();


#endif

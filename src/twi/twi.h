
#ifndef ComputerAided_twi_h
#define ComputerAided_twi_h

void twiEnable(void); //Enables TWI on the AVR


void twiDisable(void); // Disables TWI on the AVR


void twiStart(void); // Sends Start Condition


void twiStop(void); // Sends Stop Condition


void twiSend(uint8_t data); // Loads Data, Sends it


uint8_t readACK(void); // Reads in from Slave, sends ACK when done


uint8_t readNoAck(void); // Reads in from slave, sends NOACK when Done


void waitForTWIComplete(void); // Waits until complete


#endif

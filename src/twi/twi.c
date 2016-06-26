/********************************************************
twi.c

By: Kenny H.
Created: 5.3.2016
https://github.com/ComputerAided/avrlib

TWI (I2C) Library for the ATMega328

Distributed as-is; NO WARRANTY IS GIVEN
********************************************************/

#include "ComputerAidedTWI.h"


void twiEnable(void) { //Enables TWI on the AVR
  TWBR = 32; //set bit rate pg 212.
             //8MHz / (16-2(TWBR)*1
  TWCR |= (1 << TWEN);
}

void twiDisable(void) { // Disables TWI on the AVR
  TWCR &= ~(1 << TWEN);
  
  TWBR &= 0x00;
}

void twiStart(void) { // Sends Start Condition
 TWCR = ((1 << TWINT) | (1 << TWEN) | (1 << TWSTA));
 waitForTWIComplete();
}

void twiStop(void) { // Sends Stop Condition
  TWCR = ((1 << TWINT) | (1 << TWEN) | (1 << TWSTO));
  waitForTWIComplete();
}

void twiSend(uint8_t data) { // Loads Data, Sends it
  TWDR = data;
  TWCR = ((1 << TWINT) | (1 << TWEN));
}

uint8_t readACK(void){ // Reads in from Slave, sends ACK when done
  TWCR = ((1 << TWINT) | (1 << TWEN) | (1 << TWEA));
  waitForTWIComplete();
  return(TWDR);
}
uint8_t readNoAck(void){ // Reads in from slave, sends NOACK when Done
  TWCR = ((1 << TWINT) | (1 << TWEN));
  waitForTWIComplete();
  return (TWDR);
  
void waitForTWIComplete (void) { // Waits until complete
  loop_until_bit_is_set(TWCR, TWINT);
}

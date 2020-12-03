#include <tm4c123gh6pm.h>
#include <stdio.h>
//1st 7 digit display
void zero(void){
  GPIO_PORTD_DATA_R = 0x07;
  GPIO_PORTE_DATA_R = 0x07;
}

void one(void){
  GPIO_PORTD_DATA_R = 0x04;
  GPIO_PORTE_DATA_R = 0x02;
}

void two(void){
  GPIO_PORTD_DATA_R = 0x0D;
  GPIO_PORTE_DATA_R = 0x05;
}

void three(void){
  GPIO_PORTD_DATA_R = 0x0D;
  GPIO_PORTE_DATA_R = 0x06;
}

void four(void){
  GPIO_PORTD_DATA_R = 0x0E;
  GPIO_PORTE_DATA_R = 0x02;
}

void five(void){
  GPIO_PORTD_DATA_R = 0x0B;
  GPIO_PORTE_DATA_R = 0x06;
}

void six(void){
  GPIO_PORTD_DATA_R = 0x0B;
  GPIO_PORTE_DATA_R = 0x07;
}

void seven(void){
  GPIO_PORTD_DATA_R = 0x05;
  GPIO_PORTE_DATA_R = 0x02;
}

void eight(void){
  GPIO_PORTD_DATA_R = 0x0F;
  GPIO_PORTE_DATA_R = 0x07;
}

void nine(void){
  GPIO_PORTD_DATA_R = 0x0F;
  GPIO_PORTE_DATA_R = 0x06;
}

//2nd 7 digit display
void zerot(void){
  GPIO_PORTF_DATA_R = 0x07;
  GPIO_PORTB_DATA_R = 0x07;
}

void onet(void){
  GPIO_PORTF_DATA_R = 0x04;
  GPIO_PORTB_DATA_R = 0x02;
}

void twot(void){
  GPIO_PORTF_DATA_R = 0x0D;
  GPIO_PORTB_DATA_R = 0x05;
}

void threet(void){
  GPIO_PORTF_DATA_R = 0x0D;
  GPIO_PORTB_DATA_R = 0x06;
}

void fourt(void){
  GPIO_PORTF_DATA_R = 0x0E;
  GPIO_PORTB_DATA_R = 0x02;
}

void fivet(void){
  GPIO_PORTF_DATA_R = 0x0B;
  GPIO_PORTB_DATA_R = 0x06;
}

void sixt(void){
  GPIO_PORTF_DATA_R = 0x0B;
  GPIO_PORTB_DATA_R = 0x07;
}

void sevent(void){
  GPIO_PORTF_DATA_R = 0x05;
  GPIO_PORTB_DATA_R = 0x02;
}

void eightt(void){
  GPIO_PORTF_DATA_R = 0x0F;
  GPIO_PORTB_DATA_R = 0x07;
}

void ninet(void){
  GPIO_PORTF_DATA_R = 0x0F;
  GPIO_PORTB_DATA_R = 0x06;
}


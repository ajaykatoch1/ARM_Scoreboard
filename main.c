//lesson 6 experiments on Protoboard, Scoreboard using seven segment displays
#include <tm4c123gh6pm.h>
#include <stdio.h>
#include "number.h"

//function declarations/prototypes
void portD_init();
void portE_init();
void portF_init();
void portB_init();
void portA_init();
void SysTick_Init();
void SysTick_Wait10ms();
void SysTick_Wait();
//end of prototypes

int main()
{
  void (*func_ptr[10])() = {zero,one,two,three,four,five,six,seven,eight,nine}; //display 1
  void (*func_ptr2[10])() = {zerot,onet,twot,threet,fourt,fivet,sixt,sevent,eightt,ninet}; //display 2 
  int i = 0;
  int j = 0;
  SysTick_Init();
  portD_init();
  portE_init();
  portF_init();
  portB_init();
  portA_init();
  (*func_ptr[0])();
  (*func_ptr2[0])();
  while(1){
    volatile int sw1_inc = GPIO_PORTE_DATA_R & 0x20;//PE5 for display 1 increases
    volatile int sw2_dec = GPIO_PORTE_DATA_R & 0x10;//PE4 for display 1 decreases
    volatile int sw3_inc = GPIO_PORTB_DATA_R & 0x20;//PB5 for display 2 increases
    volatile int sw4_dec = GPIO_PORTB_DATA_R & 0x10;//PB4 for display 2 decreases
    volatile int reset = GPIO_PORTA_DATA_R & 0x04;//PA2 for reset button

    if(sw1_inc == 0x20 && i+1<10){
        i++;
        (*func_ptr[i])();
        SysTick_Wait10ms(20);
    }
    if(sw2_dec == 0x10 && i-1>=0){
        i--;
        (*func_ptr[i])();
        SysTick_Wait10ms(20);
    }
    if(sw3_inc == 0x20 && j+1<10){
        j++;
        (*func_ptr2[j])();
        SysTick_Wait10ms(20);
    }
    if(sw4_dec == 0x10 && j-1>=0){
        j--;
        (*func_ptr2[j])();
        SysTick_Wait10ms(20);
    }
    if(reset == 0x04){
      (*func_ptr[0])();
      (*func_ptr2[0])();
    }
    
  }
  
  return 0;
}

void portD_init(void){  
  SYSCTL_RCGCGPIO_R |= 0x08; //set clock gating in run mode for port D so clock and hardware block is working for port D
  GPIO_PORTD_DIR_R |= 0x0F; //PD0-3 is set for output
  GPIO_PORTD_DEN_R |= 0x0F; //Data enable for PD0-3
}

void portE_init(void){  
  SYSCTL_RCGCGPIO_R |= 0x10; //set clock gating in run mode for port E so clock and hardware block is working for port E
  GPIO_PORTE_DIR_R |= 0x0F; //PE0-3 is set for output
  GPIO_PORTE_DIR_R &= ~0x30; //PE4-5 is set for input
  GPIO_PORTE_DEN_R |= 0x3F; //Data enable for PE0-5
}

void portF_init(void){  
  SYSCTL_RCGCGPIO_R |= 0x20; //set clock gating in run mode for port F so clock and hardware block is working for port F
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R |= 0x0F; //PF0-3 is set for output
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_DEN_R |= 0x0F; //Data enable for PF0-3  
}

void portB_init(void){         
  SYSCTL_RCGCGPIO_R |= 0x02; //set clock gating in run mode for port B so clock and hardware block is working for port B
  GPIO_PORTB_DIR_R |= 0x0F; //PB0-3 is set for output
  GPIO_PORTB_DIR_R &= ~0x30; //PB4-5 is set for input
  GPIO_PORTB_DEN_R |= 0x3F; //Data enable for PB0-5
}

void portA_init(void){         
  SYSCTL_RCGCGPIO_R |= 0x01; //set clock gating in run mode for port A so clock and hardware block is working for port A
  GPIO_PORTA_DIR_R &= ~0x04; //set PA2 as input (reset button)
  GPIO_PORTA_DEN_R |= 0x04; //Data enable for PA2
}

void SysTick_Init(void){

  NVIC_ST_CTRL_R = 0;               // disable SysTick during setup
  NVIC_ST_CTRL_R = 0x00000005;      // enable SysTick with core clock

}

// If PLL set for 80mhz core clock then 12.5ns for each decrement from current register, else 62.5ns with stock 16mhz clock (this 62.5ns dec./16MHz clk is what is running as no PLL is currently active). 
void SysTick_Wait(unsigned int delay){

  NVIC_ST_RELOAD_R = delay-1;  // number of counts to wait
  NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0){ // waiting for count flag to go high

  }

}

// 800000*12.5ns equals 10ms, delay(user defined in func. call) * 10ms is the wait time
void SysTick_Wait10ms(unsigned int delay){

  unsigned int i;
  for(i=0; i<delay; i++){
    SysTick_Wait(160000);  // wait 10ms (adjusted for 62.5ms decrements as per 16MHZ clock)
  }

}

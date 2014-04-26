#line 1 "C:/Users/Dan/Desktop/USB/PIC Projects/Expander/expander.c"

sbit SPExpanderRST at RC0_bit;
sbit SPExpanderCS at RC1_bit;
sbit SPExpanderRST_Direction at TRISC0_bit;
sbit SPExpanderCS_Direction at TRISC1_bit;


void main() {









 OSCCON=0x6E;





 CMCON=0x07;








 ADCON0=0x02;








 ADCON1=0x0E;





 SPI1_Init();




 Expander_Init(0);

 Expander_Set_DirectionPortA(0, 0x00);
 Expander_Set_DirectionPortB(0,0xFF);


 while(1) {
 Expander_Write_PortA(0, Expander_Read_PortB(0));

 Delay_ms(100);
 }
}

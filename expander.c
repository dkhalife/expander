// Port Expander module connections
sbit  SPExpanderRST at RC0_bit;
sbit  SPExpanderCS  at RC1_bit;
sbit  SPExpanderRST_Direction at TRISC0_bit;
sbit  SPExpanderCS_Direction  at TRISC1_bit;
// End Port Expander module connections

void main() {
	//**
	//  Oscillator Configuration:
	//  0b0
	//  - 4 MHz (110)
	//  - Primary system clock (1)
	//  - Stable frequency (1)
	//  - System clock : Internal RC (10)
	//  - Total : 0b01101110
	//**
	OSCCON=0x6E;
	//**
	//  Comparator Configuration:
	//  Disable all
	//  - Total : 0b00000111;
	//**
	CMCON=0x07;
	//**
	//  A/D Configuration:
	//  0b00
	//  - Select An0 (0000)
	//  - Convertor idle (0)
	//  - A/D Convertor enabled (1)
	//  - Total : 0b00000010;
	//**
	ADCON0=0x02;
	//**
	//  A/D Configuration:
	//  0b00
	//  VRef - = VSS (0)
	//  VRef + = VDD (0)
	//  - An0 Analogue (1110)
	//  - Total : 0b00001110;
	//**
	ADCON1=0x0E;
	//**
	//  PORT Directions
	//**

	// If Port Expander Library uses SPI1 module
	SPI1_Init();                                   // Initialize SPI module used with PortExpander

	//  If Port Expander Library uses SPI2 module
	//  SPI2_Init();                                   // Initialize SPI module used with PortExpander

	Expander_Init(0);                      // Initialize Port Expander

	Expander_Set_DirectionPortA(0, 0x00);  // Set Expander's PORTA to be output
	Expander_Set_DirectionPortB(0,0xFF);   // Set Expander's PORTB to be input
	//Expander_Set_PullUpsPortB(0,0xFF);     // Set pull-ups to all of the Expander's PORTB pins

	while(1) {                             // Endless loop
		Expander_Write_PortA(0, Expander_Read_PortB(0));        // Write i to expander's PORTA
		// PORTE = Expander_Read_PortB(0);      // Read expander's PORTB and write it to LEDs
		Delay_ms(100);
	}
}
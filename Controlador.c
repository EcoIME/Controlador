#include <xc.h>
#define _XTAL_FREQ 8000000
// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Detect (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)


void setup(void)
{
    ANSEL=0;CMCON0=7;
    TRISA0=1;TRISA1=1;TRISA2=1;TRISA4=1;
    TRISC0=0;TRISC1=0;TRISC2=0;TRISC3=0;
    TRISC4=0;TRISC5=0;
    return;
}

main(void)
{
    char x=0;
    setup();
    do
    {
        Sensor:
            x=4*RA0+2*RA1+RA2;
            switch(x)
            {
                    case 1: goto Phase6;
                    case 2: goto Phase5;
                    case 3: goto Phase4;
                    case 4: goto Phase2;
                    case 5: goto Phase1;
                    case 6: goto Phase3;
                    default: goto Sensor;
            }
        Phase6:  
            PORTC=0b100111;
            __delay_us(100);
            goto Sensor;
        Phase5:
            PORTC=0b101100;
            __delay_us(100);
            goto Sensor;
        Phase4:
            PORTC=0b011110;
            __delay_us(100);
            goto Sensor;
        Phase2:
            PORTC=0b111001;
            __delay_us(100);
            goto Sensor;
        Phase1:
            PORTC=0b001011;
            __delay_us(100);
            goto Sensor;
        Phase3:
            PORTC=0b110010;
            __delay_us(100);
            goto Sensor;
    }
    while(1);
    return;
}


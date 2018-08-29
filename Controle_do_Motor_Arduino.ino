void setup()
 { 
 //..............Habilita Pull-Up............................
   MCUCR &= ~(1 << 4);  //Desabilita o 4o bit do MCUCR (PUD - Pull-up Disable)
   
   PORTB |= (1 << PORTB0); // Seta 1 no bit PORTB0, para habilitar o PU
   DDRB &= ~(1 << DDB0);  //seta o pino como Entrada
   
   PORTC |= (1 << PORTC0);
   DDRC &= ~(1 << DDC0);
   
   PORTD |= (1 << PORTD4);
   DDRD &= ~(1 << DDD4);
 //..............Desabilita Pull-Up no PB1............................
 
   DDRB |= (1 << DDB1); //seta o pino como SAIDA (eh sem PU)
   DDRB |= (1 << DDB2);
   DDRC |= (1 << DDC1);
   DDRC |= (1 << DDC2);
   DDRD |= (1 << DDD7);
   DDRD |= (1 << DDD6);
   
 
 //..............Habilita Interrupt............................
   
   PCICR |= (1 << PCIE0);  //Habilita a Interrupt do PORTB (poderia ser o PORTC ou PORTD)
   PCMSK0 |= (1 << PCINT0);  //Habilita a Intrrupt do PCINT0
   
   PCICR |= (1 << PCIE1);
   PCMSK1 |= (1 << PCINT8);
   
   PCICR |= (1 << PCIE2);
   PCMSK2 |= (1 << PCINT20);
   
   sei();  //Habilita (Global) todas as Interrupts
   

 //..............Start............................
   PORTB |= (1 << PORTB1); // PWM_A = 1;
   PORTB |= (1 << PORTB2); // SD_A = 1;
 //..........................................
 
 }
 
ISR(PCINT0_vect){  //Executa se houver mudan�a de pino
   if(PINB&(1<<PINB0)){  // PINB � o valor NO pino
      PORTB |= (1 << PORTB1); // PWM_A = 1;
      PORTD &= ~(1 << PORTD6); // SD_C = 0;
   }
   else{
      PORTB &= ~(1 << PORTB1); // PWM_A = 0;
      PORTD |= (1 << PORTD6); // SD_C = 1
   }
 }

ISR(PCINT1_vect){  //Executa se houver mudan�a de pino no PCINT1
   if(PINC&(1<<PINC0)){  // PINC � o valor NO pino
      PORTC |= (1 << PORTC1); // PWM_B = 1;
      PORTB &= ~(1 << PORTB2); // SD_A = 0;
   }
   else{
      PORTC &= ~(1 << PORTC1); //PWM_B = 0;
      PORTB |= (1 << PORTB2); // SD_A = 1;
   }
}

ISR(PCINT2_vect){  //Executa se houver mudan�a de pino no PCINT2
   if(PIND&(1<<PIND4)){  // PIND � o valor NO pino
      PORTD |= (1 << PORTD7); // PWM_C = 1;
      PORTC &= ~(1 << PORTC2); // SD_B = 0;
   }
   else{
      PORTD &= ~(1 << PORTD7); // PWM_C = 0;
      PORTC |= (1 << PORTC2); // SD_B = 1;
   }
}   
void loop()
 {

 }

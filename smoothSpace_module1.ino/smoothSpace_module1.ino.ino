/* Melody
 * (cleft) 2005 D. Cuartielles for K3
 *
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note 	frequency 	period 	timeHigh
 * c 	        261 Hz 	        3830 	1915 	
 * d 	        294 Hz 	        3400 	1700 	
 * e 	        329 Hz 	        3038 	1519 	
 * f 	        349 Hz 	        2864 	1432 	
 * g 	        392 Hz 	        2550 	1275 	
 * a 	        440 Hz 	        2272 	1136 	
 * b 	        493 Hz 	        2028	1014	
 * C	        523 Hz	        1912 	956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */

 // Define hardware connections
#define PIN_GATE_IN 2
#define IRQ_GATE_IN  0
#define PIN_LED_OUT 13
#define PIN_ANALOG_IN A0
#define PIN_SPEAKER 3

 
//LED Pin Variables
int ledPins[] = {4,5,6,7,8,9,10,11}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 100;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(PIN_SPEAKER, HIGH);
    delayMicroseconds(tone);
    digitalWrite(PIN_SPEAKER, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void soundISR()
{
  int pin_val;

  pin_val = digitalRead(PIN_GATE_IN);
  digitalWrite(PIN_LED_OUT, pin_val);   
}

void setup() {
  // Piezo
  pinMode(PIN_SPEAKER, OUTPUT);
  
  // Sound detector
  Serial.begin(9600);

  //  Configure LED pin as output
  pinMode(PIN_LED_OUT, OUTPUT);

  // configure input to interrupt
  pinMode(PIN_GATE_IN, INPUT);
  attachInterrupt(IRQ_GATE_IN, soundISR, CHANGE);

  // Display status
  Serial.println("Initialized");
  
  
  pinMode(ledPins[0],OUTPUT);
  pinMode(ledPins[1],OUTPUT);
  pinMode(ledPins[2],OUTPUT);
  pinMode(ledPins[3],OUTPUT);
  pinMode(ledPins[4],OUTPUT);
  pinMode(ledPins[5],OUTPUT);
  pinMode(ledPins[6],OUTPUT);
  pinMode(ledPins[7],OUTPUT);
  
 
}

void sing(){
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 2); 
  }
}

    

void loop() {
  int delayTime = 100;
  int value = 0;

  value = analogRead(PIN_ANALOG_IN);
  
  Serial.println(value);
  
  delay(delayTime);
  
  if ( value > 10 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2], LOW); 
      digitalWrite(ledPins[3], LOW);       
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW); 
      digitalWrite(ledPins[6], LOW);       
      digitalWrite(ledPins[7], LOW);      
      delay(delayTime);      
      }
    if ( value > 20 ){
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], LOW); 
      digitalWrite(ledPins[3], LOW);       
      digitalWrite(ledPins[4], LOW);
      digitalWrite(ledPins[5], LOW); 
      digitalWrite(ledPins[6], LOW);       
      digitalWrite(ledPins[7], LOW);      
      delay(delayTime);
      }
    if ( value > 30 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH); 
      digitalWrite(ledPins[3], LOW);       
      digitalWrite(ledPins[4], LOW); 
      digitalWrite(ledPins[5], LOW); 
      digitalWrite(ledPins[6], LOW);       
      digitalWrite(ledPins[7], LOW);     
      delay(delayTime);
      }
    if ( value > 40 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH); 
      digitalWrite(ledPins[3], HIGH);       
      digitalWrite(ledPins[4], LOW);   
      digitalWrite(ledPins[5], LOW); 
      digitalWrite(ledPins[6], LOW);       
      digitalWrite(ledPins[7], LOW);    
      delay(delayTime);
      }
    if ( value > 50 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH); 
      digitalWrite(ledPins[3], HIGH);       
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[5], LOW); 
      digitalWrite(ledPins[6], LOW);       
      digitalWrite(ledPins[7], LOW);      
      delay(delayTime);
      }
    if ( value > 60 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH); 
      digitalWrite(ledPins[3], HIGH);       
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[5], HIGH); 
      digitalWrite(ledPins[6], LOW);       
      digitalWrite(ledPins[7], LOW);      
      delay(delayTime);
      }
    if ( value > 70 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH); 
      digitalWrite(ledPins[3], HIGH);       
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[5], HIGH); 
      digitalWrite(ledPins[6], HIGH);       
      digitalWrite(ledPins[7], LOW);      
      delay(delayTime);
      }
    if ( value > 80 ) {
      digitalWrite(ledPins[0], HIGH);
      digitalWrite(ledPins[1], HIGH);
      digitalWrite(ledPins[2], HIGH); 
      digitalWrite(ledPins[3], HIGH);       
      digitalWrite(ledPins[4], HIGH);
      digitalWrite(ledPins[5], HIGH); 
      digitalWrite(ledPins[6], HIGH);       
      digitalWrite(ledPins[7], HIGH);  
      sing();    
      delay(500);      
      }      
}


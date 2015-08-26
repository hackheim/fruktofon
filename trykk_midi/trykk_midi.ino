#include <Bounce.h>

#define layout_midi 1    // This one need arduino acore hardware library
//#define layout_keyboard 1
//#define layout_joy 1


#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define D12 12
#define D13 13

#define BOUNCE_T 25
#define _C 48
#define _D 50
#define _E 52
#define _F 53
#define _G 55
#define _A 57
#define _B 59
#define _C2 60

#define DEBUG










Bounce bD2 = Bounce(D2, BOUNCE_T);
Bounce bD3 = Bounce(D3, BOUNCE_T);
Bounce bD4 = Bounce(D4, BOUNCE_T);
Bounce bD5 = Bounce(D5, BOUNCE_T);
Bounce bD6 = Bounce(D6, BOUNCE_T);
Bounce bD7 = Bounce(D7, BOUNCE_T);
Bounce bD8 = Bounce(D8, BOUNCE_T);
Bounce bD9 = Bounce(D9, BOUNCE_T);
Bounce bD10 = Bounce(D10, BOUNCE_T);
Bounce bD11 = Bounce(D11, BOUNCE_T);
Bounce bD12 = Bounce(D12, BOUNCE_T);
Bounce bA0 = Bounce(A0, BOUNCE_T);
Bounce bA1 = Bounce(A1, BOUNCE_T);
Bounce bA2 = Bounce(A2, BOUNCE_T);
Bounce bA3 = Bounce(A3, BOUNCE_T);
Bounce bA4 = Bounce(A4, BOUNCE_T);
Bounce bA5 = Bounce(A5, BOUNCE_T);

void setup() {
  // put your setup code here, to run once:
  delay(10000);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
  pinMode(D11, INPUT);
  pinMode(D12, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
  
  /*bD2.attach( D2);  bD2.interval( BOUNCE_T);
  bD3.attach( D3);  bD3.interval( BOUNCE_T);
  bD4.attach( D4);  bD4.interval( BOUNCE_T);
  bD5.attach( D5);  bD5.interval( BOUNCE_T);
  bD6.attach( D6);  bD6.interval( BOUNCE_T);
  bD7.attach( D7);  bD7.interval( BOUNCE_T);
  bD8.attach( D8);  bD8.interval( BOUNCE_T);
  bD9.attach( D9);  bD9.interval( BOUNCE_T);
  bD10.attach(D10); bD10.interval(BOUNCE_T);
  bD11.attach(D11); bD11.interval(BOUNCE_T);
  bD12.attach(D12); bD12.interval(BOUNCE_T);
  bA0.attach( A0);  bA0.interval( BOUNCE_T);
  bA1.attach( A1);  bA1.interval( BOUNCE_T);
  bA2.attach( A2);  bA2.interval( BOUNCE_T);
  bA3.attach( A3);  bA3.interval( BOUNCE_T);
  bA4.attach( A4);  bA4.interval( BOUNCE_T);
  bA5.attach( A5);  bA5.interval( BOUNCE_T);
  */
  
  
#ifdef layout_keyboard
  Keyboard.begin();
#endif

#ifdef layout_joy
  Keyboard.begin();
#endif
}

#ifdef layout_midi
// Note on, channel 0, middle C (48), normal velocity (64):
void noteOn(int note, int velo) {
  #ifdef DEBUG
  if (Serial) { Serial.print("PRESS  ");  Serial.println(note);}
  #endif
  MIDIEvent e1 = {0x09, 0x90, note, velo};
  MIDIUSB.write(e1);
  MIDIUSB.flush(); 
}

// Note off, channel 0, middle C (48), fastest velocity (127):
void noteOff(int note, int velo) {
  #ifdef DEBUG
  if (Serial) { Serial.print("RELEASE");  Serial.println(note);}
  #endif
  MIDIEvent e1 = {0x09, 0x80, note, velo};
  MIDIUSB.write(e1);
  MIDIUSB.flush(); 
}
#endif

void loop() {
  // put your main code here, to run repeatedly: 
  //Update keys
  bD2.update();
  bD3.update();
  bD4.update();
  bD5.update();
  bD6.update();
  bD7.update();
  bD8.update();
  bD9.update();
  bD10.update();
  bD11.update();
  bD12.update();
  bA0.update();
  bA1.update();
  bA2.update();
  bA3.update();
  bA4.update();
  bA5.update();

  
  //if(!digitalRead(A0))  {   debugString("A0"); delay(100); }
  
#ifdef layout_midi
  if (bD2.risingEdge())  {  noteOff(_C,127);  }
  if (bD2.fallingEdge()) {   noteOn(_C,064);  }
  if (bD3.risingEdge())  {  noteOff(_D,127);  }
  if (bD3.fallingEdge()) {   noteOn(_D,064);  }
  if (bD4.risingEdge())  {  noteOff(_E,127);  }
  if (bD4.fallingEdge()) {   noteOn(_E,064);  }
  if (bD5.risingEdge())  {  noteOff(_F,127);  }
  if (bD5.fallingEdge()) {   noteOn(_F,064);  }
  if (bD6.risingEdge())  {  noteOff(_G,127);  }
  if (bD6.fallingEdge()) {   noteOn(_G,064);  }
  if (bD7.risingEdge())  {  noteOff(_A,127);  }
  if (bD7.fallingEdge()) {   noteOn(_A,064);  }
  if (bD8.risingEdge())  {  noteOff(_B,127);  }
  if (bD8.fallingEdge()) {   noteOn(_B,064);  }
  if (bD9.risingEdge())  {  noteOff(_C2,127); }
  if (bD9.fallingEdge()) {   noteOn(_C2,064); }

#endif

#ifdef layout_keyboard
  if (bD2.risingEdge())  {  Keyboard.release( 'w' ); }
  if (bD2.fallingEdge()) {  Keyboard.press(   'w' ); }
  if (bD3.risingEdge())  {  Keyboard.release( 'a' ); }
  if (bD3.fallingEdge()) {  Keyboard.press(   'a' ); }
  if (bD4.risingEdge())  {  Keyboard.release( 's' ); }
  if (bD4.fallingEdge()) {  Keyboard.press(   's' ); }
  if (bD5.risingEdge())  {  Keyboard.release( 'd' ); }
  if (bD5.fallingEdge()) {  Keyboard.press(   'd' ); }
  if (bD6.risingEdge())  {  Keyboard.release( 'f' ); }
  if (bD6.fallingEdge()) {  Keyboard.press(   'f' ); }
  if (bD7.risingEdge())  {  Keyboard.release( 'g' ); }
  if (bD7.fallingEdge()) {  Keyboard.press(   'g' ); }
  if (bD8.risingEdge())  {  Keyboard.release( 'h' ); }
  if (bD8.fallingEdge()) {  Keyboard.press(   'h' ); }
  if (bD9.risingEdge())  {  Keyboard.release( 'j' ); }
  if (bD9.fallingEdge()) {  Keyboard.press(   'j' ); }
  if (bD10.risingEdge())  { Keyboard.release( 'q' ); }
  if (bD10.fallingEdge()) { Keyboard.press(   'q' ); }
  if (bD11.risingEdge())  { Keyboard.release( ' ' ); }
  if (bD11.fallingEdge()) { Keyboard.press(   ' ' ); }
  if (bD12.risingEdge())  { Keyboard.release( KEY_RETURN ); }
  if (bD12.fallingEdge()) { Keyboard.press(   KEY_RETURN ); }
#endif

#ifdef layout_joy
  if (bD2.risingEdge())  {  keyboard.release( KEY_UP_ARROW ); }
  if (bD2.fallingEdge()) {  keyboard.press(   KEY_UP_ARROW ); }
  if (bD3.risingEdge())  {  keyboard.release( KEY_DOWN_ARROW ); }
  if (bD3.fallingEdge()) {  keyboard.press(   KEY_DOWN_ARROW ); }
  if (bD4.risingEdge())  {  keyboard.release( KEY_LEFT_ARROW ); }
  if (bD4.fallingEdge()) {  keyboard.press(   KEY_LEFT_ARROW ); }
  if (bD5.risingEdge())  {  keyboard.release( KEY_RIGHT_ARROW ); }
  if (bD5.fallingEdge()) {  keyboard.press(   KEY_RIGHT_ARROW ); }
  if (bD6.risingEdge())  {  keyboard.release( 'A' ); }
  if (bD6.fallingEdge()) {  keyboard.press(   'A' ); }
  if (bD7.risingEdge())  {  keyboard.release( 'B' ); }
  if (bD7.fallingEdge()) {  keyboard.press(   'B' ); }
  if (bD8.risingEdge())  {  keyboard.release( KEY_ESC ); }
  if (bD8.fallingEdge()) {  keyboard.press(   KEY_ESC ); }
  if (bD9.risingEdge())  {  keyboard.release( KAY_TAB ); }
  if (bD9.fallingEdge()) {  keyboard.press(   KEY_TAB ); }
  if (bD10.risingEdge())  {  keyboard.release( " " ); }
  if (bD10.fallingEdge()) {  keyboard.press(   " " ); }
  if (bD11.risingEdge())  {  keyboard.release( KEY_RETURN ); }
  if (bD11.fallingEdge()) {  keyboard.press(   KEY_RETURN ); }
  if (bD12.risingEdge())  {  keyboard.release( KEY_RETURN ); }
  if (bD12.fallingEdge()) {  keyboard.press(   KEY_RETURN ); }
#endif
  
}

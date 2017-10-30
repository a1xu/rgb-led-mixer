#define COMMON_ANODE

// Pin assignments //
const int r = 10;
const int g = 9;
const int b = 8;
const int pot_r = A2;
const int pot_g = A1;
const int pot_b = A0;

// Initialize values //
int r_val = 0;
int g_val = 0;
int b_val = 0;
int pot_r_val = 0;
int pot_g_val = 0;
int pot_b_val = 0;
int out_r = 0;
int out_g = 0;
int out_b = 0;

void setup() {
  // Pin mode assignment //
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // Get potentiometer values //
  pot_r_val = analogRead(r);
  pot_g_val = analogRead(g);
  pot_b_val = analogRead(b);
  
  // Map potentiometer values to LED color channels //
  out_r = map(pot_r_val, 0, 1023, 0, 255);
  out_g = map(pot_g_val, 0, 1023, 0, 255);
  out_b = map(pot_b_val, 0, 1023, 0, 255);

  #ifdef COMMON_ANODE
  out_r = 255 - out_r;
  out_g = 255 - out_g;
  out_b = 255 - out_b;
  #endif
  
  // Update LED color channels //
  analogWrite(r, out_r);
  analogWrite(g, out_g);
  analogWrite(b, out_b);

  // Wait 10 ms //
  delay(10);
}

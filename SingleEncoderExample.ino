/* Rotary encoder read example */
#define ENC_1A 8
#define ENC_1B 9
#define ENC_PORT PINC
#define ENC_2A 14
#define ENC_2B 15
/*#define ENC_PORT2 PINC */
 
void setup()
{
  /* Setup encoder pins as inputs */
  pinMode(ENC_1A, INPUT);
  digitalWrite(ENC_1A, HIGH);
  pinMode(ENC_1B, INPUT);
  digitalWrite(ENC_1B, HIGH);
  Serial.begin (115200);
  Serial.println("Start");
}
 
void loop()
{
 static uint8_t counter = 0;      //this variable will be changed by encoder input
 int8_t tmpdata;
 /**/
  tmpdata = read_encoder();
  if( tmpdata ) {
    Serial.print("Counter value: ");
    Serial.println(counter, DEC);
    counter += tmpdata;
  }
}
 
/* returns change in encoder state (-1,0,1) */
int8_t read_encoder()
{
  static int8_t enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  static uint8_t old_AB = 0;
  /**/
  old_AB <<= 2;                   //remember previous state
  old_AB |= ( ENC_PORT & 0x03 );  //add current state
  return ( enc_states[( old_AB & 0x0f )]);
}

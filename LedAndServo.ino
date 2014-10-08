#include <Servo.h> 
int _ABVAR_2_step; 
int _ABVAR_1_dim;  
int _ABVAR_4_step;
int _ABVAR_3_dim;

Servo myservo;

int pos = 0;

void setup()
{
  Serial.begin(9600);
  pinMode( 11 , OUTPUT);
  pinMode( 10 , OUTPUT);
  pinMode( 9 , OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode( 5, OUTPUT);
  myservo.attach(4);

  _ABVAR_2_step = 0;
  _ABVAR_1_dim = 0;
  _ABVAR_4_step = 0;
  _ABVAR_3_dim = 0;
}

void loop()
{  
analogWrite(11 , _ABVAR_1_dim);
analogWrite(10 , _ABVAR_1_dim);
analogWrite(9 , _ABVAR_1_dim);
analogWrite(6 , _ABVAR_1_dim);
analogWrite(5 , _ABVAR_1_dim);

_ABVAR_1_dim = ( _ABVAR_1_dim + _ABVAR_2_step );
myservo.write(_ABVAR_3_dim);
_ABVAR_3_dim = _ABVAR_3_dim + _ABVAR_4_step;
delay( 36 );
if (( ( _ABVAR_1_dim ) > ( 240 ) ))
{
_ABVAR_2_step = -10 ;
}
if (( ( _ABVAR_1_dim ) < ( 10 ) ))
{
_ABVAR_2_step = 50 ;
}

if(_ABVAR_4_step > 180)
{
  _ABVAR_4_step = -10;
}

if(_ABVAR_4_step < 1)
{
  _ABVAR_4_step = 20;
}
}



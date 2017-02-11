
#include <Wire.h> //I2C
#include <RTClib.h>
#include <Time.h>

int minutes;
int seconds;
int hours;
int twelve_hours;

//boolean AMPM;
boolean PM;
int VFDhours[2];
int VFDmins[2];

  int mins1;
  int mins0;
  
  int mins;

///CHANGE TIME 
const int EDITbutton = 14;
const int HOURbutton= 15; 
const int MINbutton = 16;

boolean hoursHIT = false;
boolean minsHIT = false;
boolean editMode = false;
int hoursSET;
int minsSET;


const int numberOfTUBES = 6;
const int numberOfPinOUTs = 12; 

//pins for transistor signal - array - transposed pins 12 and 13 for prototype error
const int grid[numberOfTUBES]={
  12, 13, 11, 10, 9, 8};

int counter = 0;

//array capable of holding 6 digits WHAT TO DISPLAY
int VFDdis[numberOfTUBES];

///0, 6, 8, 2, 3, 1 , 7 , 4, 5
//transfer the above into writeable array
int VFDposWriteSeg[numberOfTUBES][numberOfPinOUTs];


//VFD ARDUINO PINS
int clk = 4;
int load = 5;
int blank = 7;
int din = 3; 


//Numerical values 
int numericalValue[10][numberOfPinOUTs] ={
  //ZERO // 0  // ZERO // !
  {
    1, 1, 1, 1, 1, 1, 0, 1, 0, 0 , 0, 0,                         }
  , 
  //ONE // 1  // ONE //!
  { 
    0, 0, 0, 1, 1, 0, 0, 0,  0, 0 , 0, 0,                       }
  ,
  //TWO // 2  // TWO //	!
  { 
    0, 1, 1, 0, 1, 1, 1, 1, 1, 0 , 0, 0,                          }
  ,
  //THREE // 3  // THREE //!
  { 
    0, 0, 1, 1, 1, 1, 1, 1, 1, 0 , 0, 0,                       }
  ,
  //FOUR // 4  // FOUR // 
  { 
    1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0,                        }
  ,
  //FIVE // 5  // FIVE // !
  { 
    1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0,                         }
  ,
  //SIX // 6  // SIX // !
  { 
    1, 1, 1, 1, 0, 1, 1, 1, 0, 0 , 0, 0,                       }
  ,
  //SEVEN // 7  // SEVEN // !
  { 
    0, 0, 0, 1, 1, 1, 0, 0, 0, 0 , 0, 0,                        }
  ,
  //EIGHT // 8  // EIGHT //!
  {
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0 , 0, 0,                     }
  ,
  //NINE // 9  // NINE //
  { 
    1, 0, 1, 1, 1, 1, 1, 0, 0, 0 , 0, 0,                      }


};

int AMPM [2][numberOfPinOUTs] ={
  ///PM
  { 
    1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,       }
  ,
  //AM
  {
    1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,       }
  ,
};

int dash [1][numberOfPinOUTs] ={
  {
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,       }

};

///may need a CHAR string empty to hold 
int rand_hour;
int timeCHARdis;
//char display time should be a divisor of 3 /// tubes divie 18 chars evenly 3 times
int CharDISParse = 0;
int CharDIScount = 0;
boolean textDIS = false;
boolean makeNewRandAM = false;


char ericIScool[24] = {'Q','E', 'R', 'I', 'C', 'Q', 'Q', 'Q', 'I', 'S','Q', 'Q', 'Q',  'R', 'E', 'A', 'L','Q',  'Q','C', 'O', 'O', 'L', 'Q' };

int space[1][numberOfPinOUTs] = {
  { 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    }
};


int char_Value[18][numberOfPinOUTs] ={
  ///A
  {
    1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,       }
  ,
  //l/c b
  {
    1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0,       }
  ,
  //C
  {
    1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,       }
  ,
  //d l/c
  {
    0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0,       }
  ,
  //E
  {
    1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0,       }
  ,
  //F
  {
    1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,       }
  ,
  //g l/c
  {
    1, 0, 1, 1, 1, 1, 1, 0, 0, 0 , 0, 0,         }
  ,
  //H
  {
    1, 1, 0, 1, 1, 0, 1, 0, 0, 0 , 0, 0,         }
  ,
    //I
  {
    0, 0, 0, 1, 1, 0, 0, 0, 0, 0 , 0, 0,         }
  ,
  //J NOT AVAILABLE
  ///K NOT AVAILABLE
    //L
  {
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0 , 0, 0,         }
  ,
    //M NOT AVAILABLE
    //n l/c
  {
    0, 1, 0, 1, 0, 0, 1, 0, 0, 0 , 0, 0,         }
  ,
    //O
  {
     1, 1, 1, 1, 1, 1, 0, 1, 0, 0 , 0, 0,         }
  ,
  //P
  { 1, 1, 0, 0, 1, 1, 1, 1, 0, 0 , 0, 0, }
  ,
    //Q NOT AVAILABLE
    //l/c r
  { 0, 1, 0, 0, 0, 0, 1, 1, 0, 0 , 0, 0, }
  ,
    //S
  { 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0,  }
  ,
  //T NOT AVAILABLE
      //U
  { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,  }
  ,
  //V NOT AVAILABLE
  ///W NOT AVAILABLE
      //X
  { 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0,  }
  ,
  // Y MAYBE 2 WORKS
 { 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 , 0, 0,   }
  
  
};

void setup(){
  //VFD
  pinMode(din, OUTPUT);
  pinMode(clk, OUTPUT); 
  pinMode(load, OUTPUT);
  pinMode(blank, OUTPUT);


  //load the grid pins
  for (int i = 0; i< sizeof(grid); i ++){
    pinMode(grid[i], OUTPUT);
    digitalWrite (grid[i], HIGH);
  }
  //Clock time change
  pinMode(EDITbutton, INPUT);
  pinMode(HOURbutton, INPUT);
  pinMode(EDITbutton, INPUT);

  //RTC
  Wire.begin();
  Wire.beginTransmission(0x68); // address DS3231
  Wire.write(0x0E); // select register
  Wire.write(0b00011100); // write register bitmap, bit 7 is /EOSC
  Wire.endTransmission();  
  rand_hour = random(1, 12);
}


void loop(){
  getTime();  
}










































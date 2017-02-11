
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}

void flashCHANGE ( ){
  minutes=minsSET;
  hours=hoursSET;
  
  byte second;
  byte MIN;
  byte HR;

  MIN = minsSET;
  HR = hoursSET;
  // sets time and date data to DS3231
  Wire.beginTransmission(0x68);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(MIN)); // set minutes
  Wire.write(decToBcd(HR)); // set hours
  Wire.endTransmission();

  hoursHIT = false;
  minsHIT = false;

  translateTIME();
  wrt();
}















///Reads and translates 

void getTime(){

  // send request to receive data starting at register 0
  Wire.beginTransmission(0x68); // 0x68 is DS3231 device address
  Wire.write((byte)0); // start at register 0
  Wire.endTransmission();
  Wire.requestFrom(0x68, 3); // request three bytes (seconds, minutes, hours)
  while(Wire.available()){ 

    seconds = Wire.read(); // get seconds
    minutes= Wire.read(); // get minutes
    hours= Wire.read();   // get hours

    seconds = (((seconds & 0b11110000)>>4)*10 + (seconds & 0b00001111)); // convert BCD to decimal
    minutes = (((minutes & 0b11110000)>>4)*10 + (minutes & 0b00001111)); // convert BCD to decimal
    hours = (((hours & 0b00100000)>>5)*20 + ((hours & 0b00010000)>>4)*10 + (hours & 0b00001111)); // convert BCD to decimal (assume 24 hour mode)

  }
  
  manualTimeChange();
  translateTIME();
  textTrue();
  
}

void translateTIME(){ 

  if (hours == 0){    
    PM = false;
    twelve_hours = 12;      
  }
  if (hours >= 12){
    PM = true;
  }
  if (hours == 12){
    twelve_hours= 12;
    PM = true;
  }
  if (hours>=13){
    twelve_hours = hours - 12;
    PM = true;
  }
  if (hours <= 11 && hours > 0){
    PM = false;
    twelve_hours = hours;
  }  
  if (hours > 24){
    hours = 0;
  }
  if (minutes>60){
    minutes = 0;
  }

    ///populate VFDhour[] from twelve-hours var
  if (twelve_hours == 10){
    VFDhours[0] = 1;
    VFDhours[1] = 0;
  }
  if (twelve_hours == 11){
    VFDhours[0] = 1;
    VFDhours[1] = 1;
  }
  if(twelve_hours == 12){
    VFDhours[0] = 1;
    VFDhours[1] = 2;
  }
  if (twelve_hours <= 9){
    VFDhours[0] = 0;
    VFDhours[1] = twelve_hours;
  }
  //minutes population
  if (minutes <= 9){
    VFDmins[0] = 0;
    VFDmins[1] = minutes;
  }

  if (minutes > 9){
    mins1 = minutes % 10;
    VFDmins[1] = mins1;
    mins0 = minutes/10;     
    VFDmins[0] = mins0;
  }

  if (textDIS == false){
  makeTIMEDisplay(); 
 
  }  
}






















void makeTIMEDisplay(){

  VFDdis[0] = VFDhours[0]; 
  VFDdis[1] = VFDhours[1];
  VFDdis[2] = 0;
  VFDdis[3] = VFDmins[0];
  VFDdis[4] = VFDmins[1]; 
  VFDdis[5] = PM;

  TranslateNums();

}

void makeCHARdisplay(){

  int passes = CharDISParse * numberOfTUBES;

  VFDdis[0] = ericIScool[0+passes]; 
  VFDdis[1] = ericIScool[1+passes]; 
  VFDdis[2] = ericIScool[2+passes]; 
  VFDdis[3] = ericIScool[3+passes]; 
  VFDdis[4] = ericIScool[4+passes]; 
  VFDdis[5] = ericIScool[5+passes]; 

  TranslateChars();      

  if (CharDIScount < 60){
    CharDIScount = CharDIScount + 1;
    wrt();
  }
  if (CharDIScount >= 60){
    CharDIScount = 0;
    CharDISParse = CharDISParse +1;
  }
  if (CharDISParse > 3){
    textDIS = false;
    CharDISParse = 0;
    rand_hour = random(1, 12);
  }
}












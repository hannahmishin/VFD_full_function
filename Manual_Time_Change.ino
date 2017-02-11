
//needs a "if over 24 hr or over 60m - reset the thing to 0)
void manualTimeChange(){

  int EDITstate = 0;
  
  int HOURstate;
  int lastHOURstate;
  
  int MINstate;
  boolean hoursHIT = false;
  boolean minsHIT = false;
  
  EDITstate = digitalRead (EDITbutton);

  while (EDITstate == HIGH){
    EDITstate = digitalRead (EDITbutton);
    editMode = true;
    HOURstate  = digitalRead (HOURbutton);
    MINstate = digitalRead (MINbutton);

    if (hoursHIT == false){   
      hoursSET = hours; 
    }
    if (HOURstate == HIGH){
      hoursHIT = true;
      hoursSET ++ ;
      if (hoursSET == 25){
        hoursSET = 0;
      }    
      delay(10);
      flashCHANGE();    
    }

    if (minsHIT == false){   
      minsSET = minutes;  
    } 
    if (MINstate == HIGH){
      minsHIT = true;
      minsSET ++ ;
      if (minsSET > 59){
        minsSET = 0;
      }
      delay(10);
      flashCHANGE();
    }  

    if(EDITstate == LOW && editMode == true) {
      editMode = false; 
    }
  }
}

































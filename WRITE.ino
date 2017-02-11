
void wrt(){

int pace;
if (editMode == true){
  pace = 40;
}
if (editMode == false){
  pace = 1;
}

  for(int i=0;i<numberOfTUBES;i++) {
    
  for(int b=0; b < numberOfPinOUTs; b++) {  
    counter = counter + 1;
    digitalWrite (din, VFDposWriteSeg[i][b]);
    digitalWrite (clk, HIGH);
    digitalWrite (clk, LOW);
  }
  digitalWrite (load, HIGH);
  digitalWrite (load, LOW);
  digitalWrite (grid[i], HIGH);
  delay(pace);
  digitalWrite (grid[i], LOW);
  digitalWrite(din, 0);
}

  if (counter > numberOfPinOUTs*numberOfTUBES){
    counter = 0;
  }
}



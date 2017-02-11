
void TranslateNums(){

  for (int j=0; j<numberOfTUBES; j++){

    if (VFDdis[j] == 0){ //are any values a "0"
      for (int i = 0; i< numberOfPinOUTs; i++){  //if so, make VFDposwriteSeg the 0 from numericalValue lib 
        VFDposWriteSeg [j][i] = numericalValue [0][i];
      } 
    }

    if (VFDdis[j] == 1){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [1][i];
      } 
    }

    if (VFDdis[j] == 2){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [2][i];
      } 
    }

    if (VFDdis[j] == 3){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [3][i];
      } 
    }

    if (VFDdis[j] == 4){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [4][i];
      } 
    }

    if (VFDdis[j] == 5){
      for (int i = 0; i< numberOfPinOUTs ; i++){   
        VFDposWriteSeg [j][i] = numericalValue [5][i];
      } 
    }

    if (VFDdis[j] == 6){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [6][i];
      } 
    }

    if (VFDdis[j] == 7){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [7][i];
      } 
    }

    if (VFDdis[j] == 8){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [8][i];
      } 
    }

    if (VFDdis[j] == 9){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = numericalValue [9][i];
      } 
    }    
  }

  if(  VFDdis[5] == 1){
    for (int i = 0; i< numberOfPinOUTs; i++){   
      VFDposWriteSeg [5][i] = AMPM[0][i];
    }
  }
  if(  VFDdis[5] == 0){
    for (int i = 0; i< numberOfPinOUTs; i++){   
      VFDposWriteSeg [5][i] = AMPM [1][i];
    }
  }

  if(VFDdis[2] == 0){
    for (int i = 0; i< numberOfPinOUTs; i++){   
      VFDposWriteSeg [2][i] = dash [0][i];
    }
  }
  wrt();
}


void TranslateChars(){
  for (int j=0; j<numberOfTUBES; j++){

    if (VFDdis[j] == 'A'){ 
      for (int i = 0; i< numberOfPinOUTs; i++){ 
        VFDposWriteSeg [j][i] = char_Value [0][i];
      } 
    }

    if (VFDdis[j] == 'B'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [1][i];
      } 
    }

    if (VFDdis[j] == 'C'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [2][i];
      } 
    }

    if (VFDdis[j] == 'D'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [3][i];
      } 
    }

    if (VFDdis[j] == 'E'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [4][i];
        // Serial.println ('writing E');
      } 
    }

    if (VFDdis[j] == 'F'){
      for (int i = 0; i< numberOfPinOUTs ; i++){   
        VFDposWriteSeg [j][i] = char_Value [5][i];
      } 
    }

    if (VFDdis[j] == 'G'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [6][i];
      } 
    }

    if (VFDdis[j] == 'H'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [7][i];    
      } 
    }

    if (VFDdis[j] == 'I'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [8][i];     
      } 
    }

    if (VFDdis[j] == 'L'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [9][i];   
      } 
    }


    if (VFDdis[j] == 'O'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [11][i];    
      } 
    }

    //Q NOT AVAILABLE
    if (VFDdis[j] == 'R'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [13][i];      
      } 
    }

    if (VFDdis[j] == 'S'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [14][i];      
      } 
    }

    //T NOT AVAILABLE
    if (VFDdis[j] == 'U'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [15][i];      
      } 
    }
    ///V NOT AVAILABLE
    //W NOT AVAILABLE

    if (VFDdis[j] == 'X'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [16][i];      
      } 
    }
    
    if (VFDdis[j] == 'Y'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = char_Value [17][i];      
      } 
    }
    
    ////Q in this code == blank tubes.
        if (VFDdis[j] == 'Q'){
      for (int i = 0; i< numberOfPinOUTs; i++){   
        VFDposWriteSeg [j][i] = space[0][i];      
      } 
    }
  }
} 









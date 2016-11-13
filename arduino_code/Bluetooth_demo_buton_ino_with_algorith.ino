#define ctsPin 5 // Pin for capactitive touch sensor
  int sayac = 0;
  int p,i = 0;
  uint32_t A[9] = {7000,7000,7000,7000,7000,7000,7000,7000,7000};
void setup() {
  Serial.begin(9600);
  pinMode(ctsPin, INPUT);
  
 
}
int criticalRule(uint32_t A[9]){
  if((A[0] > 13000) || (A[0] < 1000)){
    return 1;
  }
  else {
    return 0;
  }
}
int rule2(uint32_t A[9]){
  int i,j,p,k;
  i,j,k,p=0;
  for(i=0;i<9;i++){
    if(A[i]>7000){
      j++;
    }
    else if(A[i]<7000){
      k++;
    }
  }
  if((j==8)||(k==8)){
    p = 1;
  }
  return p;
}
int rule1(uint32_t A[9]){
  
  int i,j,k;
  for(i=0; i<3; i++){
    for(j=i+1;j<3;j++){
      if(((A[i]>11000) && (A[j]>11000)) || ((A[i]<3000) && (A[j]<3000))){
        k=1;}
        else {
          k= 0;
        }
      }
    }
    return k;
  }


void loop() {
  int ctsValue = digitalRead(ctsPin);
  if (ctsValue == HIGH){
    uint32_t ts1 = millis();
    
    Serial.println("TOUCHED,veri alindi");
    while(ctsValue == HIGH){
      ctsValue = digitalRead(ctsPin);
      Serial.println("whiledayim");
    }
     uint32_t ts2 = millis();
     p = ts2 - ts1;
   for(i=8;i>0;i--){
     A[i]=A[i-1];
   }
   A[0]= p;
     if(criticalRule(A)==1){
      Serial.println(A[0]);
      Serial.println("Critical Error");
     }
   else if(rule1(A)==1){
     Serial.println("rule1");
     Serial.println(A[0]);
      Serial.println(A[1]);
       Serial.println(A[2]);
      
       delay(2000);}
       else if (rule2 (A) == 1){
        Serial.println("rule2");
        for(i=0;i<9;i++){
          Serial.println(A[i]);
        }
       }
     
   
   Serial.println("OK");
     delay(2000);
  
  }
}


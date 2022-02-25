void alarmSetup(){
  pinMode(buzzer,OUTPUT); //initialize the buzzer pin as an output
}

void alarm(){  
  while(1)
  {
    //output a frequency
    for(i=0;i<80;i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(1);//wait for 1ms
      digitalWrite(buzzer,LOW);
      delay(1);//wait for 1ms
 }
 }

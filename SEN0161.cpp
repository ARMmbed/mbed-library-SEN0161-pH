#include "SEN0161.h"

SEN0161::SEN0161 (PinName data_pin) : _datapin(data_pin){
}

float SEN0161::get_pH(){
  float avgValue_;  //Store the average value of the sensor feedback
  float buf_[10],temp_;
  float phValue_;
    
  for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    buf_[i]=_datapin.read();
    wait_ms(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf_[i]>buf_[j])
      {
        temp_=buf_[i];
        buf_[i]=buf_[j];
        buf_[j]=temp_;
      }
    }
  }
  avgValue_ = 0.0f;
  for(int i=2;i<8;i++)       //take the average value of 6 center sample
    avgValue_ += buf_[i];
    
  phValue_= avgValue_*3.3/6.0f; //convert the analog into millivolt
  return 3.5f*phValue_;  
}
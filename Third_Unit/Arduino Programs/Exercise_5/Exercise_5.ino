void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // num1 = 40 25 85 e2
  // num2 = 46 35 50 f9

  float num1 = 2.5862966;
  float num2 = 11604.243;

  static uint8_t arr1[4] = {0};
  static uint8_t arr2[4] = {0};

  if(Serial.available()){ 
    if(Serial.read() == 's'){ // Little endian for num1
      memcpy(arr1, (uint8_t *)&num1, 4);
      Serial.write(arr1, 4);
    }
  }
  
  if(Serial.available()){
    if(Serial.read() == 'q'){ // Little endian for num2
      memcpy(arr2, (uint8_t *)&num2, 4);
      Serial.write(arr2, 4);
    }
  }

  if(Serial.available()){
    if(Serial.read() == 'k'){ // Big endian for num1
      memcpy(arr1, (uint8_t *)&num1, 4);
      for(int8_t i = 3; i >= 0; i--){
        Serial.write(arr1[i]);
      }
    }
  }

  if(Serial.available()){
    if(Serial.read() == 'p'){ // Big endian for num2
      memcpy(arr2, (uint8_t *)&num2, 4);
      for(int8_t i = 3; i >= 0; i--){
        Serial.write(arr2[i]);
      }
    }
  }
}

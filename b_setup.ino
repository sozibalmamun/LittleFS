void setup()
{
  Serial.begin(115200);


  if (!LittleFS.begin()) {
    Serial.println("LittleFS failed");
    return;
  }

  writeFile("/data_one.txt", "This is my 1st test data");
  delay(2000);
  writeFile("/data_two.txt", "This is my 2nd test data");


  
}

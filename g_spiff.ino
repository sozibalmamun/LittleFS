

void readFile(const char * path , String& fs_data) {
  Serial.printf("Reading file: %s\n", path);

  File file = LittleFS.open(path, "r");
  if (!file) {
    Serial.println("Failed to open file");
    return;
  }

  Serial.print("Read from file: ");
  while (file.available()) {
    fs_data += char(file.read());
  }
  file.close();
}
void writeFile(const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);
  File file = LittleFS.open(path, "w");
  if (!file) {
    Serial.println("Failed to open file");
    return;
  }
  if (file.print(message)) {
    Serial.print("File written");
    Serial.println(message);

  } else {
    Serial.println("Write failed");
  }
  delay(2000);
  file.close();
}

void deleteFile(const char * path) {
  Serial.printf("Deleting file: %s\n", path);
  if (LittleFS.remove(path)) {
    Serial.println("File deleted");
  } else {
    Serial.println("Delete failed");
  }
}

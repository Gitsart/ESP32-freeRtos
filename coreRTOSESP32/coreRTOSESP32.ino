#define LED 2
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (LED, OUTPUT);

  Serial.begin (115200);

  xTaskCreatePinnedToCore (loop2,"loop2", 1000, NULL, 0, NULL, 1);         //or I can write : xTaskCreatePinnedToCore(loop2,"loop2", 1000, NULL, 0, NULL, 0);
  xTaskCreatePinnedToCore(WIFi, "WIFILOOP", 1000, NULL, 0, NULL, 0);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite (LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay (1000);  // wait for a second
  digitalWrite (LED, LOW); // turn the LED off by making the voltage LOW
  delay (1000);  // wait for a second
  Serial.print("CORE:"); Serial.println(xPortGetCoreID());
}

// the loop2 function also runs forver but as a parallel task
void loop2 (void* pvParameters) {
  while (1) {
    Serial.print ("Hello");
    delay (500); // wait for half a second
    Serial.println (" World");
    delay (500); // wait for half a second
  }
}

void WIFi (void* pvParameters) {
  while(1) {
    Serial.println("WIFICORE:");Serial.println(xPortGetCoreID());
    delay(1000);
  }
}

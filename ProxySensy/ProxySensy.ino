#include <Zumo32U4.h>

// Make proxySensy object
Zumo32U4ProximitySensors proxySensy;

// Setup 
void setup() {
  // Proximity sensors initialized
  proxSensy.initThreeSensors();
  Serial.begin(9600);
  while (!Serial) {};
  Serial.println("Start!");
}

// Main loop
void loop() {

  // Read the sensors
  proxySensy.read();

  // Sensor Variables    
  int cleft_sensor = proxSensy.countsFrontWithLeftLeds();
  int left_sensor = proxSensy.countsLeftWithLeftLeds();
  int c_right_sensor = proxSensy.countsFrontWithRightLeds();
  int right_sensor = proxSensy.countsRightWithRightLeds();
  // 0 = geen obstakel
  // 6 = obstakel heel dichtbij

  // Print variable to Serial monitor
  Serial.print(left_sensor);
  Serial.print(c_left_sensor);
  Serial.print("");
  Serial.print(c_right_sensor);
  Serial.println(right_sensor);

  // Delay to stop constant updates
  delay(1000);
}

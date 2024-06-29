#include "EngineStrategy.h"
class L298N : public EngineStrategy{
  public:
  L298N(int input1, int input2, int enableA){
    in1=input1;
    in2=input2;
    enA=enableA;
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(14, pwmChannel);
    ledcWrite(pwmChannel, dutyCycle);
  };
  void moveForward(int spdForward) override {
    Serial.println("L298N move forward");
    ledcWrite(pwmChannel, spdForward);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  };
  void moveBackward(int spdBackward) override {
    Serial.println("L298N move backward");
    ledcWrite(pwmChannel, spdBackward);
    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);
  };
  void stop() override {
    Serial.println("Stoppp");
    digitalWrite(in2, LOW);
    digitalWrite(in1, LOW);
  };

  private:
    unsigned int in1;
    unsigned int in2;
    unsigned int enA;
    const int freq = 30000;
    const int pwmChannel = 3;
    const int resolution = 8;
    int dutyCycle = 0;

};
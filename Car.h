//moveForward, moveBackward, stop, turnRight, turnLeft, ledForward, brakeLightON, brakeLightOFF, headLightON, headLightOFF

#include "EngineStrategy.h"
#include "L298N.h"

class Car : public EngineStrategy {
public:
    Car() {
        currentEngine = new L298N(26, 27, 14);
    };

    void moveBackward(int spd) override {
        currentEngine->moveBackward(spd);
        brakeLightON();
    };

    void moveForward(int spd) override {
        currentEngine->moveForward(spd);
    };

    void stop() override {
        currentEngine->stop();
        brakeLightOFF();
    };

    void setupLed(unsigned int pinBrakeLED, unsigned int pinHeadLED){
      brakeLED= pinBrakeLED;
      headLED= pinHeadLED;
      pinMode(brakeLED,OUTPUT);
      pinMode(headLED,OUTPUT);
      digitalWrite(brakeLED,LOW);
      digitalWrite(headLED,LOW);
    }
    void brakeLightON(){
      digitalWrite(brakeLED,HIGH);
    }
    void brakeLightOFF(){
      digitalWrite(brakeLED,LOW);
    }
    void headLightOFF(){
      digitalWrite(headLED,LOW);
    }
    void headLightON(){
      digitalWrite(headLED,HIGH);
    }
    

private:
    EngineStrategy* currentEngine;
    unsigned int brakeLED = 19;
    unsigned int headLED = 23;
};

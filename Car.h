//moveForward, moveBackward, stop, turnRight, turnLeft, ledForward, brakeLightON, brakeLightOFF, headLightON, headLightOFF

#include "EngineStrategy.h"
#include "L298N.h"

class Car : public EngineStrategy {
public:
    Car() {
        currentEngineStrategy = new L298N(26, 27, 14);
    }

    void moveBackward(int spd) override {
        currentStrategy->moveBackward(spd);
    }

    void moveForward(int spd) override {
        currentStrategy->moveForward(spd);
    }

    void stop() override {
        currentStrategy->stop();
    }

private:
    EngineStrategy* currentEngineStrategy;
};

#ifndef ENGINE_STRATEGY_H
#define ENGINE_STRATEGY_H
class EngineStrategy {
public:
  virtual void moveForward(int spdForward) = 0;
  virtual void moveBackward(int spdBackward) = 0;
  virtual void stop() = 0;
};
#endif
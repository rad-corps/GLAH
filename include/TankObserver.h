#pragma once

class TankObserver
{
public:
  virtual ~TankObserver() {}
  virtual void OnShoot() = 0;
};
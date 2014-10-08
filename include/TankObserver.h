#pragma once

class TankObserver
{
public:
  virtual ~TankObserver() {}
  virtual void OnShoot(Vector3 pos_, float dir_) = 0;
  //virtual void OnEnemyShoot(Vector3 pos_, float dir_) = 0;
};
#pragma once

//GAME SPECIFIC
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

//TANK SPECIFIC
const float FWD_SPEED = 120.f;
const float BKWD_SPEED = 80.f;
const float ROT_SPEED = 1.f;
const float TURRET_ROT_SPEED = 1.5f;
const int TANK_SPRITE_W = 256;
const int TANK_SPRITE_H = 128;
const float RELOAD_TIME = 0.3f; //seconds

//TANK SHELL
const int SHELL_W = 128;
const int SHELL_H = 32;
const int SHELL_VELOCITY = 1500;
const int SHELLS_IN_MEMORY = 10;
const float MAX_BULLET_TIME = 3.0f;
const float SHELL_SCALAR = 0.5f;
const float SHELL_OFFSET = 140.f;

//MATH
const float PI = 3.14159265f;
#pragma once
#define VENUS_STATE_HEAD_UP			"HEAD-UP"
#define VENUS_STATE_HEAD_DOWN		"HEAD-DOWN"

const D3DXVECTOR2 VENUS_BBOX(16 * 3, 32 * 3);
const D3DXVECTOR2 VENUS_GREEN_BBOX(16 * 3, 24 * 3);
const float VENUS_HEIGHT = 32 * 3;
const int DART_OUT_TIME = 2500;
const int TIME_TO_IDLE = 800;

const float FIRE_BALL_SPEED = 0.12f;
const float DISTANCE_CAN_SHOOT = 300.0f;

const double SHOOT_FIRE_BALL_ANGLE = D3DXToRadian(45.0f);
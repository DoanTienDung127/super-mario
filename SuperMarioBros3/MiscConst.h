#pragma once
#define FIRE_BALL_NAME							"fire-ball"

#define FIRE_BALL_ANIMATION						"FIRE-BALL"

const D3DXVECTOR2 FIRE_BALL_BBOX(8 * 3, 9 * 3);

const float FIRE_BALL_SPEED = 0.3f;
const float FIRE_BALL_GRAVITY = 0.00093f *2;
const D3DXVECTOR2 FIRE_BALL_BOUNCE_FORCE		(0.0f, 0.3f);
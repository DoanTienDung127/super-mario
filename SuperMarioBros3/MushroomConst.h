#pragma once
#define MUSHROOM_EFFECT "SUPER-MUSHROOM"

#define MUSHROOM_GRAVITY 0.00093f *2
#define MUSHROOM_SPEED 0.05f*2
#define DELTA 60 // pixels
#define TIME 100
#define GROW_MAX_HEIGHT 50
const D3DXVECTOR2 MUSHROOM_BBOX(48, 48);

#define MUSHROOM_FORCE_Y 0.004f
//const float MUSHROOM_FORCE_Y = (float) DELTA / (float) TIME;
#define MUSHROOM_PUSH_FORCE 0.02f*2
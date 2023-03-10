#pragma once
#include "RedGoomba.h"
class CRedParaGoomba: public CEnemy
{
	CRedGoomba* redGoomba;
	int jumpState; // 0: Find Mario, 1: Rest, 2,3,4: Low Jump, 5: High Jump, 6: Stop
	DWORD timer;
public:
	CRedParaGoomba();
	void Init() override;
	void LoadAnimation() override;
	void Render(CCamera* cam, int alpha);
	virtual void Update(DWORD dt, CCamera* cam, CCamera* uiCam) override;
	void ChangeToGoomba();
	CRedGoomba* GetGoomba();
	void SetGoomba(CRedGoomba* goomba);
	bool IsOnGround();
	void OnDie() override;
};


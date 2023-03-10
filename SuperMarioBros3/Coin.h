#pragma once
#include "GameObject.h"
class CCoin : public CGameObject
{
	int type;
public:
	CCoin();
	void LoadAnimation();
	void Init();
	bool CanCollisionWithThisObject(LPGameObject gO, GameObjectTags tag) override;
	void OnCollisionEnter(CCollisionBox* selfCollisionBox, std::vector<CollisionEvent*> otherCollisions) override;
	void OnOverlappedEnter(CCollisionBox* selfCollisionBox, CCollisionBox* otherCollisionBox) override;
	void SetType(int type);
	int GetType();
};

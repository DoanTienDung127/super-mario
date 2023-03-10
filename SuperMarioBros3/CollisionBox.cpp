#include "CollisionBox.h"
#include "Ultis.h"
#include "Game.h"
#include "TextureManager.h"
#include "GraphicConst.h"
#include "Const.h"
#include "CollisionBoxConst.h"

CCollisionBox::CCollisionBox()
{
	distance.x = 0;
	distance.y = 0;
	localPosition.x = 0;
	localPosition.y = 0;
	name = "";
	id = -1;
	gameObject = NULL;
	sizeBox.x = 1;
	sizeBox.y = 1;
	isEnable = true;
}

CCollisionBox::~CCollisionBox()
{
}

void CCollisionBox::Render(CCamera* camera, int distance)
{
	auto pos = GetWorldPosition();

	auto tex = CTextureManager::GetInstance()->GetTexture(TEXTURE_BBOX);
	RECT bbRect;
	bbRect.left = 0;
	bbRect.top = 0;
	bbRect.right = sizeBox.x;
	bbRect.bottom = sizeBox.y;

	D3DXVECTOR2 posInCam, camPos;
	camPos = camera->GetPositionCam();

	posInCam.x = trunc(pos.x - camPos.x);
	posInCam.y = trunc(pos.y - camPos.y + COLLISIONBOX_ALPHA_COLOR);

	CGame::GetInstance()->Draw(posInCam,D3DXVECTOR2(sizeBox.x*0.5f, sizeBox.y*0.5f) ,tex, bbRect, D3DCOLOR_ARGB(COLLISIONBOX_ALPHA_COLOR,255,255,255));
}

void CCollisionBox::CollisionHandle(DWORD dt, std::vector<CollisionEvent*>& collisions, LPPhysicsBody phyBody, D3DXVECTOR2 vel, int mintx, int minty, float nx, float ny)
{
	if (nx != 0)
	{
		vel.x = -1 * Sign(vel.x) * phyBody->GetBounceForce().x;
		distance.x = -1 * Sign(distance.x) * phyBody->GetBounceForce().x * dt;
		phyBody->SetVelocity(vel);
	}
	if (ny != 0)
	{
		vel.y = -1 * Sign(vel.y) * phyBody->GetBounceForce().y;
		distance.y = -1 * Sign(distance.y) * phyBody->GetBounceForce().y * dt;
		phyBody->SetVelocity(vel);
	}
}

void CCollisionBox::SetGameObjectAttach(LPGameObject gO)
{
	this->gameObject = gO;
}

LPGameObject CCollisionBox::GetGameObjectAttach()
{
	return gameObject;
}

void CCollisionBox::SetSizeBox(D3DXVECTOR2 size)
{
	sizeBox = size;
}

D3DXVECTOR2 CCollisionBox::GetSizeBox()
{
	return sizeBox;
}

void CCollisionBox::SetPosition(D3DXVECTOR2 pos)
{
	this->localPosition = pos;
}

D3DXVECTOR2 CCollisionBox::GetPosition()
{
	return localPosition;
}

void CCollisionBox::SetDistance(D3DXVECTOR2 d)
{
	distance = d;
}

D3DXVECTOR2 CCollisionBox::GetDistance()
{
	return distance;
}

D3DXVECTOR2 CCollisionBox::GetWorldPosition()
{
	auto worldPos = gameObject->GetPosition() + localPosition;
	return worldPos;
}

bool CCollisionBox::IsEnabled()
{
	if (gameObject != NULL)
	{
		return isEnable;
	}
	else
		return false;
}

void CCollisionBox::SetEnable(bool isEnable)
{
	this->isEnable = isEnable;
}

RectF CCollisionBox::GetBoundingBox()
{
	// GetBoundingBox la lay cai box nam trong the gioi game 
	// Con boxSize la kich thuoc thoi k co toa do
	auto pos = GetWorldPosition();
	RectF r;
	r.left = pos.x - sizeBox.x*0.5f;
	r.right = pos.x + sizeBox.x*0.5f;
	r.top =  pos.y - sizeBox.y * 0.5f;
	r.bottom = pos.y + sizeBox.y * 0.5f;
	return r;
}

void CCollisionBox::SetName(std::string n)
{
	name = n;
}

std::string CCollisionBox::GetName()
{
	return name;
}

void CCollisionBox::SetId(int i)
{
	id = i;
}

int CCollisionBox::GetID()
{
	return id;
}

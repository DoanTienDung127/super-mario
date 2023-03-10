#pragma once
#include "StateMachine.h"
#include "IState.h"
#include "GameObject.h"
#include "Scene.h"

// vừa là 1 game object, vừa là 1 state machine

// Sẽ lưu các states và các objects (đại diện của state đó): Như FireMario, RacoonMario
class CGameObject;
typedef CGameObject* LPGameObject;

class CScene;
typedef CScene* LPScene;

class CMarioController: public CStateMachine, public CGameObject
{
private:
	std::unordered_map<std::string, IState*> listMarioStates;
	std::unordered_map<std::string, LPGameObject> listStateObjects;
	LPGameObject currentStateObject;
public:
	CMarioController();
	void Init() override;
	void Process() override;
	void AddStateObjectsToScene(LPScene scene);
	void SwitchToState(std::string state);
	void OnKeyDown(int KeyCode) override;
	void Update(DWORD dt, CCamera* cam, CCamera* uiCam) override;

	void SetCurrentStateObject(LPGameObject gO);
	LPGameObject GetCurrentStateObject();
	~CMarioController();
};


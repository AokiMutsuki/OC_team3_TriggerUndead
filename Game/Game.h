#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class FPSCamera;
class Stage;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	Player* m_player;
	FPSCamera* m_fpscamera;
	Stage* m_stage;
	SkyCube* m_skyCube;
};


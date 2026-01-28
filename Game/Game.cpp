#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "FPSCamera.h"
#include "Stage.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "player");
	m_fpscamera = NewGO<FPSCamera>(0, "FPSCamera");
	m_stage = NewGO<Stage>(0, "stage");

}

Game::~Game()
{

}

bool Game::Start()
{
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	return true;
}

void Game::Update()
{
	
}

void Game::Render(RenderContext& rc)
{

}
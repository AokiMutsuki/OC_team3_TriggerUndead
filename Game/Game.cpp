#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "FPSCamera.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "player");
	m_fpscamera = NewGO<FPSCamera>(0, "FPSCamera");

}

Game::~Game()
{

}

bool Game::Start()
{
	
	return true;
}

void Game::Update()
{
	
}

void Game::Render(RenderContext& rc)
{

}
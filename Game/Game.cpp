#include "stdafx.h"
#include "Game.h"
#include "Player.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "player");
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
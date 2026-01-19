#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_playerRender.Init("Assets/modelData/unityChan.tkm");
	m_characterController.Init(25.0f, 75.0f, m_position);
}

Player::~Player()
{

}

void Player::Update()
{
	Move();
	m_playerRender.Update();
}

void Player::Move()
{
    //xzの移動速度を0.0fにする。

    m_moveSpeed.x = 0.0f;

    m_moveSpeed.z = 0.0f;

    //左スティックの入力量を取得。

    Vector3 stickL;

    stickL.x = g_pad[0]->GetLStickXF();

    stickL.y = g_pad[0]->GetLStickYF();

    //移動速度にスティックの入力量を加算する。

    m_moveSpeed.x += stickL.x * 120.0f;

    m_moveSpeed.z += stickL.y * 120.0f;

    //キャラクターコントローラーを使って座標を移動させる。

    m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);

    //絵描きさんに座標を教える。

    m_playerRender.SetPosition(m_position);
}

void Player::Render(RenderContext& rc)
{
	m_playerRender.Draw(rc);
}
#include "stdafx.h"
#include "UI.h"
#include "GameCamera.h"
#include "Player.h"

namespace HP_BAR
{
	
	/// <summary>
	/// HPバーのポジション
	/// </summary>
	constexpr float UI_PLAYER_HP_BAR_POS_X = -420.0f;
	constexpr float UI_PLAYER_HP_BAR_POS_Y = -420.0f;
	constexpr float UI_PLAYER_HP_BAR_POS_Z = 0.0f;
	/// <summary>
	/// HPバーのカラー
	/// </summary>
	const Vector4 UI_PLAYER_HP_BAR_COLOR_LED = { 1.0f,0.0f,0.0f,1.0f };
	const Vector4 UI_PLAYER_HP_BAR_COLOR_GREEN = { 1.0f,1.0f,0.0f,1.0f };
	/// <summary>
	/// HPバーのスケール
	/// </summary>
	const Vector3 UI_PLAYER_HP_BAR_SCALE = { 2.0f,2.0f,2.0f };
}

namespace AMMO
{
	/// <summary>
	/// 弾マークのポジション
	/// </summary>
	constexpr float UI_AMMO_POS_X = 620.0f;
	constexpr float UI_AMMO_POS_Y = -430.0f;
	constexpr float UI_AMMO_POS_Z = 0.0f;
	/// <summary>
	/// 弾マークのスケール
	/// </summary>
	const Vector3 UI_AMMO_SCALE = { 2.0f,2.0f,2.0f };
}

namespace HP
{
	/// <summary>
	/// 体力
	/// </summary>
	constexpr float M_MINHP = 10;
}

namespace ZOMBIENUM
{
	/// <summary>
	/// 敵の数マークのポジション
	/// </summary>
	constexpr float UI_ZOMBIENUM_POS_X = -700.0f;
	constexpr float UI_ZOMBIENUM_POS_Y = -200.0f;
	constexpr float UI_ZOMBIENUM_POS_Z = 0.0f;

	/// <summary>
	/// 敵の数マーク
	/// </summary>
	const Vector3 UI_ZOMBIENUM_SCALE = { 1.15f,1.15f,1.15f };
}


UI::UI()
{
	m_playerHpBar.Init("Assets/Sprite/PlayerHp.DDS", 450,50);
	m_playerHpBar.SetPosition(Vector3(HP_BAR::UI_PLAYER_HP_BAR_POS_X, HP_BAR::UI_PLAYER_HP_BAR_POS_Y, HP_BAR::UI_PLAYER_HP_BAR_POS_Z));
	m_playerHpBar.SetScale(Vector3(HP_BAR::UI_PLAYER_HP_BAR_SCALE));

	m_playerAmmo.Init("Assets/Sprite/WhiteGun.DDS", 100, 100);
	m_playerAmmo.SetPosition(Vector3(AMMO::UI_AMMO_POS_X, AMMO::UI_AMMO_POS_Y, AMMO::UI_AMMO_POS_Z));
	m_playerAmmo.SetScale(Vector3(AMMO::UI_AMMO_SCALE));

	m_zombieNumber.Init("Assets/Sprite/White Skull.DDS", 150, 150);
	m_zombieNumber.SetPosition(Vector3(ZOMBIENUM::UI_ZOMBIENUM_POS_X, ZOMBIENUM::UI_ZOMBIENUM_POS_Y, ZOMBIENUM::UI_ZOMBIENUM_POS_Z));
	m_zombieNumber.SetScale(Vector3(ZOMBIENUM::UI_ZOMBIENUM_SCALE));



	////表示する座標を設定する。
	wchar_t buAmmo[32];
	wchar_t buReload[64];
	wchar_t buZombie[32];

	constexpr size_t kFontBufferSize = 129;
	//表示する文字の位置を指定する
	m_ammoText.SetPosition(Vector3(AMMO::UI_AMMO_POS_X + 120.0f, AMMO::UI_AMMO_POS_Y + 50, AMMO::UI_AMMO_POS_Z));
	m_ammoTextReload.SetPosition(Vector3(AMMO::UI_AMMO_POS_X - 200.0f, AMMO::UI_AMMO_POS_Y + 150, AMMO::UI_AMMO_POS_Z));
	m_ammoTextZombie.SetPosition(Vector3(ZOMBIENUM::UI_ZOMBIENUM_POS_X + 100.0f, ZOMBIENUM::UI_ZOMBIENUM_POS_Y, ZOMBIENUM::UI_ZOMBIENUM_POS_Z));
	////表示する色を設定する。
	m_ammoText.SetColor(g_vec4White);
	m_ammoTextReload.SetColor(g_vec4White);
	m_ammoTextZombie.SetColor(g_vec4White);
	//// 座標を文字列に変換   
	swprintf(buAmmo, 32, L"x20");
	swprintf(buReload, 64, L"Yボタンを押してリロード");
	swprintf(buZombie, 32, L"残り10体");
	//// テキストをセット
	m_ammoText.SetText(buAmmo);
	m_ammoTextReload.SetText(buReload);
	m_ammoTextZombie.SetText(buZombie);
	
	
}

UI::~UI()
{

}

bool UI::Start()
{
	return true;
}

void UI::Update()
{

	m_playerHpBar.Update();
	m_playerAmmo.Update();
	m_zombieNumber.Update();
}

void UI::ChangeHPbarColor()
{
	// HPが10％以下なら赤色に変更
	if (m_hp <= HP::M_MINHP)
	{
		m_playerHpBar.SetMulColor(Vector4(HP_BAR::UI_PLAYER_HP_BAR_COLOR_LED));
	}
	else
	{
		m_playerHpBar.SetMulColor(Vector4(HP_BAR::UI_PLAYER_HP_BAR_COLOR_GREEN));
	}
}

void UI::AmmoCount()
{
}

void UI::AmmoNunberText()
{ 
}

void UI::SetPosition(const Vector3& pos)
{
	m_position = pos;
	m_playerHpBar.SetPosition(pos);
	m_playerAmmo.SetPosition(pos);
	m_ammoText.SetPosition(pos);
	m_ammoTextReload.SetPosition(pos);
	m_ammoTextZombie.SetPosition(pos);
	m_zombieNumber.SetPosition(pos);

}

void UI::SetHP(float hp)
{
	m_hp = hp;  // HPを更新

	float hpgage = m_hp / m_maxhp; //0.0 ~ 0.1

	////////////ここからはHPバーの動作コード/////////////
	// HP割合に応じて横幅を縮める
	m_playerHpBar.SetScale(Vector3(HP_BAR::UI_PLAYER_HP_BAR_SCALE.x * hpgage,
		HP_BAR::UI_PLAYER_HP_BAR_SCALE.y,
		HP_BAR::UI_PLAYER_HP_BAR_SCALE.z));

	// 左端固定のための位置補正
// HPバーの幅が縮む分だけ右にずらす
	float offset = (1.0f - hpgage) * (450.0f * -2.0f) * 0.5f;

	Vector3 pos = Vector3(HP_BAR::UI_PLAYER_HP_BAR_POS_X + offset,
		HP_BAR::UI_PLAYER_HP_BAR_POS_Y,
		HP_BAR::UI_PLAYER_HP_BAR_POS_Z);

	m_playerHpBar.SetPosition(pos);





	ChangeHPbarColor();
	m_playerHpBar.Update();


}

void UI::Render(RenderContext& rc)
{
	

	m_playerHpBar.Draw(rc);
	m_playerAmmo.Draw(rc);
	m_zombieNumber.Draw(rc);
	m_ammoText.Draw(rc);   
	m_ammoTextReload.Draw(rc);
	m_ammoTextZombie.Draw(rc);
}
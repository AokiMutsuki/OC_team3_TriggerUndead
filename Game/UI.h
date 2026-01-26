#pragma once
class UI : public IGameObject
{
public:
	UI();
	~UI();
	bool Start();
	void Update();
	void ChangeHPbarColor();
	void SetPosition(const Vector3& pos);
	void Render(RenderContext&renderContext);
	void SetHP(float hp);
	void AmmoCount();
	void AmmoNunberText();


private:

	SpriteRender m_playerHpBar;
	SpriteRender m_playerAmmo;
	SpriteRender m_zombieNumber;
	FontRender m_ammoText;
	FontRender m_ammoTextReload;
	FontRender m_ammoTextZombie;
	Vector3 m_position;

private:
	/// <summary>
	/// HPの管理
	/// </summary>
	float m_maxhp = 100;
	float m_hp = 100;
	float m_ammo = 10;

	/// <summary>
	/// Enemyの数の管理
	/// </summary>
	float m_enemyCount = 0;
	bool m_enemyenable = false;

	/// <summary>
	/// Ammoの数の管理
	/// </summary>
	float m_ammoCount = 0;
	bool m_ammoenable = false;

};


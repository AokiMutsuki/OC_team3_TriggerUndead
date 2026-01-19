#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Move();
	void Render(RenderContext& rc);

	ModelRender m_playerRender;
	Vector3 m_position;
	CharacterController m_characterController;
	Vector3 m_moveSpeed;
};


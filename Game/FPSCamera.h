#pragma once
class Player;
class FPSCamera : public IGameObject
{
	public:
		FPSCamera() {}
		~FPSCamera() {}
	bool Start();
	void Update();

	Player* m_player;
	Vector3 m_toCameraPos;

	float m_yaw = 0.0f;//¶‰E‰ñ“]
	float m_pitch = 0.0f;//ã‰º‰ñ“]B
};


#include "stdafx.h"
#include "FPSCamera.h"
#include "Player.h"

bool FPSCamera::Start()
{
	m_player = FindGO<Player>("player");

	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(25000.0f);

	m_yaw = 0.0f;
	m_pitch = 0.0f;
	return true;
}

void FPSCamera::Update()
{
	Vector3 pos = m_player->m_position;

	pos.y += 120.0f;

	float x = g_pad[0]->GetRStickXF();
	float y = g_pad[0]->GetRStickYF();

	//微小の傾きを無効にする
	if(fabs(x) < 0.05f) x = 0.0f;
	if(fabs(y) < 0.05f) y = 0.0f;

	// カメラの回転を更新。
	m_yaw += x * 1.3f;
	m_pitch += y * 1.3f;

	// ピッチ角の制限（FPSでは必須）
	if (m_pitch > 80.0f) {
		m_pitch = 80.0f;
	}
	else if (m_pitch < -80.0f) {
		m_pitch = -80.0f;
	}

	m_player->m_rotation.y = m_yaw;

	// カメラの向きを設定。
	Quaternion qYaw;
	qYaw.SetRotationDeg(Vector3::AxisY,m_yaw);

	Quaternion qPitch;
	qPitch.SetRotationDeg(Vector3::AxisX, m_pitch);
	Quaternion qRot = qYaw * qPitch;

	//前方向
	Vector3 forward = Vector3(0.0f, 0.0f, -1.0f);
	qRot.Apply(forward);

	// カメラの位置を設定。
	g_camera3D->SetPosition(pos);
	g_camera3D->SetTarget(pos + forward);
}
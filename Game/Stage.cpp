#include "stdafx.h"
#include "Stage.h"
namespace
{
	const Vector3 POSITION = Vector3{ -4200.0f,800.0f,700.0f };
	const Vector3 SCALL    = Vector3{ 1.0f,1.0f,1.0f };
}
Stage::Stage()
{
	m_stageModelRender.Init("Assets/StageModelData/Stage.tkm");
	m_stageModelRender.SetPosition(POSITION);
	m_stageModelRender.SetScale(SCALL);
	m_stageModelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_stageModelRender.GetModel(), m_stageModelRender.GetModel().GetWorldMatrix());
}

Stage::~Stage()
{

}

void Stage::Update()
{
	
}

void Stage::Render(RenderContext& rc)
{
	m_stageModelRender.Draw(rc);
}

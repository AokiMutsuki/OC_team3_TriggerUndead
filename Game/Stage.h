#pragma once
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	void Update();
	void Render(RenderContext& rc);

	ModelRender m_stageModelRender;
	PhysicsStaticObject m_physicsStaticObject;
};


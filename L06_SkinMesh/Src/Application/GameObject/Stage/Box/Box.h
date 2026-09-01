#pragma once

class Box : public KdGameObject
{
public:
	Box() {}
	virtual ~Box()	override {}

	void Init()				override;
	void Update()			override;

	void DrawLit()			override;

private:
	std::shared_ptr<KdModelWork> m_spModel = nullptr;

	std::shared_ptr<KdAnimator>					m_spAnimator = nullptr;
};
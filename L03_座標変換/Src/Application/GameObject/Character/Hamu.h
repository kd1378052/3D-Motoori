#pragma once

class Hamu : public KdGameObject
{
public:
	Hamu();
	~Hamu()				override;

	void Init()			override;
	void Update()		override;
	void DrawLit()		override;

	void SetCamera(std::shared_ptr<KdCamera> camera)
	{
		m_wpCamera = camera;
	}
	void SetHitObject(std::shared_ptr<KdGameObject> obj)
	{
		m_wpHitObj = obj;
	}

	void DrawSprite()	override;
private:

	void Release();

	// 授業用リソース
	std::shared_ptr<KdSquarePolygon> m_spPoly = nullptr;
	//座標返還に必要なためのカメラ情報
	std::weak_ptr<KdCamera> m_wpCamera;
	std::weak_ptr<KdGameObject> m_wpHitObj;

	Math::Vector3 m_TargetPos = Math::Vector3::Zero;

};
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

	void DrawSprite()	override;
private:

	void Release();

	// 授業用リソース
	std::shared_ptr<KdSquarePolygon> m_spPoly = nullptr;
	//座標返還に必要なためのカメラ情報
	std::weak_ptr<KdCamera> m_wpCamera;


};
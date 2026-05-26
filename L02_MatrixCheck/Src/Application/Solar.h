#pragma once
class Solar
{
public:
	Solar() { Init(); }
	~Solar(){}

private:
	void Init();
	void DrawLit();
	void Release();

	std::shared_ptr<KdModelData> m_solar;

};

#pragma once
#include <DirectXMath.h>
using namespace DirectX;

class Affine_trans
{
public:
	Affine_trans();
	~Affine_trans();

	double Rad(double degree);

	void scale(XMFLOAT3& vertex, XMFLOAT3& reference_point, float expansion_rate_x, float expansion_rate_y, float expansion_rate_z);

    void translation(XMFLOAT3& vertex, float Tx, float Ty, float Tz);

    void rotate(XMFLOAT3& vertex, XMFLOAT3& reference_point, float frequency_x, float frequency_y, float frequency_z);

private:
};


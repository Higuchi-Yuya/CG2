#include "Affine_trans.h"
const double Pi = 3.141593;

Affine_trans::Affine_trans()
{
}

Affine_trans::~Affine_trans()
{
}

double Affine_trans::Rad(double degree)
{
	return degree * Pi / 180;
}

void Affine_trans::scale(XMFLOAT3& vertex, XMFLOAT3& reference_point, float expansion_rate_x, float expansion_rate_y, float expansion_rate_z)
{
	float w = 0;
	//Šg‘åk¬
	/*vertex.x -= reference_point.x;
	vertex.y -= reference_point.y;
	vertex.z -= reference_point.z;*/

	vertex.x = (vertex.x * expansion_rate_x) + (vertex.y * 0) + (0 * vertex.z) + w;
	vertex.y = (vertex.x * 0) + (vertex.y * expansion_rate_y) + (0 * vertex.z) + w;
	vertex.z = (vertex.x * 0) + (vertex.y * 0) + (vertex.z * expansion_rate_z) + w;

	/*vertex.x += reference_point.x;
	vertex.y += reference_point.y;
	vertex.z += reference_point.z;*/
}

void Affine_trans::translation(XMFLOAT3& vertex, float Tx, float Ty, float Tz)
{
	float w = 1;
	//ˆÚ“®
	vertex.x = (vertex.x * 1) + (vertex.y * 0) + (vertex.z * 0) + (Tx * w);
	vertex.y = (vertex.x * 0) + (vertex.y * 1) + (vertex.z * 0) + (Ty * w);
	vertex.z = (vertex.x * 0) + (vertex.y * 0) + (vertex.z * 1) + (Tz * w);
}

void Affine_trans::rotate(XMFLOAT3& vertex, XMFLOAT3& reference_point, float frequency_x, float frequency_y, float frequency_z)
{
	float w = 0;
	float h_x, h_y, h_z;

	//x‚Ì‰ñ“]
	/*vertex.x -= reference_point.x;
	vertex.y -= reference_point.y;
	vertex.z -= reference_point.z;*/

	h_x = vertex.x, h_y = vertex.y, h_z = vertex.z;
	vertex.x = (h_x * 1) + (h_y * 0) + (h_z * 0) + (0 * w);
	vertex.y = (h_x * 0) + (h_y * cos(Rad(frequency_x))) + (h_z * sin(Rad(frequency_x))) + (0 * w);
	vertex.z = (h_x * 0) + (h_y * -sin(Rad(frequency_x))) + (h_z * cos(Rad(frequency_x))) + (0 * w);

	/*vertex.x += reference_point.x;
	vertex.y += reference_point.y;
	vertex.z += reference_point.z;*/

	//y‚Ì‰ñ“]
	/*vertex.x -= reference_point.x;
	vertex.y -= reference_point.y;
	vertex.z -= reference_point.z;*/

	h_x = vertex.x, h_y = vertex.y, h_z = vertex.z;
	vertex.x = (h_x * cos(Rad(frequency_y))) + (h_y * 0) + (h_z * -sin(Rad(frequency_y))) + (0 * w);
	vertex.y = (h_x * 0) + (h_y * 1) + (h_z * 0) + (0 * w);
	vertex.z = (h_x * sin(Rad(frequency_y))) + (h_y * 0) + (h_z * cos(Rad(frequency_y))) + (0 * w);

	/*vertex.x += reference_point.x;
	vertex.y += reference_point.y;
	vertex.z += reference_point.z;*/


	//z‚Ì‰ñ“]
	/*vertex.x -= reference_point.x;
	vertex.y -= reference_point.y;
	vertex.z -= reference_point.z;*/

	/*h_x = vertex.x, h_y = vertex.y, h_z = vertex.z;
	vertex.x = (h_x * cos(Rad(frequency_z))) + (h_y * sin(Rad(frequency_z))) + (h_z * 0) + (0 * w);
	vertex.y = (h_x * -sin(Rad(frequency_z))) + (h_y * cos(Rad(frequency_z))) + (h_z * 0) + (0 * w);
	vertex.z = (h_x * 0) + (h_y * 0) + (h_z * 1) + (0 * w);*/

	/*vertex.x += reference_point.x;
	vertex.y += reference_point.y;
	vertex.z += reference_point.z;*/

}

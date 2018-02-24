#include "Entity.h"

namespace engine {



	//Entity::Entity(const Vec3 &position, const Quaternion &rotation, const float scale)
	//	: transform(position, rotation, scale)
	//{
	//	//m_Rotation = Quaternion(0,0,0,1);
	//}

	//Entity::Entity() : transform(Vec3(0,0,0), Quaternion(0,0,0,1), 1.0f) {

	//}

	mat4 Entity::getTransformation() {
		mat4 result(1.0f);

		result = transform.rotation.toMatrix();
	
		result[12] = transform.position.x;
		result[13] = transform.position.y;
		result[14] = transform.position.z;

		mat4 scaleMatrix(transform.scale, 0, 0, 0,
							0, transform.scale, 0, 0,
							0, 0, transform.scale, 0,
							0, 0, 0, 1);

		result = result * scaleMatrix;

		return result;
	}
}
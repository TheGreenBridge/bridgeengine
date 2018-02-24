#include "Entity.h"
#include "FollowCamera.h"


namespace engine {	namespace entity {
	FollowCamera::FollowCamera(Entity *entity) : Camera(90.0f, 1.7777f, 0.1f, 800.0f), m_pEntity(entity) {
	
	}

	FollowCamera::~FollowCamera(){

	}

	void FollowCamera::update(float dTime) {
	
		m_Position = Vec3(0, -5, -entityDistance) - m_pEntity->transform.position;
	
		Camera::update();
	}

	void calculateCameraPosition(F32 horizDistance, F32 verticDistance) {
		
	}
}}


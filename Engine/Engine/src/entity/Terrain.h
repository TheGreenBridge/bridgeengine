#pragma once

#include "../types.h"
#include "../math/Vec3.h"
#include "../math/Quaternion.h"
#include "../graphics/Model.h"
#include "../graphics/render/Loader.h"

#define TILE_SIZE 200
#define VERTICES_PER_SIDE 128
#define VERTICES_COUNT VERTICES_PER_SIDE*VERTICES_PER_SIDE

namespace engine {namespace entity {
	
	
	class Terrain {
		
	private:

		Model m_Model;
		
		U32 numIndices;
	public:
		explicit Terrain();
		~Terrain();
		void loadTerrain();
		U32 getNumIndices();

		Model &getModel();
	};
}}
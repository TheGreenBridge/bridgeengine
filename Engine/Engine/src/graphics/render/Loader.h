#pragma once

#include "../Mesh.h"
#include "../Model.h"
#include "RenderAPI.h"
#include "../../types.h"

///<summary>
///	Diese Hilfs-Klasse ist dafür da, dass Daten in den Grafik-RAM 
///	auf der Grafikkarte geladen werden. 
///</summary>

inline Model loadModel(engine::graphics::Mesh &mesh) {
	Model model;
	
	glGenVertexArrays(1, &model.vao);
	glBindVertexArray(model.vao);
	// Vertices
	glGenBuffers(3, &model.vertices);
	glBindBuffer(GL_ARRAY_BUFFER, model.vertices);
	glBufferData(GL_ARRAY_BUFFER, mesh.getVertices().size() * sizeof(Vec3), &mesh.getVertices()[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	// Normals
	glBindBuffer(GL_ARRAY_BUFFER, model.normals);
	glBufferData(GL_ARRAY_BUFFER, mesh.getNormals().size() * sizeof(Vec3), &mesh.getNormals()[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	//UV Coordinates
	glBindBuffer(GL_ARRAY_BUFFER, model.uvs);
	glBufferData(GL_ARRAY_BUFFER, mesh.getUVs().size() * sizeof(vec2), &mesh.getUVs()[0], GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	return model;
}

inline U32 loadBuffer(engine::graphics::Mesh &mesh, const U32 dimensions, const U32 attribute) {
	U32 vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mesh.getVertices().size() * sizeof(Vec3), &mesh.getVertices()[0], GL_STATIC_DRAW);
	glVertexAttribPointer(attribute, dimensions, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(attribute);
	return vbo;
}

inline U32 loadBufferf(const float * const mesh, const U32 size, const U32 dimensions, const U32 attribute) {
	U32 vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size*sizeof(float), mesh, GL_STATIC_DRAW);
	glVertexAttribPointer(attribute, dimensions, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(attribute);

	return vbo;
}

inline U32 loadIndexedBufferf(const float * const mesh, const U32 size, const U32 *indices, const U32 indicesSize) {
	// For indexed Buffer the enum must be GL_ELEMENT_ARRAY_BUFFER
	U32 vao, vbo[2];
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glGenBuffers(2, vbo);


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), mesh, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(int), indices, GL_STATIC_DRAW);
	
	glBindVertexArray(0);
	return vao;
}

inline U32 loadVAO(U32 &vbo, const float *mesh, const U32 size, const U32 dimensions, const U32 attribute) {
	U32 vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, mesh, GL_STATIC_DRAW);
	glVertexAttribPointer(attribute, dimensions, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(attribute);
	glBindVertexArray(0);
	return vao;
}
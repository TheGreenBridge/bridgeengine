

#include "Buffer.h"


Buffer::Buffer(const float *data, const unsigned int length) {
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.getVertices()), &mesh.getVertices(), GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	unbind();
	
}

Buffer::~Buffer(){}

void Buffer::bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void Buffer::unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
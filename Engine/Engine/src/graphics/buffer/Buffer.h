#pragma once

#include <gl\glew.h>


class Buffer {
private: 
	GLuint m_ID;

public:
	Buffer(const float* data, const unsigned int length);
	~Buffer();

	void bind() const;
	void unbind() const;
};
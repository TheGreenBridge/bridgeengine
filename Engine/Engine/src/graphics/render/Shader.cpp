#include "Shader.h"
#include "../../utils/Log.h"
#include <vector>
#include "../../utils/fileutils.h"
#include "RenderAPI.h"

namespace engine { namespace graphics{
	Shader::Shader(const char* vertexPath, const char* fragmentPath) : m_VertPath(vertexPath), m_FragPath(fragmentPath) {
		m_ShaderID = load();
		//LOG("Shader ID", m_ShaderID);
	}

	Shader::~Shader() {
		deleteProgram(m_ShaderID);
	}

	U32 Shader::load() {
		U32 program = createProgram();
		U32 vertex = createVertexShader();
		U32 fragment = createFragmentShader();

		std::string vertSourceString = FileUtils::read_file(m_VertPath);
		std::string fragSourceString = FileUtils::read_file(m_FragPath);

		const char *vertSource = vertSourceString.c_str();
		const char *fragSource = fragSourceString.c_str();

		// Vertex Shader
		shaderSource(vertex, 1, &vertSource, NULL);
		compileShader(vertex);

		int result;
		getShaderiv(vertex, &result);
		if (result == false) {
			int length;
			getShaderiv(vertex, &length);
			LOG("Length: ", length);
			std::vector<GLchar> error(length);
			getShaderInfoLog(vertex, length, &length, error.data());
			LOG("Failed to compile Vertex Shader. ");
			LOG(&error[0]);
			deleteShader(vertex);
			return 0;
		}

		// Fragment Shader
		shaderSource(fragment, 1, &fragSource, NULL);
		compileShader(fragment);

		getShaderiv(fragment, &result);
		if (result == false) {
			int length;
			getShaderiv(fragment, &length);
			std::vector<GLchar> error(length);
			getShaderInfoLog(fragment, length, &length, error.data());
			LOG("Failed to compile Fragment Shader. ");
			LOG(&error[0]);
			deleteShader(fragment);
			return 0;
		}

		// Erstellen des Shader Programms
		attachShader(program, vertex);
		attachShader(program, fragment);
		linkProgram(program);
		validateProgram(program);

		// Die Shader werden nicht mehr gebraucht
		deleteShader(vertex);
		deleteShader(fragment);

		return program;
	}

	void Shader::enable() const {
		useProgram(m_ShaderID);
	}

	void Shader::disable() const {
		useProgram(0);
	}


	void Shader::setUniform3f(const char* name, const Vec3 &value) const {
		GLint location = getUniformLocation(m_ShaderID, name);
		if (location == -1) { LOG("Could not find Uniform with name", name); return; }
		uniform3f(location, value.x, value.y, value.z);
	}

	void Shader::setUniformMat4(const char *name, const mat4 &matrix) const {
		GLint location = getUniformLocation(m_ShaderID, name);
		if (location == -1) { LOG("Could not find Uniform with name", name); return; }
		uniformMatrix4fv(location, matrix.elements);
	}

	void Shader::setUniformMat4Array(const char*name, const F32 *matrix) const {
		GLint location = getUniformLocation(m_ShaderID, name);
		if (location == -1) { LOG("Could not find Uniform with name", name); return; }
		glUniformMatrix4fv(location, 30, GL_FALSE, matrix);
	}

}}
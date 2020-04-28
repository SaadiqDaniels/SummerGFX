/*!
 * @author Saadiq
 * @file standard_shader
 * @date 4/27/2020
 */

#include "shader.h"
#include "mesh.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>

namespace operations::gfx {
	Shader::Shader(const char *vertex, const char *fragment) : Shader() {

		if (!vertex || !fragment)
		{
			std::cerr << "Either the vertex or fragment shader provided were nullptr" << std::endl;
			return;
		}
		GLint result;

		GLuint vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, &vertex, nullptr);
		glCompileShader(vert);
		glGetShaderiv(vert, GL_COMPILE_STATUS, &result);

		if (result != GL_TRUE)
		{
			char buffer[1024] = {0};
			glGetShaderInfoLog(vert, sizeof(buffer), nullptr, buffer);
			std::cerr << buffer << std::endl;
		}

		GLuint frag = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(frag, 1, &fragment, nullptr);
		glCompileShader(frag);
		glGetShaderiv(frag, GL_COMPILE_STATUS, &result);

		if (result != GL_TRUE)
		{
			char buffer[1024] = {0};
			glGetShaderInfoLog(frag, sizeof(buffer), nullptr, buffer);
			std::cerr << buffer << std::endl;
		}

		program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &result);

		if (result != GL_TRUE)
		{
			char buffer[1024] = {0};
			glGetProgramInfoLog(program, sizeof(buffer), nullptr, buffer);
			std::cerr << buffer << std::endl;
		}

		glDeleteShader(vert);
		glDeleteShader(frag);
	}

	Shader::Shader(const char *compute) : Shader() {
		// TODO: Implement this function
		(void) compute;
	}

	Shader::Shader() : program(0) {

	}

	Shader::~Shader() {

		if (program)
		{
			glUseProgram(0);
			glDeleteProgram(0);
		}
	}

	RV Shader::Use() {

		if (program)
		{
			glUseProgram(program);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::Unuse() {

		glUseProgram(0);
		return RV::success;
	}

	iddt Shader::FindShaderValue(const char *name) {

		iddt rv(0);
		if (program)
		{
			rv = glGetUniformLocation(program, name);
		}
		return rv;
	}

	RV Shader::SetShaderValue(iddt name, float value) {

		if (program)
		{
			glUseProgram(program);
			glUniform1f(name, value);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, int value) {

		if (program)
		{
			glUseProgram(program);
			glUniform1i(name, value);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, float *value, int num) {

		if (program)
		{
			glUseProgram(program);
			switch (num)
			{
			case 1:
				glUniform1fv(name, num, value);
				break;
			case 2:
				glUniform2fv(name, num, value);
				break;
			case 3:
				glUniform3fv(name, num, value);
				break;
			case 4:
				glUniform4fv(name, num, value);
				break;
			default:
				return RV::data_fail;
			}
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, int *value, int num) {

		if (program)
		{
			glUseProgram(program);
			switch (num)
			{
			case 1:
				glUniform1iv(name, num, value);
				break;
			case 2:
				glUniform2iv(name, num, value);
				break;
			case 3:
				glUniform3iv(name, num, value);
				break;
			case 4:
				glUniform4iv(name, num, value);
				break;
			default:
				return RV::data_fail;
			}
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, glm::vec2 &value) {

		if (program)
		{
			glUseProgram(program);
			glUniform2f(name, value.x, value.y);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, glm::vec3 &value) {

		if (program)
		{
			glUseProgram(program);
			glUniform3f(name, value.x, value.y, value.z);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, glm::vec4 &value) {

		if (program)
		{
			glUseProgram(program);
			glUniform4f(name, value.x, value.y, value.z, value.w);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, glm::mat2 &value) {

		if (program)
		{
			glUseProgram(program);
			glUniformMatrix2fv(name, 1, false, &value[0][0]);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, glm::mat3 &value) {

		if (program)
		{
			glUseProgram(program);
			glUniformMatrix3fv(name, 1, false, &value[0][0]);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::SetShaderValue(iddt name, glm::mat4 &value) {

		if (program)
		{
			glUseProgram(program);
			glUniformMatrix4fv(name, 1, false, &value[0][0]);
			return RV::success;
		}
		return RV::data_fail;
	}
}
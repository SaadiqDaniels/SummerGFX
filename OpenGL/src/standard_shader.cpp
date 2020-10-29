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

		// If there is no vertex or fragment shader provided, the shader cannot be created
		if (!vertex || !fragment)
		{
			std::cerr << "Either the vertex or fragment shader provided were nullptr" << std::endl;
			return;
		}
		// A local variable to hold temporary results
		GLint result;

		// Create and compile the vertex shader
		GLuint vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, &vertex, nullptr);
		glCompileShader(vert);
		glGetShaderiv(vert, GL_COMPILE_STATUS, &result);

		// Check for failure and print results
		if (result != GL_TRUE)
		{
			char buffer[1024] = {0};
			glGetShaderInfoLog(vert, sizeof(buffer), nullptr, buffer);
			std::cerr << buffer << std::endl;
		}

		// Create and compile the fragment shader
		GLuint frag = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(frag, 1, &fragment, nullptr);
		glCompileShader(frag);
		glGetShaderiv(frag, GL_COMPILE_STATUS, &result);

		// Check for failure and print results
		if (result != GL_TRUE)
		{
			char buffer[1024] = {0};
			glGetShaderInfoLog(frag, sizeof(buffer), nullptr, buffer);
			std::cerr << buffer << std::endl;
		}

		// Create the glProgram, attach and delete the shaders
		program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &result);

		// If the program could not be linked correctly, delete the program and print errors
		if (result != GL_TRUE)
		{
			glDeleteProgram(program);
			program = 0;
			char buffer[1024] = {0};
			glGetProgramInfoLog(program, sizeof(buffer), nullptr, buffer);
			std::cerr << buffer << std::endl;
		}

		// Delete the temp vertex and fragment shaders
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

		// If the program exists, delete it
		if (program)
		{
			glUseProgram(0);
			glDeleteProgram(program);
		}
	}

	RV Shader::Use() {

		// Use the shader program
		if (program)
		{
			glUseProgram(program);
			return RV::success;
		}
		return RV::data_fail;
	}

	RV Shader::Unuse() {

		// Unuse the shader
		glUseProgram(0);
		return RV::success;
	}

	iddt Shader::FindShaderValue(const char *name) {

		iddt rv(invalid);
		// If the shader exists, find the uniform value in the shader
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

	RV Shader::BindMesh(Mesh &mesh) const {

		// TODO: Bind the mesh
		if (program)
		{
			(void) mesh;
			return RV::success;
		}
		return RV::data_fail;
	}
}
/*!
 * @author Saadiq
 * @file shader
 * @date 4/26/2020
 */

#ifndef SUMMERGFX_SHADER_H
#define SUMMERGFX_SHADER_H

#include "defines.h"
#include <glm/glm.hpp>

namespace operations::gfx {
	class Shader {
	public:
		/*!
		 * @brief Creates a shader program out of text files
		 * @param vertex The text of the desired vertex shader to create
		 * @param fragment The text of the desired fragment shader to create
		 * @return A shader object that holds both the vertex and fragment shader
		 * @details
		 * 		It should be noted that calling this function with one string argument will create a compute shader
		 * 		instead of a regular fragment/vertex shader object
		 */
		Shader(const char *vertex, const char *fragment);

		/*!
		 * @brief Creates a compute shader out of a text file
		 * @param compute The text of the desired compute shader to create
		 * @return A shader object that holds the compute shader
		 * @details
		 * 		It should be noted that calling this function with two string arguments will create a vertex/fragment
		 * 		shader pair instead of a compute shader
		 */
		explicit Shader(const char *compute);

		/*!
		 * @brief Creates a shader object with no data
		 * @note see SwapShader() from interface.h for a potential use for a default shader
		 */
		Shader();

		/*!
		 * @brief Destructor, will delete shader object from the GPU, if the shader is still in use there may be
		 * adverse effects
		 */
		virtual ~Shader();

		/*!
		 * @brief Activates this shader program
		 * @return gfx_fail if this shader cannot be activated,
		 * data_fail if this is a default created shader
		 */
		virtual RV Use();

		/*!
		 * @brief Deactivates the shader program and no shader is selected
		 * @return gfx_fail if the shader cannot be de-selected
		 */
		virtual RV Unuse();

		/*!
		 * @brief Finds a uniform (or similar object) from a shader that can later be set
		 * @param name The name of the shader value to find
		 * @return success if the value was found,
		 * gfx_fail if the value could not be found
		 * data_fail if this is a default created shader
		 */
		virtual iddt FindShaderValue(const char *name);

		/*!
		 * @brief Sets a shader value in the program's memory
		 * @param name The name of the variable to set
		 * @param value The value to set
		 * @return data_fail if the value provided is not valid or this is a default shader,
		 * gfx_fail if the value could not be successfully set
		 */
		virtual RV SetShaderValue(iddt name, float value);

		virtual RV SetShaderValue(iddt name, int value);

		/*!
		 * @param num The number of elements in the array
		 */
		virtual RV SetShaderValue(iddt name, float *value, int num);

		virtual RV SetShaderValue(iddt name, int *value, int num);

		virtual RV SetShaderValue(iddt name, glm::vec2 &value);

		virtual RV SetShaderValue(iddt name, glm::vec3 &value);

		virtual RV SetShaderValue(iddt name, glm::vec4 &value);

		/*!
		 * @note The matrix values used in these functions are assumed to be column major, if the underlying graphics
		 * library is expecting row major, the matrix will be transposed on this library's end
		 */
		virtual RV SetShaderValue(iddt name, glm::mat2 &value);

		virtual RV SetShaderValue(iddt name, glm::mat3 &value);

		virtual RV SetShaderValue(iddt name, glm::mat4 &value);

		/*!
		 * @brief Will bind this mesh to this shader
		 * @param mesh The mesh to bind
		 * @return data_fail if the mesh values were incorrect,
		 * gfx_fail if the shader could not receive the mesh data
		 * @note There must be a variable name in the shader that corresponds to the data in the mesh, if there is a
		 * vertex array in the mesh, there must be a variable named "vertex" in the shader and so on
		 */
		RV BindMesh(Mesh &mesh) const;

	private:
#ifdef OPENGL
		iddt program;
#endif
	};
}

#endif // SUMMERGFX_SHADER_H

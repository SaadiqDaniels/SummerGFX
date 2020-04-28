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
		Shader(const char *compute);

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
		 * @brief Finds a uniform (or similar object) from a shader that can later be set
		 * @param name The name of the shader value to find
		 * @return success if the value was found, gfx_fail if the value could not be found
		 */
#ifdef GRAPHICS_BASE_CLASSES

		virtual RV FindShaderValue(const char *name);

#else
		RV FindShaderValue(const char *name);
#endif


		/*!
		 * @brief Sets a shader value in the program's memory
		 * @param name The name of the variable to set
		 * @param value The value to set
		 * @return data_fail if the value provided is not valid, gfx_fail if the value could not be successfully set
		 */
#ifdef GRAPHICS_BASE_CLASSES

		virtual RV SetShaderValue(iddt name, float value);

		virtual RV SetShaderValue(iddt name, int value);

		virtual RV SetShaderValue(iddt name, float *value);

		virtual RV SetShaderValue(iddt name, int *value);

		virtual RV SetShaderValue(iddt name, glm::vec2 &value);

		virtual RV SetShaderValue(iddt name, glm::vec3 &value);

		virtual RV SetShaderValue(iddt name, glm::vec4 &value);

		virtual RV SetShaderValue(iddt name, glm::mat2 &value);

		virtual RV SetShaderValue(iddt name, glm::mat3 &value);

		virtual RV SetShaderValue(iddt name, glm::mat4 &value);

#else

		RV SetShaderValue(iddt name, float value);

		RV SetShaderValue(iddt name, int value);

		RV SetShaderValue(iddt name, float *value);

		RV SetShaderValue(iddt name, int *value);

		RV SetShaderValue(iddt name, glm::vec2 &value);

		RV SetShaderValue(iddt name, glm::vec3 &value);

		RV SetShaderValue(iddt name, glm::vec4 &value);

		RV SetShaderValue(iddt name, glm::mat2 &value);

		RV SetShaderValue(iddt name, glm::mat3 &value);

		RV SetShaderValue(iddt name, glm::mat4 &value);

#endif
	};
}

#endif // SUMMERGFX_SHADER_H

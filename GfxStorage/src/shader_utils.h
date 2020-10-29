/*!
 * @author Saadiq
 * @file shader_utils
 * @date 4/28/2020
 */

#ifndef SUMMERGFX_SHADER_UTILS_H
#define SUMMERGFX_SHADER_UTILS_H

namespace data::gfx {

	/*!
	 * @brief Loads in a shader from a file
	 * @param filename The name of the file to load the shader from
	 * @return A pointer to the loaded file contents (must be freed by caller)
	 */
	const char * LoadShaderFromFile(const char * filename);
}

#endif //SUMMERGFX_SHADER_UTILS_H

/*!
 * @author Saadiq
 * @file shader_utils
 * @date 4/28/2020
 */

#include "shader_utils.h"
#include <fstream>
#include <iterator>
#include <string>
#include <cstring>

namespace data::gfx {

	const char *LoadShaderFromFile(const char *filename) {

		char *rv = nullptr;
		// Open the file
		std::ifstream file(filename);

		if (file.is_open())
		{
			// Create a string from the contents of the file
			std::string file_chars = std::string(std::istreambuf_iterator<char>(file),
				std::istreambuf_iterator<char>());
			// Create a character array to copy the string into
			rv = new char[file_chars.size() + 1]{0};
			// Copy the string into the character array
			std::strcpy(rv, file_chars.c_str());
		}
		return rv;
	}
}
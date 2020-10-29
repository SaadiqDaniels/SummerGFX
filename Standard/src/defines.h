/*!
 * @author Saadiq Daniels
 * @file defines.h
 * @date 4/26/2020
 * @brief
 */
#ifndef SUMMERGFX_DEFINES_H
#define SUMMERGFX_DEFINES_H

namespace operations {
	/*!
	 * @brief The return values for various operations functions
	 */
	enum class RV {
		success = 0, data_fail, gfx_fail,
	};
}

namespace operations::gfx {

	// The identification data type (ID Data Type)
#ifdef OPENGL
	using iddt = unsigned int;
	// Default error value for iddt
	const unsigned int invalid = -1;
#else
	using iddt = unsigned long;
	// Default error value for iddt
	const unsigned long invalid = -1;
#endif

	// Forward declarations of all operations::gfx classes
	class Camera;

	class Font;

	class Mesh;

	class NamedBuffer;

	class Renderable;

	class Shader;

	class Texture;

	class Viewport;

	class Window;

} // namespace operations::gfx

#endif // SUMMERGFX_DEFINES_H

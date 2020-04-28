/*!
 * @author Saadiq
 * @file interface
 * @date 4/26/2020
 */

#ifndef SUMMERGFX_INTERFACE_H
#define SUMMERGFX_INTERFACE_H

#include "defines.h"

namespace operations::gfx {

	/*!
	 * @brief Initializes the graphics system, this is not related to creating windows
	 * @return Success if the graphics system was set up correctly, gfx_fail if not
	 */
	RV Initialize();

	/*!
	 * @brief Shuts down the graphics system, this is not related to creating windows
	 * @return Success if the graphics system was shut down correctly, gfx_fail if not
	 */
	RV Shutdown();

	/*!
	 * @brief Will swap the underlying shader being used by the graphics library
	 * @param shader The shader to swap in
	 * @return gfx_fail if the swap could not be executed,
	 * data_fail if the shader provided was not able to be used.
	 * In either scenario the old shader was not removed from use
	 * @note If this function is called with a default constructed shader, t
	 */
	RV SwapShader(Shader &shader);

	/*!
	 * @brief Enables depth testing on the GPU
	 * @return gfx_fail if the depth buffer could not be activated correctly
	 */
	RV EnableDepthBuffer();

	/*!
	 * @brief Clears values out of the depth buffer (usually used after swapping frames)
	 * @return gfx_fail if the values could not be cleared
	 */
	RV ClearDepthBuffer();

	/*!
	 * @brief All functions and data in the forward namespace are used for forward rendering, instead of deferred
	 * rendering
	 */
	namespace forward {
		/*!
		 * @brief Different ways to draw meshes on the gpu
		 */
		enum class DrawType {
			Point, Line, Triangle, TriangleFan, TriangleStrip, Quad
		};

		/*!
		 * @brief Draws a mesh to the gpu
		 * @param mesh The mesh to draw
		 * @param type The draw type to draw with
		 * @return
		 */
		RV Draw(Mesh &mesh, DrawType type);
	}

	/*!
	 * @brief All functions and data in the deferred namespace are used for deferred rendering, instead of forward
	 * rendering
	 */
	namespace deferred {

	}
}

#endif //SUMMERGFX_INTERFACE_H

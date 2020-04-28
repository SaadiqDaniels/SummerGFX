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
	 * @brief Clears the color buffer (usually for the next frame)
	 * @param r The red variable for the new frame (between 0 and 1)
	 * @param g The green variable for the new frame (between 0 and 1)
	 * @param b The blue variable for the new frame (between 0 and 1)
	 * @return gfx_fail if the color buffer could not be cleared,
	 * data_fail if r, g, or b was less than 0 ro greater than 1
	 */
	RV ClearColorBuffer(float r = 0.f, float g = 0.f, float b = 0.f);

	/*!
	 * @brief All functions and data in the forward namespace are used for forward rendering, instead of deferred
	 * rendering
	 */
	namespace forward {

		/*!
		 * @brief Draws a mesh to the gpu
		 * @param mesh The mesh to draw
		 * @param type The draw type to draw with
		 * @return data_fail if the shader, mesh, or type is invalid,
		 * gfx_fail if the mesh could not be drawn
		 */
		RV Draw(Mesh &mesh);
	}

	/*!
	 * @brief All functions and data in the deferred namespace are used for deferred rendering, instead of forward
	 * rendering
	 */
	namespace deferred {

	}
}

#endif //SUMMERGFX_INTERFACE_H

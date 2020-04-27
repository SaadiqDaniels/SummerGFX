/*!
 * @author Saadiq
 * @file interface
 * @date 4/26/2020
 */

#ifndef SUMMERGFX_INTERFACE_H
#define SUMMERGFX_INTERFACE_H

#include <utility>
#include "defines.h"

namespace operations::gfx {
	/*!
	 * @brief An interface class to translate between general c++ and OpenGL calls
	 */
	class Interface {
	public:
		/*!
		 * @brief Initializes the graphics interface to display to a window
		 * @param win A window object to initialize the graphics system with
		 * @return If success, then the graphics system was loaded correctly,
		 * If data_fail, then the window object was not valid
		 * If gfx_fail, then the underlying graphics implementation could not initialize correctly
		 */
		static RV Initialize(Window const &win) noexcept(true);

		/*!
		 * @brief Deletes all gpu memory and shuts down the underlying graphics system
		 * @return If success, then the system de-initialized correctly
		 * If gfx_fail, then the graphics system could not gracefully exit
		 */
		static RV Shutdown() noexcept(true);

		/*!
		 * @brief Renders an renderable object according to a specific camera
		 * @param rend A renderable object to draw
		 * @param cam The camera to draw the renderable object in relation to
		 * @param vp The viewport to use along with the camera
		 * @return If success, then the object was successfully rendered,
		 * If data_fail, then the data in rend or cam was false, or assets loaded earlier were not successful
		 * If gfx_fail, the the object could not be rendered for an unknown reason
		 */
		static RV Render(Renderable const &rend, Camera const &cam) noexcept(true);

		/*!
		 * @brief Creates a buffer for deferred rendering techniques, if this function is called
		 * once, then all rendering afterwards will be deferred
		 * @param shdr The shader to use with the new buffer
		 * @return If success, then the buffer was successfully created
		 * If data_fail, then the shader could not be used and the buffer was not created
		 * If gfx_fail, then the graphics system could not create the buffer correctly
		 */
		static RV CreateRenderBuffer(Shader const &shdr);

		/*!
		 * @brief Waits for the next render-able frame to start
		 */
		static void WaitForNextFrame() noexcept(true);

		/*!
		 * @brief Loads a mesh into the gpu
		 * @param mesh The mesh to load
		 * @return An ID to refer to the mesh with, if the ID is invalid there was a failure
		 * @throws DataLoadFailure, if mesh cannot be loaded
		 */
		static iddt Load(Mesh const &mesh) noexcept(false);

		/*!
		 * @brief Loads a texture into the gpu
		 * @param tex The texture to load
		 * @return An ID to refer to the texture with
		 * @throws DataLoadFailure, if the texture cannot be loaded
		 */
		static iddt Load(Texture const &tex) noexcept(false);

		/*!
		 * @brief Loads a font into the gpu
		 * @param font The font to load
		 * @return An ID to refer to the font with
		 * @throws DataLoadFailure, if the font cannot be loaded
		 */
		static iddt Load(Font const &font) noexcept(false);

		/*!
		 * @brief Loads a shader into the gpu
		 * @param shdr The shader to load
		 * @return An ID to refer to the shader with
		 * @throws DataLoadFailure, if the shader cannot be loaded
		 */
		static iddt Load(Shader const &shdr) noexcept(false);

		/*!
		 * @brief Verifies if a mesh with a given ID is actually loaded into the gpu
		 * @param id The mesh id to verify
		 * @return If success, then the mesh is currently loaded and ready for use,
		 * if data_fail then the mesh was not loaded correctly or never loaded,
		 * if gfx_fail then the underlying graphics library did not load the mesh correctly
		 */
		static RV Verify(iddt id) noexcept(true);

		/*!
		 * @brief Unloads a resource from the gpu
		 * @param id The id of the resource to unload
		 * @return If success, then the resource was unloaded successfully
		 * If data_fail, then the resource was not loaded in the first place
		 * If gfx_fail, then the resource was loaded but is unable to be unloaded
		 */
		static RV Unload(iddt id) noexcept(true);

		/*!
		 * @brief Maps a buffer in the gpu to memory available to the cpu for direct manipulation
		 * @param id The id to map the buffer to
		 * @return A named buffer object that holds the underlying buffers in the gpu
		 * @throws IDDTFailure, if the given ID does not match any known buffers, this exception is thrown
		 */
		static NamedBuffer Map(iddt id) noexcept(false);
	};
}

#endif //SUMMERGFX_INTERFACE_H

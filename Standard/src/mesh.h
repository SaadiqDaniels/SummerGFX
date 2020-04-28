/*!
 * @author Saadiq
 * @file mesh
 * @date 4/26/2020
 */

#ifndef SUMMERGFX_MESH_H
#define SUMMERGFX_MESH_H

#include "defines.h"
#include <glm/glm.hpp>

namespace operations::gfx {
	class Mesh {
	public:
		/*!
		 * @brief The different types of arrays that can be bound
		 */
		enum class ArrayType {
			Array, Element
		};

		/*!
		 * @brief Default constructor of a mesh
		 */
		Mesh();

		/*!
		 * @brief Creates an array to bind to this mesh
		 * @param type The type of array to bind
		 * @note The last element array to be bound will have its element parameter used in Draw() calls
		 * @param arr A pointer to the array to copy
		 * @param size The size of an element of the array
		 * @param elements The number of elements in the array
		 * @return If data_fail, then the type, arr, or size variables were incorrectly entered,
		 * if gfx_fail, then the graphics system could not bind the array
		 */
#ifdef GRAPHICS_BASE_CLASSES
		virtual RV BindArray(ArrayType type, const void *arr, unsigned size, unsigned elements);
#else
		RV BindArray(ArrayType type, const void *arr, unsigned size, unsigned elements);
#endif
	};
}

#endif // SUMMERGFX_MESH_H

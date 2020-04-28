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
		friend Shader;
	public:

		/*!
		 * @brief The different types of meshes
		 */
		enum class MeshType {
			Point, Line, Triangle, TriangleFan, TriangleStrip, Quad
		};

		/*!
		 * @brief The different types of arrays that can be bound
		 */
		enum class ArrayType {
			position, face, normal, num
		};

		/*!
		 * @brief Default constructor of a mesh
		 */
		Mesh();

		/*!
		 * @brief Contructs a mesh and sets the type
		 * @param type The type of mesh that this is
		 */
		explicit Mesh(MeshType type);

		/*!
		 * @brief Default destructor, may cause adverse effects if the mesh is destructed and then is tried to be
		 * drawn with
		 */
		virtual ~Mesh();

		/*!
		 * @brief Sets the type of mesh that this is
		 * @param type The new mesh type
		 * @return gfx_fail if the mesh type could not be set correctly
		 */
		virtual RV SetType(MeshType type);

		/*!
		 * @brief Returns the type of mesh that is stored inside
		 * @return The type of mesh
		 */
		virtual MeshType GetType();

		/*!
		 * @brief Creates an array to bind to this mesh
		 * @param type The type of array to bind
		 * @note The position and normal arrays are assumed to be floats while the face array is integers
		 * @note The last face array to be bound will have its element parameter used in Draw() calls
		 * @param arr A pointer to the array to copy
		 * @param size The size of an element of the array
		 * @param elements The number of elements in the array
		 * @return If data_fail, then the type, arr, or size variables were incorrectly entered,
		 * if gfx_fail, then the graphics system could not bind the array
		 */
		virtual RV BindArray(ArrayType type, const void *arr, unsigned size, unsigned elements);

		/*!
		 * @brief This gives the ID used by the mesh
		 * @return Returns the mesh identification given by the underlying graphics implementation
		 */
		virtual iddt MeshID();

		/*!
		 * @brief Gives the size of the mesh
		 * @return The size of the mesh
		 */
		virtual unsigned size();

	private:
#ifdef OPENGL
		iddt     vert_array;
		iddt     buffers[static_cast<unsigned >(ArrayType::num)];
		unsigned face_count;
		MeshType mtype;
#endif
	};
}

#endif // SUMMERGFX_MESH_H

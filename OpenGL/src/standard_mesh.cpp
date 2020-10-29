/*!
 * @author Saadiq
 * @file standard_mesh
 * @date 4/27/2020
 */

#include "mesh.h"
#include <GL/glew.h>

namespace operations::gfx {
	Mesh::Mesh() : vert_array(0), buffers{0}, face_count(0), mtype(MeshType::Triangle) {

		// Create the vertex array object that is bound to the individual arrays
		glGenVertexArrays(1, &vert_array);
	}

	Mesh::Mesh(Mesh::MeshType type) : Mesh() {

		mtype = type;
	}

	Mesh::~Mesh() {

		// Delete all of the buffers for this mesh
		for (int i = 0; i < static_cast<int>( ArrayType::num); ++i)
		{
			if (buffers + i)
			{
				glDeleteBuffers(1, buffers + i);
			}
		}
		// Delete the vertex array object created in the constructor
		glDeleteVertexArrays(1, &vert_array);
	}

	RV Mesh::SetType(Mesh::MeshType type) {

		mtype = type;
		return RV::success;
	}

	RV Mesh::BindArray(Mesh::ArrayType type, const void *arr, unsigned size, unsigned elements) {

		// If any of these arguments are null, then you cannot create a buffer
		if (!arr || !elements || !size)
		{
			return RV::data_fail;
		}
		// If there is already a buffer in that spot, delete the old buffer
		if (buffers[static_cast<int>(type)])
		{
			glDeleteBuffers(1, buffers + static_cast<int>(type));
		}
		// Create the new buffer
		glGenBuffers(1, buffers + static_cast<int>(type));
		glBindVertexArray(vert_array);
		// Do different stuff depending on the type of buffer being created
		switch (type)
		{
		case Mesh::ArrayType::position:
		case Mesh::ArrayType::color:
		case Mesh::ArrayType::normal:
			glBindBuffer(GL_ARRAY_BUFFER, buffers[static_cast<int>(type)]);
			glBufferData(GL_ARRAY_BUFFER, size * elements, arr, GL_STATIC_DRAW);
			break;
		case Mesh::ArrayType::face:
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[static_cast<int>(type)]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * elements, arr, GL_STATIC_DRAW);
			face_count = elements;
			break;
		default:
			// If an invalid array type was given, delete the buffer and return failure
			glDeleteBuffers(1, buffers + static_cast<int>(type));
			return RV::data_fail;
		}
		glBindVertexArray(0);
		return RV::success;
	}

	iddt Mesh::MeshID() {

		// In opengl, the vertex array object is the identifier for a mesh
		return vert_array;
	}

	unsigned Mesh::size() {

		// Return the number of triangles or quads in the mesh
		return face_count;
	}
}
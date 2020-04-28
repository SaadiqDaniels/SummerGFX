/*!
 * @author Saadiq
 * @file standard_mesh
 * @date 4/27/2020
 */

#include "mesh.h"
#include <GL/glew.h>

namespace operations::gfx {
	Mesh::Mesh() : vert_array(0), buffers{0}, face_count(0) {

		glGenVertexArrays(1, &vert_array);
	}

	Mesh::Mesh(Mesh::MeshType type) : Mesh() {

		SetType(type);
	}

	Mesh::~Mesh() {

		for (int i = 0; i < static_cast<int>( ArrayType::num); ++i)
		{
			if (buffers + i)
			{
				glDeleteBuffers(1, buffers + i);
			}
		}
		glDeleteVertexArrays(1, &vert_array);
	}

	RV Mesh::SetType(Mesh::MeshType type) {

		mtype = type;
		return RV::success;
	}

	RV Mesh::BindArray(Mesh::ArrayType type, const void *arr, unsigned size, unsigned elements) {

		if (!arr || !elements || !size)
		{
			return RV::data_fail;
		}
		if (buffers[static_cast<int>(type)])
		{
			glDeleteBuffers(1, buffers + static_cast<int>(type));
		}
		glGenBuffers(1, buffers + static_cast<int>(type));
		glBindVertexArray(vert_array);
		switch (type)
		{
		case Mesh::ArrayType::position:
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
			return RV::data_fail;
		}
		glBindVertexArray(0);
		return RV::success;
	}

	iddt Mesh::MeshID() {

		return vert_array;
	}

	unsigned Mesh::size() {

		return face_count;
	}
}
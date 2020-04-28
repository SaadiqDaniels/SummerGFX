/*!
 * @author Saadiq
 * @file standard_interface
 * @date 4/27/2020
 */

#include "interface.h"
#include "shader.h"
#include "mesh.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>

namespace operations::gfx {
	RV Initialize() {

		GLenum value = glewInit();
		if (value != GLEW_OK)
		{
			std::cerr << glewGetErrorString(value) << std::endl;
			return RV::gfx_fail;
		}
		return RV::success;
	}

	RV Shutdown() {

		return RV::success;
	}

	RV EnableDepthBuffer() {

		glEnable(GL_DEPTH_TEST);
		return RV::success;
	}

	RV ClearDepthBuffer() {

		glClearDepth(1);
		glClear(GL_DEPTH_BUFFER_BIT);
		return RV::success;
	}

	RV ClearColorBuffer(float r, float g, float b) {

		if (r < 0.f || r > 1.f || g < 0.f || g > 1.f || b < 0.f || b > 1.f)
		{
			return RV::gfx_fail;
		}
		glClearColor(r, g, b, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		return RV::success;
	}

	namespace forward {

		RV Draw(Mesh &mesh) {

			glBindVertexArray(mesh.MeshID());
			switch (mesh.GetType())
			{
			case Mesh::MeshType::Point:
				glDrawElements(GL_POINTS, mesh.size(), GL_INT, nullptr);
				break;
			case Mesh::MeshType::Line:
				glDrawElements(GL_LINE, 2 * mesh.size(), GL_INT, nullptr);
				break;
			case Mesh::MeshType::Triangle:
				glDrawElements(GL_TRIANGLES, 3 * mesh.size(), GL_INT, nullptr);
				break;
			case Mesh::MeshType::TriangleFan:
				glDrawElements(GL_TRIANGLE_FAN, 3 * mesh.size(), GL_INT, nullptr);
				break;
			case Mesh::MeshType::TriangleStrip:
				glDrawElements(GL_TRIANGLE_STRIP, 3 * mesh.size(), GL_INT, nullptr);
				break;
			case Mesh::MeshType::Quad:
				glDrawElements(GL_QUADS, 4 * mesh.size(), GL_INT, nullptr);
				break;
			default:
				return RV::data_fail;
			}
			glBindVertexArray(0);
			return RV::success;
		}
	}
}
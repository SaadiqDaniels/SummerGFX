/*!
 * @author Saadiq
 * @file exception
 * @date 4/26/2020
 * @brief 
 */

#ifndef SUMMERGFX_EXCEPTION_H
#define SUMMERGFX_EXCEPTION_H

#include <stdexcept>

namespace operations::gfx {

	class exception : public std::exception {
		enum {
			mesh_load = 1, font_load, shader_load, texture_load, ID_failure,
		};
	};

	class DataLoadFailure : public exception {
	public:
		const char *err_msg;
		const int  err_code;

		DataLoadFailure(const char *what, int code) : err_msg(what), err_code(code) {
		}

		~DataLoadFailure() = default;

		const char *what() const noexcept(true) {

			return err_msg;
		}
	};

	class IDDTFailure : public exception {
	public:
		const char *err_msg;
		const int  err_code;

		IDDTFailure(const char *what, int code) : err_msg(what), err_code(code) {
		}

		~IDDTFailure() = default;

		const char *what() const noexcept(true) {

			return err_msg;
		}
	};
}

#endif //SUMMERGFX_EXCEPTION_H

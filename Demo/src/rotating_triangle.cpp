/*!
 * @author Saadiq
 * @file rotating_triangle
 * @date 4/28/2020
 */

#include "gfx.h"
#include <SDL2/SDL.h>
#include <iostream>

int main() {

	// Required for WSL to display the window properly
	setenv("DISPLAY", "127.0.0.1:0", true);

	int width = 1000, height = 1000;
#ifdef OPENGL
	SDL_WindowFlags gfx_flag = SDL_WINDOW_OPENGL;
#endif
	SDL_Window *window = SDL_CreateWindow("Rotating Triangle Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, gfx_flag | SDL_WINDOW_RESIZABLE);
#ifdef OPENGL
	SDL_GLContext context = SDL_GL_CreateContext(window);
#endif

	if (operations::gfx::Initialize() != operations::RV::success)
	{
		std::cerr << "The graphics system could not initiialize" << std::endl;
#ifdef OPENGL
		SDL_GL_DeleteContext(context);
		SDL_Quit();
#endif
		return 1;
	}
	operations::gfx::EnableDepthBuffer();

	while (true)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				goto quit;
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					goto quit;
				}
			default:
				break;
			}
		}

		operations::gfx::ClearDepthBuffer();
		operations::gfx::ClearColorBuffer(.2f, 0.f, .2f);

		// TODO: Draw triangle

#ifdef OPENGL
		SDL_GL_SwapWindow(window);
#endif
	}
quit:
	operations::gfx::Shutdown();
#ifdef OPENGL
	SDL_GL_DeleteContext(context);
	SDL_Quit();
#endif
	return 0;
}
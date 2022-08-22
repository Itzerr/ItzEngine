#include <SDL.h>
#include <stdexcept>
#include <ItzEngine/ItzEngine.h>

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL2 error: %s\n", SDL_GetError());
		throw std::runtime_error("SDL2 initialization failed");
	}

	SDL_Window* window = SDL_CreateWindow(
		"Hello SDL2!",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1280, 720,
		0);

	if (window == nullptr) {
		printf("SDL2 error: %s\n", SDL_GetError());
		throw std::runtime_error("SDL2 window creation failed");
	}

	bool is_running = true;
	while (is_running) {
		SDL_Event event{};
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				is_running = false;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
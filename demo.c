#include <stdio.h>

#include "src/app.h"
#include "src/screen.h"

int main(int argc, char** argv) {
	printf("demo\n");
	App* app = create_app("demo", 640, 480);
	create_screen(app);
	uint8_t quit = 0;
	while (!quit) {
		update_app(app);
		SDL_Event e;
		while(SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = 1;
			}
		}
	}
	destroy_app(app);
	return 0;
}

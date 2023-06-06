#include "app.h"
#include "screen.h"

App* create_app(const char* name, int width, int height) {
	App* app = malloc(sizeof(App));
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Could not initialize SDL video subsystem. SDL error: %s\n",
				SDL_GetError());
		exit(1);
	}
	app->win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, 0);
	if (app->win == NULL) {
		fprintf(stderr, "Could not create SDL window, SDL error: %s\n", SDL_GetError());
		exit(1);
	}
	app->rend = SDL_CreateRenderer(app->win, -1, 0);
	if (app->rend == NULL) {
		fprintf(stderr, "Could not create SDL rednerer, SDL error: %s\n", SDL_GetError());
		exit(1);
	}

	return app;
}

void update_app(App* app) {
	SDL_SetRenderDrawColor(app->rend, app->screen->bg_color.r, app->screen->bg_color.g,
			app->screen->bg_color.b, app->screen->bg_color.a);
	SDL_RenderClear(app->rend);
	SDL_RenderPresent(app->rend);
}

void destroy_app(App* app) {
	SDL_DestroyRenderer(app->rend);
	SDL_DestroyWindow(app->win);
	destroy_screen(app->screen);
	free(app);
}

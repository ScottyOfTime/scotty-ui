/**
 *  \file app.c
 *
 *  \brief Funtionality of the app
 */

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
	if (TTF_Init() == -1) {
		fprintf(stderr, "Could not initialize SDL_ttf. SDL_ttf error: %s\n", TTF_GetError());
		exit(1);
	}
	app->font_text = TTF_OpenFont("/usr/share/fonts/TTF/FiraMono-Regular.ttf", 18); // TEMP FONT
	if (app->font_text == NULL) {
		fprintf(stderr, "Could not open font Roboto-Medium.ttf, SDL_ttf error; %s\n", TTF_GetError());
		exit(1);
	}

	return app;
}

uint8_t update_app(App* app) {
	if (handle_event(app) == 0) {
		return SC_EXIT;
	}
	SDL_SetRenderDrawColor(app->rend, app->screen->bg_color.r, app->screen->bg_color.g,
			app->screen->bg_color.b, app->screen->bg_color.a);
	SDL_RenderClear(app->rend);
	render_screen(app->screen);
	SDL_RenderPresent(app->rend);
	return SC_CONTINUE;
}

uint8_t handle_event(App* app) {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			return SC_EXIT; 
		}
		handle_event_screen(app->screen, &e);
	}
	return SC_CONTINUE;
}

void destroy_app(App* app) {
	SDL_DestroyRenderer(app->rend);
	SDL_DestroyWindow(app->win);
	destroy_screen(app->screen);
	free(app);
}

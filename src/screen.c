#include "screen.h"

SDL_Color screen_bg_color = (SDL_Color){60, 60, 60, 255};

void create_screen(App* app) {
	Screen_t* screen_ptr = malloc(sizeof(Screen_t));
	screen_ptr->app = app;
	screen_ptr->bg_color = screen_bg_color;
	app->screen = screen_ptr;
}

void destroy_screen(Screen_t* screen) {
	free(screen);
}

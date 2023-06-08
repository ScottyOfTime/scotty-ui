/**
 *  \file screen.c
 *
 *  \brief Emplements functionality of the screen
 */

#include "app.h"
#include "screen.h"

SDL_Color screen_bg_color = (SDL_Color){60, 75, 60, 255};

Screen* create_screen(App* app) {
	Screen* screen_ptr = malloc(sizeof(Screen));
	screen_ptr->app = app;
	screen_ptr->bg_color = screen_bg_color;
	app->screen = screen_ptr;
	return screen_ptr;
}

void update_screen(Screen* screen) {
	update_button(screen->button);
}

void destroy_screen(Screen* screen) {
	destroy_button(screen->button);
	free(screen);
}

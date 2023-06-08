/**
 *  \file screen.c
 *
 *  \brief Emplements functionality of the screen
 */

#include "app.h"
#include "screen.h"

SDL_Color screen_bg_color = (SDL_Color){70, 70, 85, 255};

Screen* create_screen(App* app) {
	Screen* screen_ptr = malloc(sizeof(Screen));
	screen_ptr->app = app;
	screen_ptr->bg_color = screen_bg_color;
	app->screen = screen_ptr;
	return screen_ptr;
}

void render_screen(Screen* screen) {
	render_button(screen->button);
}

void handle_event_screen(Screen* screen, const SDL_Event* event) {
	handle_event_button(screen->button, event);
}

void destroy_screen(Screen* screen) {
	destroy_button(screen->button);
	free(screen);
}

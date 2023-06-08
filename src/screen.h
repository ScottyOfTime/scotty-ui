/**
 *  \file screen.h
 *
 *  \brief Defines structures and cuntions for a screen
 */

#include <SDL2/SDL.h>

#include "button.h"


#ifndef SC_SCREEN_H
#define SC_SCREEN_H


extern SDL_Color screen_bg_color;

/* defined in app.h */
typedef struct App App;

/* A screen is a single UI layer instance that can contain UI elements */
typedef struct Screen {
	App* app;
	SDL_Color bg_color;

	Button* button;
} Screen;

/* Creates a screen within a scotty-ui app */
Screen* create_screen(App* app);

void update_screen(Screen* screen);

/* Frees resources used by a screen */
void destroy_screen(Screen* screen);

#endif

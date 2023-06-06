/**
 *  \file screen.h
 *
 *  \brief Defines structures and cuntions for a screen
 */

#include <SDL2/SDL.h>

#include "app.h"

#ifndef SC_SCREEN_H
#define SC_SCREEN_H


extern SDL_Color screen_bg_color;

/* A screen is a single UI layer instance that can contain UI elements */
struct Screen_s {
	App* app;
	SDL_Color bg_color;
};

/* Creates a screen within a scotty-ui app */
void create_screen(App* app);

/* Frees resources used by a screen */
void destroy_screen(Screen_t* screen);

#endif

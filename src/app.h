/**
 *  \file app.h
 *
 *  \brief Defines structures and functions for the app
 */

#include <SDL2/SDL.h>

#ifndef SC_APP_H
#define SC_APP_H

/* Forward declaration of Screen structure see screen.h */
typedef struct Screen_s Screen_t;

/* The App structure for storing/maintaining/modifying the app state */
typedef struct {
	SDL_Window* win;
	SDL_Renderer* rend;

	Screen_t* screen;
} App;

/* Creates a scotty-ui app (fills app structure) */
App* create_app(const char* name, int width, int height);

/* Updates the application including computation and rendering */
void update_app(App* app);

/* Frees all resources created and used by scotty-ui app */
void destroy_app(App* app);

#endif

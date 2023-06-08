/**
 *  \file app.h
 *
 *  \brief Declares/defines structures and functions for the app
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "screen.h"

#ifndef SC_APP_H
#define SC_APP_H

#define SC_EXIT 0x0
#define SC_CONTINUE 0x1

/* The App structure for storing/maintaining/modifying the app state */
typedef struct App {
	SDL_Window* win;		// pointer to SDL window instance
	SDL_Renderer* rend;		// pointer to SDL renderer instance

	Screen* screen;			// pointer to child screen

	TTF_Font* font_text;	// pointer to True Type Font for text
} App;

/* Creates a scotty-ui app (fills app structure) */
App* create_app(const char* name, int width, int height);

/* Updates the application including computation and rendering 
 * returns: 0 on app exit >0 otherwise */
uint8_t update_app(App* app);

/* Handles SDL events such as keyboard/mouse input 
 * returns: 0 on event indicating app exit >0 otherwise */
uint8_t handle_event(App* app);

/* Frees all resources created and used by scotty-ui app */
void destroy_app(App* app);

#endif

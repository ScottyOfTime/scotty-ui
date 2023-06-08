/**
 *  \file button.h
 *
 *   \brief Declares/defines structures and functions for a button
 */

#include <SDL2/SDL.h>

#ifndef SC_BUTTON
#define SC_BUTTON

extern SDL_Color button_color;
extern SDL_Color button_color_hovered;

/* defined in screen.h */
typedef struct Screen Screen;

/* Structure for a button */
typedef struct {
	Screen* screen;			// parent screen

	int x, y;				// position
	char text[16];			// text to appear on button (MAY BE REDUNDANT)
	SDL_Texture* text_tex; 	// pointer to a texture containing text

	uint8_t hovered;		// mouse is hovering button

	void (*on_press)(); 	// pointer to function to execute on button press
} Button;

Button* create_button(Screen* screen, int x, int y, const char* text, void (*on_press));

void update_button(Button* button);

void destroy_button(Button* button);

#endif

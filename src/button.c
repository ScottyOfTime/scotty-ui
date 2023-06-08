/**
 *  \file button.c
 *
 *  \brief implements functions declared in button.h
 *
 */
#include <SDL_render.h>
#include <SDL_ttf.h>

#include "app.h"
#include "screen.h"
#include "button.h"

SDL_Color button_color = (SDL_Color){150, 120, 25, 255};
SDL_Color button_color_hovered = (SDL_Color){175, 135, 30, 255};

Button* create_button(Screen* screen, int x, int y, const char* text, void (*on_press)) {
	Button* btn_ptr = malloc(sizeof(Button));
	btn_ptr->x = x;
	btn_ptr->y = y;

	btn_ptr->screen = screen;
	strcpy(btn_ptr->text, text);

	btn_ptr->hovered = 0;
	screen->button = btn_ptr;

	SDL_Surface* text_surf = TTF_RenderText_Solid(btn_ptr->screen->app->font_text, btn_ptr->text,
			(SDL_Color){255, 255, 255, 255});
	btn_ptr->text_tex = SDL_CreateTextureFromSurface(btn_ptr->screen->app->rend, text_surf);
	SDL_FreeSurface(text_surf);
	return btn_ptr;
}

void update_button(Button* button) {
	SDL_Rect rect = (SDL_Rect){button->x, button->y, 70, 30};
	SDL_SetRenderDrawColor(button->screen->app->rend, button_color.r, button_color.g,
			button_color.b, button_color.a);
	SDL_RenderFillRect(button->screen->app->rend, &rect);
	SDL_RenderCopy(button->screen->app->rend, button->text_tex, NULL, &rect);
}

void destroy_button(Button* button) {
	SDL_DestroyTexture(button->text_tex);
	free(button);
}

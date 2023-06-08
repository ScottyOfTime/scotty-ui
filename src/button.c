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

SDL_Color button_color_hovered = (SDL_Color){173, 46, 36, 255};
SDL_Color button_color = (SDL_Color){175, 135, 30, 255};

Button* create_button(Screen* screen, int x, int y, const char* text, void (*on_press)) {
	Button* btn_ptr = malloc(sizeof(Button));

	btn_ptr->screen = screen;
	strcpy(btn_ptr->text, text);
	btn_ptr->hovered = 0;
	screen->button = btn_ptr;

	SDL_Surface* text_surf = TTF_RenderText_Solid(btn_ptr->screen->app->font_text, btn_ptr->text,
			(SDL_Color){255, 255, 255, 255});
	btn_ptr->text_tex = SDL_CreateTextureFromSurface(btn_ptr->screen->app->rend, text_surf);
	btn_ptr->text_rect = (SDL_Rect){x, y, text_surf->w, text_surf->h};
	SDL_FreeSurface(text_surf);

	btn_ptr->rect.x = x;
	btn_ptr->rect.y = y;
	btn_ptr->rect.h = BUTTON_H;
	/* if the button's text is smaller than the minimum size (50), expand to 50
	/  else, pad the text by 12 (6 either side) */
	if (btn_ptr->text_rect.w + BUTTON_PADDING < BUTTON_W_MIN)
		btn_ptr->rect.w = BUTTON_W_MIN;
	else
		btn_ptr->rect.w = btn_ptr->text_rect.w + BUTTON_PADDING;
	// set the text position to have even padding left/right
	btn_ptr->text_rect.x = btn_ptr->text_rect.x + (btn_ptr->rect.w - btn_ptr->text_rect.w)/2;
	return btn_ptr;
}

void render_button(Button* button) {
	if (!button->hovered)
		SDL_SetRenderDrawColor(button->screen->app->rend, button_color.r, button_color.g,
				button_color.b, button_color.a);
	else
		SDL_SetRenderDrawColor(button->screen->app->rend, button_color_hovered.r,
				button_color_hovered.g, button_color_hovered.b, button_color_hovered.a);
	SDL_RenderFillRect(button->screen->app->rend, &button->rect);
	SDL_RenderCopy(button->screen->app->rend, button->text_tex, NULL, &button->text_rect);
}

void handle_event_button(Button *button, const SDL_Event *event) {
	if (event->type == SDL_MOUSEMOTION) {
		if (is_hovered(button, event->motion.x, event->motion.y))
			button->hovered = 1;
		else
			button->hovered = 0;
	}
}

uint8_t is_hovered(Button* button, int x, int y) {
	return !(x < button->rect.x ||
			 x > button->rect.x + button->rect.w ||
			 y < button->rect.y ||
			 y > button->rect.y + button->rect.h);
}

void destroy_button(Button* button) {
	SDL_DestroyTexture(button->text_tex);
	free(button);
}

#include <stdio.h>

#include "src/app.h"
#include "src/screen.h"

void on_press(void* arg) {
	uint8_t* cont = (uint8_t*)arg;
	*cont = 0;
	fprintf(stderr, "on_press changed cont (%p) to %d\n", arg, *cont);
	return;
}

int main(int argc, char** argv) {
	printf("demo\n");
	App* app = create_app("demo", 640, 480);
	Screen* scrn_a = create_screen(app);
	char* string = "hello";
	uint8_t cont = 1;
	uint8_t cont_button = 1;
	fprintf(stderr, "cont at %p\n", &cont);
	Button* btn_a = create_button(app->screen, 50, 50, "A", &on_press, &cont_button);
	while (cont && cont_button) {
		cont = update_app(app);
		//fprintf(stderr, "%p: %d\n", &cont, cont);
	}
	destroy_app(app);
	return 0;
}

#include <stdio.h>

#include "src/app.h"
#include "src/screen.h"

void on_press() {
	return;
}

int main(int argc, char** argv) {
	printf("demo\n");
	App* app = create_app("demo", 640, 480);
	Screen* scrn_a = create_screen(app);
	char* string = "hello";
	Button* btn_a = create_button(app->screen, 50, 50, "A", &on_press);
	uint8_t cont = 1;
	while (cont) {
		cont = update_app(app);
	}
	destroy_app(app);
	return 0;
}

#include <stdio.h>

#include "src/app.h"
#include "src/screen.h"

int main(int argc, char** argv) {
	printf("demo\n");
	App* app = create_app("demo", 640, 480);
	create_screen(app);
	while (1) {
		update_app(app);
	}
	destroy_app(app);
	return 0;
}

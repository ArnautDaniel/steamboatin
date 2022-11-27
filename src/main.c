#include "init.h"

int main() {
	int height = 1000;
	int width = 1000;
	SetTargetFPS(60);

	InitWindow(width, height, "That's Steamboatin Baby!");
	InitGame();
	while (!WindowShouldClose()) {
		Update();
		Render();
	}
	return 0;
}
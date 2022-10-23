#include <raylib.h>
#include "init.h"

int main() {
	int height = 800;
	int width = 600;
	SetTargetFPS(60);

	InitWindow(width, height, "That's Steamboatin Baby!");
	InitGame();
	while (!WindowShouldClose()) {
		UpdateScreen();
		RenderScreen();
	}
	return 0;
}
#include "init.h"

#define place_holderspeed 5;

extern int player_id;
extern struct GameObject* player;
extern struct GameObject* enemy;
extern int canon_texture;
extern int turrent_texture;

void HandleInput() {
	if (IsKeyDown(KEY_A)) {
		player->moveable->position->x -= place_holderspeed;
		//PlayerRotate(LEFT);
	}
	if (IsKeyDown(KEY_D)) {
		player->moveable->position->x += place_holderspeed;
		//PlayerRotate(RIGHT);
	}
	if (IsKeyDown(KEY_W)) {
		player->moveable->position->y -= place_holderspeed;
		//PlayerRotate(UP);
	}
	if (IsKeyDown(KEY_S)) {
		player->moveable->position->y += place_holderspeed;
		//PlayerRotate(DOWN);
	}
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Vector2 vec2 = GetMousePosition();
    printf("MOUSE POSITION: %f %f\n", vec2.x, vec2.y);
    CreateNPC(vec2.x, vec2.y, turrent_texture);
    enemy->effects->current_hp -= 1;
  }
}


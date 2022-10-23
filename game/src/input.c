#include "init.h"

#define place_holderspeed 5;

extern int player_id;
extern struct Character* player;

void HandleInput() {
	if (IsKeyDown(KEY_A)) {
		player->position->x -= place_holderspeed;
		PlayerRotate(LEFT);
	}
	if (IsKeyDown(KEY_D)) {
		player->position->x += place_holderspeed;
		PlayerRotate(RIGHT);
	}
	if (IsKeyDown(KEY_W)) {
		player->position->y -= place_holderspeed;
		PlayerRotate(UP);
	}
	if (IsKeyDown(KEY_S)) {
		player->position->y += place_holderspeed;
		PlayerRotate(DOWN);
	}

}


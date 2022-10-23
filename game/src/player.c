#include "init.h"

extern struct Character* player;

void PlayerRotate(int degrees) {
	player->rotation = degrees;
	return;
}
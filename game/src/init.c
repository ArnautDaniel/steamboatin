#include "init.h"

struct Character* player = NULL;
struct AssetMap* asset_map;

void InitGame() {
	int player_texture = CreateTexture("resources/player.png");
	int player_id = CreateNPC(50, 50, player_texture);
	player = FindNPC(player_id);

	int npc = CreateNPC(200, 200, player_texture);

	return;
};


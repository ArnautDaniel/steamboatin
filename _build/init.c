#include "init.h"



struct Character* player = NULL;
struct AssetMap* asset_map;
int gridsize;

void InitGame() {

  for (int i = 0; i < GetScreenHeight(); i += increment) {
    for (int j = 0; j < GetScreenWidth(); j += increment) {
      gridsize = CreateGrid(i, j);
    }
  }

	int player_texture = CreateTexture("resources/player.png");
	int turrent_texture = CreateTexture("resources/yacht.png");
	int cannon_texture = CreateTexture("resources/canon.png");
	int player_id = CreateNPC(50, 50, player_texture);
	player = FindNPC(player_id);

	int turrent = CreateNPC(200, 200, turrent_texture);
	int canon = CreateTurrent(FindNPC(turrent), player, cannon_texture);
	return;
};


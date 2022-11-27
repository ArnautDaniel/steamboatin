#include "init.h"

struct GameObject* player = NULL;
struct AssetMap* asset_map;
int gridsize;
int canon_texture;
int turrent_texture;
int enemy_texture;

void InitGame() {

  for (int i = 0; i < GetScreenHeight(); i += increment) {
    for (int j = 0; j < GetScreenWidth(); j += increment) {
      gridsize = CreateGrid(i, j);
    }
  }

	int player_texture = CreateTexture("resources/player.png");
	turrent_texture = CreateTexture("resources/yacht.png");
	canon_texture = CreateTexture("resources/canon.png");
  enemy_texture = CreateTexture("resources/enemy.png");

  player = CreateGameObject(NPC);
  player->moveable = AddMoveable(player, 100, 100, 0, 0, 10);
  player->visuals = AddVisuals(player, player_texture, 0, 1.0, RAYWHITE);

	return;
};


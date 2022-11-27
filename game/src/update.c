#include "init.h"

extern int enemy_texture;

// generalize this later
int iCountEnemies(struct AssetMap* assets) {
  if (assets == NULL) {
    return 0;
  }
  return 1 + iCountEnemies(assets->next);
}

void MoveEnemies(struct AssetMap* assets, int count) {
  struct AssetMap* asset_next;
  for (int i = 0; i < count; i++) {
    struct Moveable* enemy = ((struct GameObject*)assets->data)->moveable;
    enemy->position->x += 1.0;
    enemy->position->y += 1.0;
    asset_next = assets->next;
    MemFree(assets);
    assets = asset_next;
  }
  return;
}
void HandleEnemies() {
  struct AssetMap* assets = FindAllByType(ENEMY);
  int count = iCountEnemies(assets);
  MoveEnemies(assets, count);
  return;
}

void Update() {
	HandleInput();
  //HandleEnemies();
	return;
}

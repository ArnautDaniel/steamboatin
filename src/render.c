#include "init.h"

extern struct AssetMap* asset_map;
extern int gridsize;


// Just a debugging function.  grids are inserted first into the AssetMap so
// they don't have to be searched for every frame. 
void RenderGrid() {
  struct AssetMap* assets = asset_map;

  for (int i = 0; i < gridsize; i++) {
    struct Grid* grid = assets->data;
    assets = assets->next;
    DrawRectangleLines(grid->x, grid->y, increment, increment, RAYWHITE);
  }
  return;
}

void iRender(struct AssetMap* assets, void(*renderfunc)(struct AssetMap* asset)) {
  if (assets == NULL || assets->id == 0) return;
  renderfunc(assets);
  struct AssetMap* next = assets->next;
  MemFree(assets);
  return iRender(next, renderfunc);
}

void RenderGameObject(struct AssetMap* asset) {
  struct GameObject* go = asset->data;

  if (go->visuals == NULL) return;

  Texture* texture = go->visuals->texture;
  DrawTextureEx(*texture, *go->moveable->position, 0, 0.2, RED);

  if (go->effects == NULL) return;
  float x = go->moveable->position->x;
  float y = go->moveable->position->y + 40;

  DrawRectangleLines(x, y, 40, 10, RED);
  int max_hp = go->effects->max_hp;
  int current_hp = go->effects->current_hp;
  DrawRectangle(x + 2, y, ((float)current_hp/(float)max_hp) * 40, 10, GREEN);
  return;
}

void RenderGameObjects(struct AssetMap* gameobjects) {
  return iRender(gameobjects, RenderGameObject);
}

void Render() {
	BeginDrawing();

	ClearBackground(BLACK);
  RenderGrid();
  RenderGameObjects(FindAllByType(NPC));
  RenderGameObjects(FindAllByType(ENEMY));

	EndDrawing();
	return;
}

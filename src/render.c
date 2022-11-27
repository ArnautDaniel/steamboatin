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

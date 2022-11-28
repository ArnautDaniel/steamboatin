#include "init.h"

extern struct AssetMap* asset_map;

// This current version just uses a linked list.  However, other options may be quite faster.
// Whenever I have an idea about improvements I'll post it here...
//
//

struct AssetMap* FindInMap(struct AssetMap* asset_map, int id) {
	if (asset_map == NULL) {
		return NULL;
	}
	if (asset_map->id == id) {
		return asset_map;
	}
	return FindInMap(asset_map->next, id);
}

struct AssetMap* iFindAllByType(struct AssetMap* asset_ptr, int type, struct AssetMap* assets) {
	
	if (asset_ptr == NULL) {
		return assets;
	}

	if (asset_ptr->type == type) {
		AddAssetMap(assets, asset_ptr->data, asset_ptr->type);
		return iFindAllByType(asset_ptr->next, type, assets);
	}

	return iFindAllByType(asset_ptr->next, type, assets);
}

struct AssetMap* FindAllByType(int type) {
	struct AssetMap* assets = MemAlloc(sizeof(struct AssetMap));
	iFindAllByType(asset_map, type, assets);
	return assets;
}

void ClearAssetMap(struct AssetMap* assets) {
	if (assets == NULL) {
		return;
	}

	struct AssetMap* asset_ptr = assets->next;
	MemFree(assets);
	return ClearAssetMap(asset_ptr);
}

int CreateTexture(const char* filename) {
	Texture texture = LoadTexture(filename);
	Texture* texture_stack = MemAlloc(sizeof(struct Texture));
	texture_stack->format = texture.format;
	texture_stack->height = texture.height;
	texture_stack->id = texture.id;
	texture_stack->mipmaps = texture.mipmaps;
	texture_stack->width = texture.width;
	return AddAssetMap(asset_map, texture_stack, FILE);
}

// Creates an empty game object.
struct GameObject* CreateGameObject(int tag) {
  struct GameObject* go = MemAlloc(sizeof(struct GameObject));

  go->moveable = NULL;
  go->effects = NULL;
  go->visuals = NULL;

  go->id = AddAssetMap(asset_map, go, tag);
  return go;
}

struct Moveable* AddMoveable(struct GameObject* go, float x, float y, float dirx, float diry, int speed) {
  struct Moveable* moveable = MemAlloc(sizeof(struct Moveable));

  struct Vector2* vecPosition = MemAlloc(sizeof(struct Vector2));
  vecPosition->x = x;
  vecPosition->y = y;
  moveable->position = vecPosition;

  struct Vector2* vecDirection = MemAlloc(sizeof(struct Vector2));
  vecDirection->x = dirx;
  vecDirection->y = diry;
  moveable->direction = vecDirection;

  moveable->speed = speed;
  return moveable;
}

struct Effectables* AddEffectable(struct GameObject* go, bool collisions, int hp) {
  struct Effectables* effects = MemAlloc(sizeof(struct Effectables));
  effects->collisions = collisions;
  effects->max_hp = hp;
  effects->current_hp = hp;
  return effects;
}

struct Visuals* AddVisuals(struct GameObject* go, int texture_id, int rotation, float scale, Color color) {
  struct Visuals* visuals = MemAlloc(sizeof(struct Visuals));
  visuals->texture = FindTexture(texture_id);
  visuals->rotation = rotation;
  visuals->scale = scale;
  visuals->color = color;
  return visuals;
}

struct GameObject* CreateNPC() {
  return CreateGameObject(NPC);
}

int CreateGrid(int x, int y) {
  struct Grid* grid = MemAlloc(sizeof(struct Grid));
  grid->x = x;
  grid->y = y;
  return AddAssetMap(asset_map, grid, GRID);
}

struct GameObject* CreateEnemy() {
  return CreateGameObject(ENEMY);
}

struct Texture* FindTexture(int id) {
	struct AssetMap* asset = FindInMap(asset_map, id);
	return (struct Texture*)asset->data;
}

struct GameObject* FindGameObject(int id) {
	struct AssetMap* asset = FindInMap(asset_map, id);
	return (struct GameObject*)asset->data;
}

int AddAssetMap(struct AssetMap* asset_ptr, void* asset, int type) {

	struct AssetMap* asset_next = MemAlloc(sizeof(struct AssetMap));
	asset_next->next = NULL;
	asset_next->type = type;
	asset_next->data = asset;

	if (asset_ptr == NULL) {
		asset_next->id = 1;
		asset_map = asset_next;
		return asset_next->id;
	}

	if (asset_ptr->id == 0) {
		MemFree(asset_next);
		asset_ptr->id = 1;
		asset_ptr->data = asset;
		asset_ptr->type = type;
		asset_ptr->next = NULL;
		return asset_ptr->id;
	}

	if (asset_ptr->next == NULL) {
		asset_next->id = asset_ptr->id + 1;
		asset_ptr->next = asset_next;
		return asset_next->id;
	}
  MemFree(asset_next);
	return AddAssetMap(asset_ptr->next, asset, type);
}

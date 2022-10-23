#include <raylib.h>
#include "init.h"

extern struct AssetMap* asset_map;

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
	return AddAssetMap(asset_map, texture_stack, FILE_TYPE);
}

int CreateNPC(int x, int y, int texture_id) {
	struct Character* character = MemAlloc(sizeof(struct Character));
	character->x = x;
	character->y = y;
	character->texture_id = texture_id;
	return AddAssetMap(asset_map, character, NPC_TYPE);
}

struct Texture* FindTexture(int id) {
	struct AssetMap* asset = FindInMap(asset_map, id);
	return (struct Texture*) asset->data;
}

struct Character* FindNPC(int id) {
	struct AssetMap* asset = FindInMap(asset_map, id);
	return (struct Character*) asset->data;
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

	return AddAssetMap(asset_ptr->next, asset, type);
};
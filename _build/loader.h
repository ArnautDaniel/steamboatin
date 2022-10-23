#pragma once
struct AssetMap* FindInMap(struct AssetMap* texture_map, int id);
struct AssetMap* iFindAllByType(struct AssetMap* asset_ptr, int type, struct AssetMap* assets);
struct AssetMap* FindAllByType(int type);
void ClearAssetMap(struct AssetMap* assets);
int CreateTexture(const char* filename);
int CreateNPC(int x, int y, int texture_id);
struct Texture* FindTexture(int id);
struct Character* FindNPC(int id);
int AddAssetMap(struct AssetMap* asset_map, void* asset, int type);
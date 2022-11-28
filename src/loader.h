#pragma once
struct AssetMap* FindInMap(struct AssetMap* texture_map, int id);
struct AssetMap* iFindAllByType(struct AssetMap* asset_ptr, int type, struct AssetMap* assets);
struct AssetMap* FindAllByType(int type);
void ClearAssetMap(struct AssetMap* assets);
int CreateTexture(const char* filename);
struct GameObject* FindGameObject(int id);
struct GameObject* CreateGameObject(int tag);
struct Moveable* AddMoveable(struct GameObject* go, float x, float y, float dirx, float diry, int speed);
struct Effectables* AddEffectable(struct GameObject* go, bool collisions, int hp);
struct Visuals* AddVisuals(struct GameObject* go, int texture_id, int rotation, float scale, Color color);
struct GameObject* CreateNPC();
struct GameObject* CreateEnemy();
int CreateGrid(int x, int y);
struct Texture* FindTexture(int id);
int AddAssetMap(struct AssetMap* asset_map, void* asset, int type);

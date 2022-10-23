#include "raylib.h"
#include "init.h"


int player_id = 0;

struct AssetMap* asset_map;

void InitGame() {
	int player_texture = CreateTexture("resources/player.png");
	player_id = CreateNPC(50, 50, player_texture);
	int npc = CreateNPC(200, 200, player_texture);
	return;
};

void UpdateScreen() {
	struct Character* player = FindNPC(player_id);
	if (IsKeyDown(KEY_A)) player->x -= 5;
	if (IsKeyDown(KEY_D)) player->x += 5;
	if (IsKeyDown(KEY_W)) player->y -= 5;
	if (IsKeyDown(KEY_S)) player->y += 5;
	return;
}

void RenderNPC(struct Character* npc) {
	Texture* texture = FindTexture(npc->texture_id);
	DrawTexture(*texture, npc->x, npc->y, WHITE);
	return;
}

void RenderNPCS(struct AssetMap* npcs) {
	if (npcs == NULL || npcs->id == 0) {
		return;
	}
	RenderNPC(npcs->data);
	struct AssetMap* next = npcs->next;
	MemFree(npcs);
	return RenderNPCS(next);
}

void RenderScreen() {
	BeginDrawing();
	ClearBackground(BLACK);
	RenderNPCS(FindAllByType(NPC_TYPE));
	EndDrawing();
	return;
}
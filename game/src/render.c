#include "init.h"

void RenderNPC(struct Character* npc) {
	Texture* texture = FindTexture(npc->texture_id);
	DrawTextureEx(*texture, *npc->position, npc->rotation, 1.0, WHITE);
	return;
}

// Compiler can eat my shorts.
void RenderNPCS(struct AssetMap* npcs) {
	if (npcs == NULL || npcs->id == 0) {
		return;
	}
	RenderNPC(npcs->data);
	struct AssetMap* next = npcs->next;
	MemFree(npcs);
	return RenderNPCS(next);
}

void Render() {
	BeginDrawing();
	ClearBackground(BLACK);
	RenderNPCS(FindAllByType(NPC_TYPE));
	EndDrawing();
	return;
}
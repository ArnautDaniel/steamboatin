#pragma once

enum type_tag { FILE_TYPE, NPC_TYPE };
enum rotation_type { UP = 0, RIGHT = 90, DOWN = 180, LEFT = 270 };

struct Character {
	struct Vector2* position;
	int texture_id;
	int rotation;
};

struct AssetMap {
	int id;
	int type;
	void* data;
	struct AssetMap* next;
};


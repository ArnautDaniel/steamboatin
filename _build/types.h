#pragma once
#include <raylib.h>

enum type_tag { FILE_TYPE, NPC_TYPE };

struct Character {
	int x;
	int y;
	int texture_id;
};

struct AssetMap {
	int id;
	int type;
	void* data;
	struct AssetMap* next;
};


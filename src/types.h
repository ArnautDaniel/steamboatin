#pragma once

enum type_tag { FILE, NPC, TURRENT, GRID, ENEMY, PROJECTILE};
enum rotation_type { UP = 0, RIGHT = 90, DOWN = 180, LEFT = 270 };

struct Moveable {
  struct Vector2* position;
  struct Vector2* direction;
  int speed;
};

struct Effectables {
  bool collisions;
  bool flying;
  int max_hp;
  int current_hp;

};

struct Visuals {
  struct Texture* texture;
  int rotation;
  float scale;
  Color color;
};

struct Projectile {
  struct GameObject* go;
  int damage;
};

struct GameObject {
  struct Moveable* moveable;
  struct Effectables* effects;
  struct Visuals* visuals;
  int id;
};

struct AssetMap {
	int id;
	int type;
	void* data;
	struct AssetMap* next;
};

struct Grid {
  int x;
  int y;
};

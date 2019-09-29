#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include <string>
using namespace std;

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct Tileset {
	unsigned int firstgrid = 1;
	string name = "Desert";
	unsigned int tilewidth = 32;
	unsigned int tileheight = 32;
	unsigned int spacing = 32;
	unsigned int margin = 32;
	string img_desert_spacing = "tmw_desert_spacing.png";
};

// TODO 1: Create a struct needed to hold the information to Map node
enum Orientation {
	OR_Orthogonal,
	OR_Isometric,
	OR_Hexagonal,
};

enum RenderOrder {
	right_down,
	right_up,
	left_down,
	left_up,
};

struct MapNode {
	float version = 1.0f;
	Orientation myOrientation = OR_Orthogonal;
	RenderOrder myRenderOrder = right_down;
	unsigned int width = 50;
	unsigned int height = 15;
	unsigned int tilewidth = 32;
	unsigned int tileheight = 32;
	unsigned int nextobjectid = 1;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:


public:

	// TODO 1: Add your struct for map info as public for now

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__
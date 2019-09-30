#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"


// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct Tileset {
	p2SString name = "Desert";
	uint firstgrid = 1;
	uint tilewidth = 32;
	uint tileheight = 32;
	uint spacing = 32;
	uint margin = 32;

	p2SString file_name;
	unsigned int file_width;
	unsigned int file_height;
};

// TODO 1: Create a struct needed to hold the information to Map node
enum Orientation {
	Orthogonal,
	Isometric,
	Hexagonal,
	Staggered,
};

enum RenderOrder {
	right_down,
	right_up,
	left_down,
	left_up,
};

struct map_info {
	float version = 1.0f;
	Orientation myOrientation = Orthogonal;
	RenderOrder myRenderOrder = right_down;
	uint width = 50;
	uint height = 15;
	uint tilewidth = 32;
	uint tileheight = 32;
	uint nextobjectid = 1;
};

struct Layer
{
	p2SString name;
	uint width;
	uint height;
	uint* data;
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
	bool FillMapInfo(pugi::xml_node&);
	bool FillTileSet();
	void LogMapData(bool, bool);
public:

	// TODO 1: Add your struct for map info as public for now
	map_info map;
	p2List<Tileset*> tilesets;
	p2List<Layer*> layers;
private:

	pugi::xml_document	map_info;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__
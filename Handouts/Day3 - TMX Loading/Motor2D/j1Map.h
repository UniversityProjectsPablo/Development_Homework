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
	unsigned int firstgrid = 1;	
	unsigned int tilewidth = 32;
	unsigned int tileheight = 32;
	unsigned int spacing = 32;
	unsigned int margin = 32;

	p2SString file_name;
	unsigned int file_width;
	unsigned int file_height;
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

struct map_info {
	float version = 1.0f;
	Orientation myOrientation = OR_Orthogonal;
	RenderOrder myRenderOrder = right_down;
	unsigned int width = 50;
	unsigned int height = 15;
	unsigned int tilewidth = 32;
	unsigned int tileheight = 32;
	unsigned int nextobjectid = 1;
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
	void FillMapInfo();

public:

	// TODO 1: Add your struct for map info as public for now
	map_info map;
	p2List<Tileset*> tilesets;
	p2List<Layer*> layers;
private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__
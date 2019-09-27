#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------


// TODO 1: Create a struct needed to hold the information to Map node
enum Orientation {
	or_ortogonal,
	or_isometric,
	or_staggered,
	or_hexagonal,
};
Orientation myOrientation = or_ortogonal;

enum  renderorder {
	right_down,
	right_up,
	left_down,
	left_up,
};

enum class information {
	version = 1,
	//Orientation myOrientation,
	renderorder = 1,
	width = 1,
	height = 1,
	tilewidth = 32,
	tileheight = 32,
	spacing = 1,
	margin = 1,
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
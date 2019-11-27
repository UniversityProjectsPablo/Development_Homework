#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map
	for (unsigned int i = 0; i < layers.count(); i++)
		delete[] layers[i]->data;


	map_info.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_info.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	bool loadmap = false;
	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		loadmap = FillMapInfo(map_info.child("map"));

	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	bool loadtiles = FillTileSet();

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
		LogMapData(loadmap, loadtiles);
	}

	map_loaded = ret;

	return ret;
}

bool j1Map::FillMapInfo(pugi::xml_node&)
{
	p2SString orientation = map_info.attribute("myOrientation").as_string();
	p2SString renderorder = map_info.attribute("renderorder").as_string();

	//Map Orientation
	if (orientation == "Orthogonal")
		map.myOrientation = Orientation::Orthogonal;
	else if (orientation == "Isometric")
		map.myOrientation = Orientation::Isometric;
	else if (orientation == "Staggered")
		map.myOrientation = Orientation::Staggered;
	else if (orientation == "Hexagonal")
		map.myOrientation = Orientation::Hexagonal;

	//Render Order
	if (renderorder == "right_down")
		map.myRenderOrder = RenderOrder::right_down;
	else if (renderorder == "right_up")
		map.myRenderOrder = RenderOrder::right_up;
	else if (renderorder == "left_down")
		map.myRenderOrder = RenderOrder::left_down;
	else if (renderorder == "left_up")
		map.myRenderOrder = RenderOrder::left_up;

	map.width = map_info.attribute("width").as_uint();
	map.height = map_info.attribute("height").as_uint();
	map.tilewidth = map_info.attribute("tilewidth").as_uint();
	map.tileheight = map_info.attribute("tileheight").as_uint();

	return true;
}

bool j1Map::FillTileSet() 
{
	for (pugi::xml_node tileset = map_info.child("map").child("tileset");tileset;tileset = tileset.next_sibling("tileset")) 
	{
		Tileset* tile = new Tileset;

		tile->name = tileset.attribute("name").as_string();
		tile->firstgrid = tileset.attribute("firstgrid").as_uint();
		tile->tilewidth = tileset.attribute("tilewidth").as_uint();
		tile->tileheight = tileset.attribute("tileheight").as_uint();
		tile->spacing = tileset.attribute("spacing").as_uint();
		tile->margin = tileset.attribute("margin").as_uint();
		
		tile->file_name = tileset.attribute("file_name").as_string();
		tile->file_width = tileset.attribute("file_width").as_uint();
		tile->file_height = tileset.attribute("file_height").as_uint();		
	}	
	return true;
}

void j1Map::LogMapData(bool loadmap, bool loadtiles)
{
	if (loadmap && loadtiles)
		LOG("XML file parsed successfully");
	else
		LOG("Error parsing XML file");

	LOG("-- Map Info --");

	LOG("Width: %d", map.width);
	LOG("Height: %d", map.height);
	LOG("Tilewidth: %d", map.tilewidth);
	LOG("Tileheight: %d", map.tileheight);

	LOG("TileSet----");

	for (uint i = 0; i < tilesets.count(); i++)
	{
		LOG("name: %s", tilesets[i]->name.GetString());
		LOG("firstgid: %d", tilesets[i]->firstgrid);
		LOG("tile width: %d", tilesets[i]->tilewidth);
		LOG("tile height: %d", tilesets[i]->tileheight);
		LOG("spacing: %d", tilesets[i]->spacing);
		LOG("margin: %d", tilesets[i]->margin);
		LOG("---");
		LOG("image name: %s", tilesets[i]->file_name.GetString());
		LOG("image width: %d", tilesets[i]->file_width);
		LOG("image height: %d", tilesets[i]->file_height);
	}
}
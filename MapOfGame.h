
#ifndef GAME_OF_MAP_H
#define GAME__OF_MAP_H

#include "BaseFunction.h"
#include "BaseObject.h"

#define MAX_TILES 20 // so luong cac kieu tile trong map 

// tile map : luu trang thai cua cac o, fill hinh anh va luu dc o so bao nhieu(mo hinh hoa du lieu)

class TileMat : public BaseObject //  hinh anh tinh load vao o
{
public:
	TileMat() { ; }
	~TileMat() { ; }
};

class GameMap
{
public:
	GameMap() { ; }
	~GameMap() { ; }

	void LoadMap(char* name);
	void LoadTiles(SDL_Renderer* screen);
	void DrawMap(SDL_Renderer* screen);
	Map getMap() const { return game_map_; };
	void SetMap(Map& map_data) { game_map_ = map_data; };
private:
	Map game_map_; // chua toan bo thong tin ve ban do :  trang thai cua o, vi tri cua o, chi so cua o
	TileMat tile_mat[MAX_TILES];
};
#endif



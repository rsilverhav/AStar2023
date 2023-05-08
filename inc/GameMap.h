#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Point.h"
#include <vector>

enum class MapTileType { floor, wall, invalid };

class GameMap {
private:
  std::vector<std::vector<MapTileType>> mapData;

public:
  int width, height;
  GameMap(int _width, int _height);
  MapTileType getTileType(const Point &point) const;
  void setTileType(const Point &, MapTileType);
};

#endif

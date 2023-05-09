#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Point.h"
#include <string>
#include <vector>

enum class MapTileType { floor, wall, invalid };

class GameMap {
public:
  int width, height;
  GameMap(int _width, int _height);
  GameMap(std::string mapFilePath);
  MapTileType getTileType(const Point &point) const;
  void setTileType(const Point &, MapTileType);

private:
  std::vector<std::vector<MapTileType>> mapData;
};

#endif

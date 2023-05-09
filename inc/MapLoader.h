#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include "GameMap.h"
#include "Point.h"
#include <string>
#include <tuple>
class MapLoader {
public:
  MapLoader() = default;
  static std::tuple<MapData, Point, Point> loadMap(std::string mapFilePath);
};

#endif

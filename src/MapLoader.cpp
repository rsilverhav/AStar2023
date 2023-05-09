#include "MapLoader.h"
#include "GameMap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>

std::tuple<MapData, Point, Point> MapLoader::loadMap(std::string mapFilePath) {
  MapData mapData;
  Point from{0, 0};
  Point to{0, 1};

  std::ifstream infile(mapFilePath);
  int y = 0;
  for (std::string line; getline(infile, line);) {
    mapData.push_back({});
    for (auto c : line) {
      switch (c) {
      case '#':
        mapData[y].push_back(MapTileType::wall);
        break;
      case 's':
        mapData[y].push_back(MapTileType::floor);
        from.x = mapData[y].size() - 1;
        from.y = mapData.size() - 1;
        break;
      case 'e':
        mapData[y].push_back(MapTileType::floor);
        to.x = mapData[y].size() - 1;
        to.y = mapData.size() - 1;
        break;
      default:
        mapData[y].push_back(MapTileType::floor);
      }
    }
    y++;
  }

  return std::make_tuple(mapData, from, to);
}

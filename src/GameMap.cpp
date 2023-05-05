#include "GameMap.h"
#include <__tuple>
#include <memory>

GameMap::GameMap(int _width, int _height) : width(_width), height(_height) {
  for (int y = 0; y < height; y++) {
    mapData.push_back({});
    for (int x = 0; x < width; x++) {
      mapData[y].push_back(MapTileType::floor);
    }
  }
}

MapTileType GameMap::getTileType(const Point &point) const {
  return mapData.at(point.y).at(point.x);
}

void GameMap::setTileType(const Point &point, MapTileType tileType) {
  mapData[point.y][point.x] = tileType;
}

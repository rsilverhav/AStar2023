#include "GameMap.h"
#include <memory>
#include <stdexcept>

GameMap::GameMap(int _width, int _height) : width(_width), height(_height) {
  for (int y = 0; y < height; y++) {
    mapData.push_back({});
    for (int x = 0; x < width; x++) {
      mapData[y].push_back(MapTileType::floor);
    }
  }
}

MapTileType GameMap::getTileType(const Point &point) const {
  try {
    return mapData.at(point.y).at(point.x);
  } catch (const std::out_of_range &e) {
    return MapTileType::invalid;
  }
}

void GameMap::setTileType(const Point &point, MapTileType tileType) {
  mapData[point.y][point.x] = tileType;
}

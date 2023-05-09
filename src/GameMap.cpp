#include "GameMap.h"
#include <fstream>
#include <iostream>
#include <sstream>

GameMap::GameMap(int _width, int _height) : width(_width), height(_height) {
  for (int y = 0; y < height; y++) {
    mapData.push_back({});
    for (int x = 0; x < width; x++) {
      mapData[y].push_back(MapTileType::floor);
    }
  }
}

GameMap::GameMap(std::string mapFilePath) {
  std::ifstream infile(mapFilePath);
  int y = 0;
  for (std::string line; getline(infile, line);) {
    mapData.push_back({});
    for (auto c : line) {
      if (c == '#') {
        mapData[y].push_back(MapTileType::wall);
      } else {
        mapData[y].push_back(MapTileType::floor);
      }
    }
    y++;
  }

  width = mapData[0].size();
  height = mapData.size();
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

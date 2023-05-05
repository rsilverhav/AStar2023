#include "GameMap.h"
#include "MapRenderer.h"
#include "PathFinder.h"
#include "PathNode.h"
#include "TerminalMapRenderer.h"
#include <iostream>
#include <memory>
#include <vector>

const int width = 10;
const int height = 10;

int main() {
  auto gameMap = GameMap(width, height);

  gameMap.setTileType({3, 3}, MapTileType::wall);
  gameMap.setTileType({3, 4}, MapTileType::wall);
  gameMap.setTileType({3, 5}, MapTileType::wall);

  std::unique_ptr<MapRenderer> mapRenderer =
      std::make_unique<TerminalMapRenderer>();

  PathFinder pathFinder{};

  auto path = pathFinder.findShortestPath({1, 3}, {6, 4});
  mapRenderer->renderMap(gameMap, path);
}

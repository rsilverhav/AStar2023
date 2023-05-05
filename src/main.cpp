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
  auto map = GameMap(width, height);

  std::unique_ptr<MapRenderer> mapRenderer =
      std::make_unique<TerminalMapRenderer>();

  PathFinder pathFinder{};

  auto path = pathFinder.findShortestPath({1, 3}, {6, 4});
  // mapRenderer->renderMap(map, path);
}

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
  std::vector<std::vector<int>> map;

  for (int y = 0; y < height; y++) {
    map.push_back({});
    for (int x = 0; x < width; x++) {
      map.at(y).push_back(0);
    }
  }
  map[3][3] = 1;
  map[4][3] = 1;
  map[5][3] = 1;

  std::unique_ptr<MapRenderer> mapRenderer =
      std::make_unique<TerminalMapRenderer>();

  PathFinder pathFinder{};

  auto path = pathFinder.findShortestPath({1, 3}, {6, 4});

  mapRenderer->renderMap(map, path);
}

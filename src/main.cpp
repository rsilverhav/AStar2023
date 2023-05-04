#include "MapRenderer.h"
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

  auto node = std::make_shared<PathNode>(1, 3);
  auto nodeNext = std::make_shared<PathNode>(2, 3, node);
  auto nodeThird = std::make_shared<PathNode>(2, 4, nodeNext);

  mapRenderer->renderMap(map, nodeThird);
}

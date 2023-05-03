#include "MapRenderer.h"
#include "TerminalMapRenderer.h"
#include <iostream>
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

  std::unique_ptr<MapRenderer> mapRenderer =
      std::make_unique<TerminalMapRenderer>();

  mapRenderer->renderMap(map);
}

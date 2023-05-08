#include "GameMap.h"
#include "MapRenderer.h"
#include "PathFinder.h"
#include "TerminalMapRenderer.h"

const int width = 10;
const int height = 10;

int main() {
  auto gameMap = GameMap(width, height);

  gameMap.setTileType({3, 3}, MapTileType::wall);
  gameMap.setTileType({3, 4}, MapTileType::wall);
  gameMap.setTileType({3, 5}, MapTileType::wall);

  std::unique_ptr<MapRenderer> mapRenderer =
      std::make_unique<TerminalMapRenderer>();

  auto manhattanDistance = [](Point point) {
    std::vector<Point> adjacentPoints{};
    adjacentPoints.push_back({point.x + 1, point.y});
    adjacentPoints.push_back({point.x - 1, point.y});
    adjacentPoints.push_back({point.x, point.y + 1});
    adjacentPoints.push_back({point.x, point.y - 1});
    return adjacentPoints;
  };

  PathFinder pathFinder{manhattanDistance};

  auto path = pathFinder.findShortestPath({1, 3}, {6, 4}, gameMap);
  mapRenderer->renderMap(gameMap, path);
}

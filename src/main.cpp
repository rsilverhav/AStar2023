#include "GameMap.h"
#include "MapRenderer.h"
#include "PathFinder.h"
#include "Point.h"
#include "TerminalMapRenderer.h"
#include <iostream>

const int width = 10;
const int height = 10;

int main() {
  auto gameMap = GameMap(width, height);

  gameMap.setTileType({3, 3}, MapTileType::wall);
  gameMap.setTileType({3, 4}, MapTileType::wall);
  gameMap.setTileType({3, 5}, MapTileType::wall);

  std::unique_ptr<MapRenderer> mapRenderer =
      std::make_unique<TerminalMapRenderer>();

  auto manhattanDistance = [](const Point &point) {
    std::vector<Point> adjacentPoints{};
    for (int dy = -1; dy <= 1; dy += 2) {
      adjacentPoints.push_back({point.x, point.y + dy});
    }
    for (int dx = -1; dx <= 1; dx += 2) {
      adjacentPoints.push_back({point.x + dx, point.y});
    }
    return adjacentPoints;
  };

  auto euclideanDistance = [manhattanDistance](const Point &point) {
    std::vector<Point> adjacentPoints{};
    for (int dy = -1; dy <= 1; dy += 1) {
      for (int dx = -1; dx <= 1; dx += 1) {
        if (dx == 0 && dy == 0) {
          continue;
        }
        adjacentPoints.push_back({point.x + dx, point.y + dy});
      }
    }
    return adjacentPoints;
  };

  Point from{1, 3};
  Point to{6, 4};

  {
    std::cout << "\nEuclidean\n";
    PathFinder pathFinder{euclideanDistance};

    auto path = pathFinder.findShortestPath(from, to, gameMap);
    mapRenderer->renderMap(gameMap, path);
  }
  {
    std::cout << "\nManhattan\n";
    PathFinder pathFinder{manhattanDistance};

    auto path = pathFinder.findShortestPath(from, to, gameMap);
    mapRenderer->renderMap(gameMap, path);
  }
}

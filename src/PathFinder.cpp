#include "PathFinder.h"
#include "PathNode.h"
#include <iostream>
#include <memory>
#include <vector>

PathFinder::PathFinder(
    std::function<std::vector<Point>(Point)> _getAdjacentPoints)
    : getAdjacentPoints(_getAdjacentPoints) {}

std::shared_ptr<PathNode> PathFinder::findShortestPath(const Point &from,
                                                       const Point &to,
                                                       const GameMap &gameMap) {

  auto startNode =
      std::shared_ptr<PathNode>(new PathNode({from.x, from.y}, 0.0f));

  auto adjacentPoints = this->getAdjacentPoints(from);

  for (auto p : adjacentPoints) {
    std::cout << p.x << ", " << p.y << "\n";
  }

  return startNode;
}

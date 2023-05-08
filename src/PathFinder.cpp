#include "PathFinder.h"
#include <iostream>
#include <queue>
#include <unordered_set>

PathFinder::PathFinder(
    std::function<std::vector<Point>(Point)> _getAdjacentPoints)
    : getAdjacentPoints(_getAdjacentPoints) {}

std::shared_ptr<PathNode> PathFinder::findShortestPath(const Point &from,
                                                       const Point &to,
                                                       const GameMap &gameMap) {

  auto startNode =
      std::shared_ptr<PathNode>(new PathNode({from.x, from.y}, 0.0f));

  auto cmp = [](std::shared_ptr<PathNode> left,
                std::shared_ptr<PathNode> right) { return left->x < right->x; };
  std::priority_queue<std::shared_ptr<PathNode>,
                      std::vector<std::shared_ptr<PathNode>>, decltype(cmp)>
      queue(cmp);

  queue.push(startNode);

  while (!queue.empty()) {
    auto current = queue.top();
    std::cout << "Current: " << current->x << ", " << current->y << "\n";
    queue.pop();
  }

  auto adjacentPoints = this->getAdjacentPoints(from);

  return startNode;
}

#include "PathFinder.h"
#include "GameMap.h"
#include <memory>
#include <queue>
#include <unordered_set>

PathFinder::PathFinder(
    std::function<std::vector<Point>(Point)> _getAdjacentPoints)
    : getAdjacentPoints(_getAdjacentPoints) {}

std::shared_ptr<PathNode> PathFinder::findShortestPath(const Point &from,
                                                       const Point &to,
                                                       const GameMap &gameMap) {

  auto startNode = std::shared_ptr<PathNode>(
      new PathNode({from.x, from.y}, to.getDistance(from)));

  auto cmp = [](std::shared_ptr<PathNode> left,
                std::shared_ptr<PathNode> right) {
    return left->estimatedDistance > right->estimatedDistance;
  };

  std::priority_queue<std::shared_ptr<PathNode>,
                      std::vector<std::shared_ptr<PathNode>>, decltype(cmp)>
      queue(cmp);

  queue.push(startNode);

  std::unordered_set<Point> visited;

  while (!queue.empty()) {
    auto current = queue.top();
    queue.pop();

    if (*current == to) {
      return current;
    }

    visited.insert(*current);

    auto adjacentPoints = this->getAdjacentPoints(*current);
    for (auto adjacent : adjacentPoints) {
      auto mapTileType = gameMap.getTileType(adjacent);
      if (mapTileType == MapTileType::floor &&
          visited.find(adjacent) == visited.end()) {
        queue.push(std::shared_ptr<PathNode>(new PathNode(
            {adjacent.x, adjacent.y},
            from.getDistance(adjacent) + to.getDistance(adjacent), current)));
      }
    }
  }

  return nullptr;
}

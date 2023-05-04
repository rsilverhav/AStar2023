#include "PathFinder.h"
#include "PathNode.h"
#include <memory>

std::shared_ptr<PathNode> PathFinder::findShortestPath(const Point &from,
                                                       const Point &to) {
  auto startNode = std::make_shared<PathNode>(from.x, from.y);
  return startNode;
}

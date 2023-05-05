#include "PathFinder.h"
#include "PathNode.h"
#include <memory>

std::shared_ptr<PathNode> PathFinder::findShortestPath(const Point &from,
                                                       const Point &to) {
  auto startNode = std::shared_ptr<PathNode>(new PathNode({2, 3}, 0.0f));

  return startNode;
}

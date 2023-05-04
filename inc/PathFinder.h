#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "PathNode.h"
#include "Point.h"
#include <memory>

class PathFinder {
public:
  // TODO: add constructor parameter function for getting adjacent Points
  PathFinder() {}

  std::shared_ptr<PathNode> findShortestPath(const Point &from,
                                             const Point &to);
};

#endif

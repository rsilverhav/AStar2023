#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "GameMap.h"
#include "PathNode.h"
#include "Point.h"
#include <functional>
#include <memory>
#include <vector>

class PathFinder {
public:
  PathFinder(std::function<std::vector<Point>(Point)> _getAdjacentPoints);

  std::shared_ptr<PathNode> findShortestPath(const Point &from, const Point &to,
                                             const GameMap &gameMap);

private:
  std::function<std::vector<Point>(Point)> getAdjacentPoints;
};

#endif

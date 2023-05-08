#ifndef PATH_NODE_H
#define PATH_NODE_H
#include "Point.h"
#include <memory>
#include <string>

class PathNode : public Point {
public:
  float distanceFromStart;
  float estimatedDistance;
  std::shared_ptr<PathNode> previousNode;
  PathNode(Point, float, float);
  PathNode(Point, float, float, std::shared_ptr<PathNode>);

  void printDistanceFromStart();
};
#endif

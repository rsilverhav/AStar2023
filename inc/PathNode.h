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
  PathNode(Point _point, float _distanceFromStart, float _estimatedDistance);
  PathNode(Point _point, float _distanceFromStart, float _estimatedDistance,
           std::shared_ptr<PathNode>);

  void printDistanceFromStart();
};
#endif

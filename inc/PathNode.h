#ifndef PATH_NODE_H
#define PATH_NODE_H
#include "Point.h"
#include <memory>
#include <string>

class PathNode : public Point {
public:
  float estimatedDistance;
  std::shared_ptr<PathNode> previousNode;
  PathNode(Point, float);
  PathNode(Point, float, std::shared_ptr<PathNode>);
};
#endif

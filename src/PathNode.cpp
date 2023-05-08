#include "PathNode.h"
#include <string>

PathNode::PathNode(Point _point, float _distanceStart)
    : Point(_point.x, _point.y), distanceStart(_distanceStart) {}

PathNode::PathNode(Point _point, float _distanceStart,
                   std::shared_ptr<PathNode> _previousNode)
    : PathNode(_point, _distanceStart) {
  previousNode = _previousNode;
};

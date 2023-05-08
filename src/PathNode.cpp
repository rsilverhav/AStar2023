#include "PathNode.h"
#include <string>

PathNode::PathNode(Point _point, float _distanceStart, float _estimatedDistance)
    : Point(_point.x, _point.y), distanceStart(_distanceStart),
      estimatedDistance(_estimatedDistance) {}

PathNode::PathNode(Point _point, float _distanceStart, float _estimatedDistance,
                   std::shared_ptr<PathNode> _previousNode)
    : PathNode(_point, _distanceStart, _estimatedDistance) {
  previousNode = _previousNode;
};

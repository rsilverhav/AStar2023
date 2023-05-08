#include "PathNode.h"

PathNode::PathNode(Point _point, float _distanceFromStart,
                   float _estimatedDistance)
    : Point(_point.x, _point.y), distanceFromStart(_distanceFromStart),
      estimatedDistance(_estimatedDistance) {}

PathNode::PathNode(Point _point, float _distanceFromStart,
                   float _estimatedDistance,
                   std::shared_ptr<PathNode> _previousNode)
    : PathNode(_point, _distanceFromStart, _estimatedDistance) {
  previousNode = _previousNode;
};

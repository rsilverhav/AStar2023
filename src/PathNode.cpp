#include "PathNode.h"
#include <string>

PathNode::PathNode(Point _point, float _estimatedDistance)
    : Point(_point.x, _point.y), estimatedDistance(_estimatedDistance) {}

PathNode::PathNode(Point _point, float _estimatedDistance,
                   std::shared_ptr<PathNode> _previousNode)
    : PathNode(_point, _estimatedDistance) {
  previousNode = _previousNode;
};

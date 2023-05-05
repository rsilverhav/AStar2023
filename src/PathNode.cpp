#include "PathNode.h"
#include <string>

PathNode::PathNode(Point _point, float _distanceStart)
    : point(_point), distanceStart(_distanceStart) {}
PathNode::PathNode(Point _point, float _distanceStart,
                   std::shared_ptr<PathNode> _previousNode)
    : PathNode::PathNode(_point, _distanceStart) {
  previousNode = _previousNode;
};

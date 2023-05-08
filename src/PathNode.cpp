#include "PathNode.h"
#include <iostream>
#include <memory>

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

void PathNode::printDistanceFromStart() {
  int steps = 0;
  auto current = this->previousNode;
  while (current) {
    steps++;
    current = current->previousNode;
  }
  std::cout << "Distance from start: " << steps
            << " steps, real: " << this->distanceFromStart << "\n";
}

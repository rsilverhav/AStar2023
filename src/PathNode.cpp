#include "PathNode.h"
#include <string>

std::string PathNode::getKey() {
  return std::to_string(x) + "," + std::to_string(y);
}

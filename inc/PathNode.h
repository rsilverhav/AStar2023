#ifndef PATH_NODE_H
#define PATH_NODE_H
#include <memory>
#include <string>

class PathNode {
public:
  int x, y;
  std::shared_ptr<PathNode> previousNode;
  PathNode(int _x, int _y) : x(_x), y(_y) {}
  PathNode(int _x, int _y, std::shared_ptr<PathNode> _previousNode)
      : x(_x), y(_y), previousNode(_previousNode) {}
  std::string getKey();
};
#endif

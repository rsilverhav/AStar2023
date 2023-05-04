#ifndef MAP_RENDERER_H
#define MAP_RENDERER_H

#include "PathNode.h"
#include <vector>

class MapRenderer {
public:
  virtual ~MapRenderer() = default;
  virtual void renderMap(const std::vector<std::vector<int>> &map,
                         std::shared_ptr<PathNode> path) = 0;
};

#endif

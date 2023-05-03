#ifndef MAP_RENDERER_H
#define MAP_RENDERER_H

#include <vector>

class MapRenderer {
public:
  virtual ~MapRenderer() = default;
  virtual void renderMap(const std::vector<std::vector<int>> &map) = 0;
};

#endif

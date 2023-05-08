#ifndef MAP_RENDERER_H
#define MAP_RENDERER_H

#include "GameMap.h"
#include "PathNode.h"
#include <vector>

class MapRenderer {
public:
  virtual ~MapRenderer() = default;
  virtual void renderMap(const GameMap &gameMap,
                         const std::shared_ptr<PathNode> path) const = 0;
};

#endif

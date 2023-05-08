#ifndef TERMINAL_MAP_RENDERER_H
#define TERMINAL_MAP_RENDERER_H

#include "GameMap.h"
#include "MapRenderer.h"
#include "PathNode.h"
#include <vector>

class TerminalMapRenderer : public MapRenderer {
public:
  TerminalMapRenderer(){};

  void renderMap(const GameMap &gameMap,
                 std::shared_ptr<PathNode> path) const override;
};

#endif

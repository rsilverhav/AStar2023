#ifndef TERMINAL_MAP_RENDERER_H
#define TERMINAL_MAP_RENDERER_H

#include "MapRenderer.h"
#include "PathNode.h"
#include <iostream>
#include <vector>

class TerminalMapRenderer : public MapRenderer {
public:
  TerminalMapRenderer(){};

  void renderMap(const std::vector<std::vector<int>> &map,
                 std::shared_ptr<PathNode> path) override;
};

#endif

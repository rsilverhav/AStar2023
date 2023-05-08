#ifndef TERMINAL_MAP_RENDERER_H
#define TERMINAL_MAP_RENDERER_H

#include "GameMap.h"
#include "MapRenderer.h"
#include "PathNode.h"
#include <unordered_map>
#include <vector>

class TerminalMapRenderer : public MapRenderer {
public:
  TerminalMapRenderer(std::unordered_map<Point, char>);

  void renderMap(const GameMap &gameMap,
                 std::shared_ptr<PathNode> path) const override;

private:
  std::unordered_map<Point, char> marks;
};

#endif

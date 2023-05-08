#include "TerminalMapRenderer.h"
#include <iostream>
#include <unordered_set>

TerminalMapRenderer::TerminalMapRenderer(std::unordered_map<Point, char> _marks)
    : marks(_marks) {}

void TerminalMapRenderer::renderMap(
    const GameMap &gameMap, const std::shared_ptr<PathNode> path) const {

  auto getKey = [](int x, int y) {
    return std::to_string(x) + "," + std::to_string(y);
  };

  std::unordered_set<std::string> pathNodes;
  if (path) {
    auto currentNode = path;
    do {
      pathNodes.insert(getKey(currentNode->x, currentNode->y));
      currentNode = currentNode->previousNode;
    } while (currentNode);
  }

  for (int i = 0; i < gameMap.width + 2; i++) {
    std::cout << "-";
  }

  std::cout << "\n";
  for (int y = 0; y < gameMap.height; y++) {
    std::cout << "|";
    for (int x = 0; x < gameMap.width; x++) {
      auto col = gameMap.getTileType({x, y});
      auto mark = marks.find({x, y});
      if (mark != marks.end()) {
        std::cout << mark->second;
      } else if (pathNodes.find(getKey(x, y)) != pathNodes.end()) {
        std::cout << ".";
      } else if (col == MapTileType::wall) {
        std::cout << "#";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "|\n";
  }
  for (int i = 0; i < gameMap.width + 2; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}

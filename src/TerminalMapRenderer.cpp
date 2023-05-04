#include "TerminalMapRenderer.h"
#include "PathNode.h"
#include "getKey.h"
#include <memory>
#include <string>
#include <unordered_set>

void TerminalMapRenderer::renderMap(const std::vector<std::vector<int>> &map,
                                    std::shared_ptr<PathNode> path) {

  std::unordered_set<std::string> pathNodes;
  auto currentNode = path;
  do {
    pathNodes.insert(getKey(currentNode->x, currentNode->y));
    currentNode = currentNode->previousNode;
  } while (currentNode);

  for (int i = 0; i < map.at(0).size() + 2; i++) {
    std::cout << "-";
  }

  std::cout << "\n";
  for (int y = 0; y < map[0].size(); y++) {
    std::cout << "|";
    for (int x = 0; x < map[y].size(); x++) {
      auto col = map[y][x];
      if (col == 1) {
        std::cout << "#";
      } else if (pathNodes.find(getKey(x, y)) != pathNodes.end()) {
        std::cout << ".";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "|\n";
  }
  for (int i = 0; i < map.at(0).size() + 2; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}

#include "TerminalMapRenderer.h"
#include "PathNode.h"
#include <memory>
#include <string>
#include <unordered_set>

void TerminalMapRenderer::renderMap(const std::vector<std::vector<int>> &map,
                                    std::shared_ptr<PathNode> path) {

  std::unordered_set<std::string> pathNodes;
  auto currentNode = path;
  do {
    pathNodes.insert(currentNode->getKey());
    currentNode = currentNode->previousNode;
  } while (currentNode);

  for (int i = 0; i < map.at(0).size() + 2; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
  for (int y = 0; y < map[0].size(); y++) {
    auto row = map[y];
    std::cout << "|";
    for (int x = 0; x < map[y].size(); x++) {
      auto col = row[x];
      std::string key = std::to_string(x) + "," + std::to_string(y);
      if (col == 1) {
        std::cout << "#";
      } else if (pathNodes.find(key) != pathNodes.end()) {
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

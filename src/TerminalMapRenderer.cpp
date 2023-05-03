#include "TerminalMapRenderer.h"

void TerminalMapRenderer::renderMap(const std::vector<std::vector<int>> &map) {
  for (int i = 0; i < map.at(0).size() + 2; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
  for (auto row : map) {
    std::cout << "|";
    for (auto col : row) {
      switch (col) {
      case 1:
        std::cout << "#";
        break;
      default:
        std::cout << " ";
        break;
      }
    }
    std::cout << "|\n";
  }
  for (int i = 0; i < map.at(0).size() + 2; i++) {
    std::cout << "-";
  }
  std::cout << "\n";
}

#include "TerminalMapRenderer.h"

void TerminalMapRenderer::renderMap(const std::vector<std::vector<int>> &map) {
  for (auto row : map) {
    for (auto col : row) {
      std::cout << col;
    }
    std::cout << "\n";
  }
}

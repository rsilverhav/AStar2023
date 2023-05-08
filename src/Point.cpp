#include "Point.h"
#include <cmath>

float Point::getDistance(const Point &point) const {
  return std::sqrtf(std::pow(point.x - this->x, 2) +
                    std::pow(point.y - this->y, 2));
}

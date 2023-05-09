#ifndef POINT_H
#define POINT_H
#include <string>

class Point {
public:
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {}
  inline bool operator==(const Point &p) const { return x == p.x && y == p.y; };
  inline bool operator!=(const Point &p) const { return !(*this == p); };

  float getDistance(const Point &point) const;
};

template <> struct std::hash<Point> {
  std::size_t operator()(const Point &k) const {
    return hash<std::string>()(std::to_string(k.x) + "," + std::to_string(k.y));
  }
};

#endif

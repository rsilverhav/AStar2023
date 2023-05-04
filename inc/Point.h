#ifndef POINT_H
#define POINT_H

class Point {
public:
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {}
  inline bool operator==(const Point &p) { return x == p.x && y == p.y; };
  inline bool operator!=(const Point &p) { return !(*this == p); };
};

#endif

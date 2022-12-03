#include <iostream>

#include <cmath>
using std::sqrt;

// Address class
class Address {

private:
  double x, y;
  bool done = false;

public:

  Address() {};
  Address( double i, double j )
    : x(i), y(j) {};

  double distance( Address other ) {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt( dx * dx + dy * dy );
  }

  auto getx() { return x;}
  auto gety() { return y;}
  auto getdone() { return done; }

  void complete() { done = true; }
};

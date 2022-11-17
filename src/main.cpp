#include <iostream>

#include <cmath>
using std::sqrt;

class Address {

private:
  double x, y;

public:
  
  Address() {};
  Address( double i, double j )
    : x(i), y(j) {};

  double distance( Address other ) {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt( dx * dx + dy * dy );
  }
};

int main() {
  
  Address one(1., 1.), two(2., 2.);

  std::cerr << "Distance: "
       << one.distance(two)
       << '\n';

  return 0;

}

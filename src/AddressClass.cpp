#include <iostream>

#include <cmath>
using std::sqrt;

// Address class
class Address {

private:
  double x, y;
  bool done = false;
  bool prime = false;

public:

  Address() {};
  Address( double i, double j )
    : x(i), y(j) {};
  // add constructor for an address that indicates if it is prime or not.
  Address( double i, double j, bool isprime )
    :x(i), y(j), prime(isprime) {};

  double distance( Address other ) {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt( dx * dx + dy * dy );
  }

  auto getx() { return x;}
  auto gety() { return y;}
  auto getdone() { return done; }
  auto getprime() { return prime; }

  void complete() { done = true; }
  void incomplete() { done = false; }

};

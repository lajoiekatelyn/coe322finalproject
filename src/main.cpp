#include <iostream>

#include <cmath>
using std::sqrt;

#include <vector>
using std::vector;

// Address class
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
  
  auto getx() { return x;}
  auto gety() { return y;}
};

// AddressList class (uses Address class)
class AddressList {

private:
  vector<Address> list_of_addresses;

public:
  AddressList() {}

  void add_address(Address address) {
    list_of_addresses.push_back(address);
  }

   double length() {
     double sum = 0;
     for ( auto &address : list_of_addresses ) {
       sum += address.distance(
     }
   }

  // int index_closest_to() {}

  void print() {
    for( auto &element : list_of_addresses )
      std::cout << "( " << element.getx() << " , " << element.gety() << " )" << std::endl; 
  }

};

int main() {
  
  Address one(1., 1.), two(2., 2.);

  AddressList stack;
  stack.add_address(one);
  stack.add_address(two);

  stack.print();

  std::cerr << "Distance: "
       << one.distance(two)
       << '\n';

  return 0;

}

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
  
  // Assume list_of_addresses has a length greater than 0
  double length() {
    double sum = 0;
    for ( int i = 1; i<list_of_addresses.size(); i++ ) {
      Address address = list_of_addresses.at(i);
      sum += address.distance(list_of_addresses.at(i-1));
    }
    return sum;
  }

  int index_closest_to(Address other) {
    Address closest = other;
    double closest_distance = 100000;
    int index = 0;
    for ( int i = 0; i<list_of_addresses.size(); i++ ) {
      Address address = list_of_addresses.at(i);
      double distance_between = address.distance(other);
      if (distance_between < closest_distance) { 
	closest_distance = distance_between; 
	index = i;
      }
    }
    return index;
  }

  void print() {
    for( auto &element : list_of_addresses )
      std::cout << "( " << element.getx() << " , " << element.gety() << " )" << std::endl; 
  }

};

int main() {
  
  Address depot(0., 0.), one(2.,0.), two(1., 0.), three(3., 0.), done(0., 0.);

  AddressList stack;
  //  stack.add_address(depot);
  stack.add_address(one);
  stack.add_address(two);
  stack.add_address(three);
  // stack.add_address(done);

  stack.print();

  std::cerr << stack.length() << '\n';
  std::cerr << stack.index_closest_to(depot) << '\n';

  std::cerr << "Distance: "
       << one.distance(two)
       << '\n';

  return 0;

}

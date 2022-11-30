#include <iostream>

/*
#include <cmath>
using std::sqrt;

#include <vector>
using std::vector;
*/

//#include "AddressClass.cpp"
#include "AddressListClass.cpp"

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

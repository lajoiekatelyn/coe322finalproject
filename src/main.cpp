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
  
  Address one(0., 5.), two(5., 0.), three(5., 5.), four(3., 5.), five(5., 2.), six(3., 7.), seven(4., 4.), eight(8., 3.), nine(2., 10.), ten(6., 8.), eleven(4., 5.);

  AddressList stack;
  //  stack.add_address(depot);
  stack.add_address(one);
  stack.add_address(two);
  stack.add_address(three);
  stack.add_address(four);
  stack.add_address(five);
  stack.add_address(six);
  stack.add_address(seven);
  stack.add_address(eight);
  stack.add_address(nine);
  stack.add_address(ten);
  stack.add_address(eleven);

  stack.two_trucks();

  return 0;

}

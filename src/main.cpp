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
  
  Address one(0., 5.), two(5., 0.), three(5., 5.), four(3., 5.), five(5., 2.), six(3., 7.);

  AddressList stack;
  //  stack.add_address(depot);
  stack.add_address(one);
  stack.add_address(two);
  stack.add_address(three);
  stack.add_address(four);
  stack.add_address(five);
  stack.add_address(six);
  // stack.add_address(done);

  // AddressList newstack = stack.greedy_route();
  // stack.print();
  // newstack.print();

  AddressList newstack2 = stack.opt2();

  newstack2.print();
    
  std::cerr << newstack2.length() << '\n';
  // std::cerr << newstack.length() << '\n';
  //std::cerr << stack.index_closest_to(depot) << '\n';

  return 0;

}

#include <iostream>

#include "RouteClass.cpp"

int main() {

  bool flag = false; // not running prime delivery.

  Route route1;
  Route route2;

  route1.add_address( Address(2., 0.) );
  route1.add_address( Address(3., 2.) );
  route1.add_address( Address(2., 3.) );
  route1.add_address( Address(0., 2.) );
  route1.greedy_route();
  route1.opt2();
  
  route2.add_address( Address(3., 1.) );
  route2.add_address( Address(2., 1.) );
  route2.add_address( Address(1., 2.) );
  route2.add_address( Address(1., 3.) );
  route2.greedy_route();
  route2.opt2();

  route1.two_trucks( route2, flag );

  return 0;

}

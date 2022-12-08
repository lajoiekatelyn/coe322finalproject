#include <iostream>

#include "RouteClass.cpp"

int main() {

  Route route1;
  Route route2;
  
  route1.add_address( Address(2., 0.) );
  route1.add_address( Address(3., 2.) );
  route1.add_address( Address(2., 3.) );
  route1.add_address( Address(0., 2.) );
  //route1.add_random_addresses(false);
  route1.make_route();
  
  route2.add_address( Address(3., 1.) );
  route2.add_address( Address(2., 1.) );
  route2.add_address( Address(1., 2.) );
  route2.add_address( Address(1., 3.) );
  route2.make_route();

  //route1.add_address( Address(0., 5.) );
  //route1.add_address( Address(5., 0.) );
  //route1.add_address( Address(5, 5.) );
  
  route1.print();
  std::cout << "\n";
  route2.print();
  std::cout << "\n";

  route1.two_trucks( route2 );

  //route1.greedy_route();

  //std::cout << "\n";
  //route1.print();
  //std::cout << "\n";

  //route1.opt2();

  //std::cout << "\n";
  //route1.print();
 
  return 0;

}

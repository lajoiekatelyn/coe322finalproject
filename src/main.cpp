#include <iostream>

#include "RouteClass.cpp"

int main() {

  Route route1;

  route1.add_address( Address(2., 0.) );
  route1.add_address( Address(3., 2.) );
  route1.add_address( Address(2., 3.) );
  route1.add_address( Address(0., 2.) );
  route1.make_route();

  Route route2;
  route2.add_address( Address(3., 1.) );
  route2.add_address( Address(2., 1.) );
  route2.add_address( Address(1., 2.) );
  route2.add_address( Address(1., 3.) );
  route2.make_route();

  std::cout << route1.length() << " " << route2.length();

  route1.two_trucks( route2 );

  std::cout << "final routes: " << std::endl;
  route1.print();
  std::cout << "\n";
  route2.print();
  
  return 0;

}

#include <iostream>

#include "AddressListClass.cpp"

class Route : public AddressList {
private:
  Address depot = Address(0., 0.);
  vector<Address> route = {depot, depot};

public:
  Route() : AddressList() {};
  // methods to keep first and last location in place (the depot!!)
  
};

int main() {
  
  Route deliveries;
  deliveries.add_address( Address(0,5));
  deliveries.add_address( Address(5,0));
  deliveries.add_address( Address(5,5));
 
  deliveries.print();

  /*
  cerr << "Travel in order: " <<
    deliveries.length() << '\n';
  assert( deliveries.size()==5 );
  auto route = deliveries.greedy_route();
  assert( route.size()==5 );
  auto len = route.length();
  cerr << "Square route: " << route.as_string() << "\n has length " << len << '\n';
  */
  return 0;
}

#include <iostream>

#include "AddressListClass.cpp"

class Route : public AddressList {
private:
  Address depot = Address(0., 0.);
  vector<Address> route;

public:
  Route() : AddressList() {};
  // methods to keep first and last location in place (the depot!!)

  void make_route() {
    route.push_back(depot);

    for (int i = 0 ; i < list_of_addresses.size(); i++) {
      route.push_back(list_of_addresses.at(i));
    }

    route.push_back(depot);

  };

  void greedy_route() {
    Address we_are_here = depot;
    route.push_back(we_are_here);

    while ( route.size() < list_of_addresses.size() + 1  ) {
      int min_index = index_closest_to( we_are_here );
      list_of_addresses[min_index].complete();
      we_are_here = list_of_addresses[min_index];
      route.push_back(we_are_here);
    }

    route.push_back( depot );
    
  }
  
  void print() {
    for( auto &address : route )
      std::cout << "( " << address.getx() << " , " << address.gety() << " )" << std::endl;
  }

};

int main() {
  
  Route deliveries;
  deliveries.add_address( Address(0,5));
  deliveries.add_address( Address(5,0));
  deliveries.add_address( Address(5,5));
  
  // deliveries.greedy_route();

  deliveries.make_route();

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

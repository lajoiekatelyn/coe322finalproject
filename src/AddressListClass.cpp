#include <iostream>

#include <tuple>
using std::pair;
using std::make_pair;

#include <vector>
using std::vector;

#include "AddressClass.cpp"

// AddressList class (uses Address class)
class AddressList {

protected:
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
      if (distance_between < closest_distance && address.getdone() == false) {
        closest_distance = distance_between;
        index = i;
      }
    }
    return index;
  }

  auto getsize() { return list_of_addresses.size(); }
  auto getlist() { return list_of_addresses; }
  auto getlistindex(int index) { return list_of_addresses.at(index); }
  
  void changeaddress( int index, Address address ) {
    list_of_addresses.at(index) = address;
  }

  void print() {
    for( auto &element : list_of_addresses )
      std::cout << "( " << element.getx() << " , " << element.gety() << " )" << std::endl;
  }

};

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

  AddressList greedy_route() {
    Address we_are_here = Address(0., 0.);
    AddressList new_list;
    new_list.add_address(we_are_here);
    
    while ( new_list.getsize() < list_of_addresses.size() + 1  ) {
      int min_index = index_closest_to( we_are_here );
      list_of_addresses[min_index].complete();
      we_are_here = list_of_addresses[min_index];
      new_list.add_address(we_are_here);
    }

    new_list.add_address( Address(0., 0.) );
    return new_list;
  
  }

  AddressList opt2() {
    AddressList route = greedy_route();
    // route.print();
    std::cout << "\n";
    bool route_changing = true;
    double len;
    for (int m=1; m<route.getsize()-1; m++) {
      bool changed = false;
      AddressList new_route;
      int n = m+1;
      for (int i=0; i<route.getsize(); i++) {
	if ( i == m ) {
	  new_route.add_address( route.getlistindex(n) );
	} else if ( i == n ) {
	  new_route.add_address( route.getlistindex(m) );
	} else {
	  new_route.add_address( route.getlistindex(i) );
	}	
      }
      if ( new_route.length() < route.length() ) {
	// std::cout << "changed \n";
	bool changed = true;
	len = route.length();
	route = new_route;
	// std::cout << len << " " << route.length() << "\n";
	m = 1;
      } 	
    }
    
    return route;

  }

  pair<AddressList, AddressList> populate_two_lists() {
    AddressList list1;
    AddressList list2;

    int size = list_of_addresses.size();
    int half = size / 2; // "rounds" down

    for (int i=0; i<half; i++) {
      list1.add_address( list_of_addresses[i] );
    }
    for (int i=half; i<size; i++) {
      list2.add_address( list_of_addresses[i] );
    }

    pair<AddressList,AddressList> list_pair = make_pair( list1, list2 );

    return list_pair;

  }

  //pair<AddressList, AdressList> two_trucks() {
    
  void two_trucks() {
    pair<AddressList, AddressList> list_pair = populate_two_lists();
    AddressList one = list_pair.first;
    AddressList two = list_pair.second;
    AddressList new_one, new_two;

    one = one.opt2();
    two = two.opt2();
    
    one.print();
    std::cout << "\n";
    two.print();
    std::cout << "\n";

    // for each index of one, iterate through two and see if swapping those two values will make one or the other shorter
    for (int i=1; i<one.getsize()-1; i++) {
      for (int j=1; j<two.getsize()-1; j++) {
	// reassign new_one and new_two st they match one and two and the previous swaps are "erased"
	new_one = one;
	new_two = two;
	// flip index i in new_one and index j in new_two
	new_one.changeaddress(i, two.getlistindex(j));
	new_two.changeaddress(j, one.getlistindex(i));

	std::cout << "one vs new_one: " << one.length() << " " << new_one.length() << "\n";
	std::cout << "two vs new_two: " << two.length() << " " << new_two.length() << "\n";


	if (new_one.length() < one.length() && new_two.length() < two.length() ) {
	  one = new_one;
	  two = new_two;
	  std::cout << "reassigning one and two \n";
	  i = 1;
	  j = two.getsize()-1;
	}
	
	//new_one.print();
	//std::cout << "\n";
	//new_two.print();
	//std::cout << "\n";
      }
      
    }
    
    std:: cout << "lists one and two... again \n";
    one.print();
    std::cout << "\n";
    two.print();

  }

  void prime_delivery() {
    
  }

  void print() {
    for( auto &element : list_of_addresses )
      std::cout << "( " << element.getx() << " , " << element.gety() << " )" << std::endl;
  }

};

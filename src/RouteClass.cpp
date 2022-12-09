#include <iostream>
#include <math.h>
#include <random>

#include "AddressListClass.cpp"

class Route : public AddressList {
private:
  Address depot = Address(0., 0.);
  AddressList route;

public:
  Route() : AddressList() {};
  // methods to keep first and last location in place (the depot!!)

  void set_route( AddressList list ) { route = list; };

  auto get_route() { return route; }

  double length() {
    double sum = 0;
    for ( int i = 1; i<route.getsize(); i++ ) {
      Address address = route.getlistindex(i);
      sum += address.distance(route.getlistindex(i-1));
    }
    return sum;
  }

  void make_route() {
    route.add_address(depot);

    for (int i = 0 ; i < list_of_addresses.size(); i++) {
      route.add_address(list_of_addresses.at(i));
    }

    route.add_address(depot);

  };

  void greedy_route() {
    Address we_are_here = depot;
    route.add_address(we_are_here);

    while ( route.getsize() < list_of_addresses.size() + 1  ) {
      int min_index = index_closest_to( we_are_here );
      list_of_addresses[min_index].complete();
      we_are_here = list_of_addresses[min_index];
      route.add_address(we_are_here);
    }

    route.add_address( depot );
    
  }

  void opt2() {
    int m = 1;
    while ( m<route.getsize()-2 ) {
      //std::cout << "\nm = " << m << std::endl;
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
      
      // debug
      //new_route.print();
      //std::cout << "new vs old " << new_route.length() << " " << route.length() << "\n\n";

      if ( new_route.length() < route.length() ) {
	//std::cout << "changed\n";
	route = new_route;
	m = 0;
      } 
      m++;
    }
    
  }

  void add_random_addresses(bool with_prime) {
    //generate a number for how many addresses
    std::random_device r;
    std::default_random_engine generator{ r() };
    std::uniform_int_distribution<int> distribution(0,25);
    int num_addresses = distribution(generator);

    for (int i=0; i<num_addresses; i++) {
      //generate an x
      std::uniform_real_distribution<double> distribution(-10.,10.);
      double x = distribution(generator);
      //generate a y
      double y = distribution(generator);
      if (with_prime) {
	//give it a prime value
	std::uniform_int_distribution<int> distribution(0,1);
	int prime_int = distribution(generator);
	if (prime_int == 0) {
	  add_address( Address(x, y, false) );
	} else { 
	  add_address( Address(x, y, true) );
	}
      } else {
	add_address( Address(x, y) );
      }
    }
  }
  
  void two_trucks( Route &other_route, bool flag ){
    AddressList other = other_route.get_route();
    AddressList new_route, new_other;
    double smallest_total = route.length() + other.length();
    double current_total = smallest_total;
    
    //std::cout << "current toatal: " << current_total << "\n";

    //route.print();
    //std::cout << "\n";    
    //other.print();
    //std::cout << "\n";

    // for each index of one, iterate through two and see if swapping those two values will make one or the other shorter
    int i = 1;
    while ( i<route.getsize()-1 ) {
      //std::cout << "\nPASS " << i-1 << std::endl;
      int j = 1;
      while( j<other.getsize()-1 ) {
      
	// reassign new_one and new_two st they match one and two and the previous swaps are "erased"
	new_route = route;
	new_other = other;    
      
	//new_route.print();
	//std::cout << "\n";    
	//new_other.print();
	//std::cout << "\n";
	
	Address other_add = other.getlistindex(j);
	Address route_add = route.getlistindex(i);
	
	// flip index i in new_one and index j in new_two
	if (flag) {
	  if ( !other_add.getprime() && !route_add.getprime() ) { 
	    new_route.changeaddress(i, other.getlistindex(j));
	    new_other.changeaddress(j, route.getlistindex(i));
	  }
	}
	
	// somewhere in here, a generator with a chance of adding a new address
	// std::cout << something about the new package address that has been added. 
	
	current_total = new_route.length() + new_other.length();
	
	// std::cout << "newroute and newother " << new_route.length() << " " << new_other.length() << "\n";
	// std::cout << "new total vs total " << new_route.length() + new_other.length() << " " << route.length() + other.length() << " " << "\n";

	if (new_other.length() < other.length() || new_route.length() < route.length() ) {
	  if (current_total < smallest_total) {
	    smallest_total = current_total;
	    route = new_route;
	    other = new_other;
	    i = 1;
	    j = 1; // changed from other.getsize()-1;
	  }
	}
	
	//std::cout << "out of inner if \n";
	j++;
      } 
      i++;
    }
    
    //std::cout << "printing final routes (in loop)" << std::endl;
    //route.print();
    //std::cout << "\n";
    //other.print();
    //std::cout << "\n";
    std::cout << "final distance of two_trucks(): " << route.length() + other.length() << std::endl;
    
    // update the input other_route by pass through reference
    other_route.set_route( other );

  }

  void print() {
    for( auto &address : route.getlist() ) {
      std::cout << "( " << address.getx() << " , " << address.gety() << " )";
      if ( address.getprime() ) std::cout << " prime";
      std::cout << "\n";
    }
  }

};

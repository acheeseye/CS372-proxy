// proxychest.cpp
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

#include "proxychest.h"

#include <iostream>
using std::cout;
using std::endl;

// ProxyChest constructor
// initializes a pointer to Chest object
// initialized as nullptr so constructor for Chest is not yet called
// this implements the proxy functionality (restricts access according to privilage)
ProxyChest::ProxyChest()
	:	real_chest_m(nullptr)
{
}

// loot_chest
// proxied version of loot_chest
// checks in the inventory is premium (access resctriction)
void ProxyChest::loot_chest(Inventory & inv)
{
	if(inv.is_premium())
	{
		if(!real_chest_m)
		{
			real_chest_m = std::make_unique<Chest>();
		}
		else
		{
			cout << "$$  This chest was looted previously\n$$  >>  Loot again";
		}
		std::cin.ignore();
		real_chest_m->loot_chest(inv);	
		std::cin.ignore();
		cout << endl;
	}
	else
	{
		cout << "$$  TO LOOT THIS CHEST, SIGN UP FOR PREMIUM MEMBERSHIP FOR A LOW PRICE OF:" << endl;
		cout << "$$      $299.99/mo!" << endl << endl;
	}
}

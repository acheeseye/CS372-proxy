// inventory.cpp
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

#include "inventory.h"
#include <iostream>
#include "chest.h"
using std::cout;


Inventory::Inventory() 
	:	prem_status_m(false)
{}

bool Inventory::is_premium() const
{
	return prem_status_m;
}

void Inventory::set_premium()
{
	prem_status_m = true;
}

void Inventory::add_loot(const int loot_id)
{
	if (loot_id == Chest::nothing)
	{
	}
	else if (inv.size() < 5)
	{
		inv.push_back(loot_id);
	}
	else
	{
		cout << ":(  Your inventory is full\n:(  Discarding loot...\n\n";
	}
}

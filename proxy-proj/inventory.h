// inventory.h
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class Inventory
{
public:
	Inventory();
	bool is_premium() const;
	void set_premium();
	void add_loot(int loot_id);
private:
	bool prem_status_m;
	std::vector<int> inv;
};

#endif /* Inventory class */
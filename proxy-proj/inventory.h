// inventory.h
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

// S ingle responsibility:	manages the contents of an inventory
// O pen/closed:			extendable (can add size, etc), and non-modifiable (unless data structure difference)
// L iskov:					no subclass exists
// I nterface segregation:	client uses "pay_299_99_per_month" instead of "set_premium"
// D ependency inversion:	depends on ProxyChest interface abstraction

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class Inventory
{
public:
	Inventory() = default;
	bool is_premium() const;
	void pay_299_99_per_month();
	void add_loot(int loot_id);
private:
	void set_premium();
	bool prem_status_m = false;
	std::vector<int> inv;
};

#endif /* Inventory class */
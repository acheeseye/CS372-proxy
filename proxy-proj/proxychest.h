// proxychest.h
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

// S ingle responsibility:	checks if inventory status is premium
// O pen/closed:			extendable (according to class Chest), non-modifiable
// L iskov:					no subclass exists
// I nterface segregation:	"loot_chest" is of client interest (is constructor of interest to client?)
// D ependency inversion:	ProxyChest is interface depended on by Inventory and Chest

#ifndef PROXYCHEST_H
#define PROXYCHEST_H

#include "inventory.h"
#include "chest.h"
#include <memory>

class ProxyChest
{
public:
	explicit ProxyChest();
	void loot_chest(Inventory & inv);
private:
	std::unique_ptr<Chest> real_chest_m;
};

#endif /* ProxyChest class */


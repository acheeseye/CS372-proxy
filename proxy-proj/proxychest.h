// proxychest.h
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

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


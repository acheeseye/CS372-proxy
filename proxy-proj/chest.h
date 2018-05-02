// chest.h
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

// S ingle responsibility:	keeps track of chest content
// O pen/closed:			exdentable (add more types of contents), non-modifiable
// L iskov:					no subclass exists
// I nterface segregation:	client (ProxyChest) is interested in "loot_chest", 
//							"loot_string" is private and not needed to be called by client
// D ependency inversion:	depends on ProxyChest interface abstraction

#ifndef CHEST_H
#define CHEST_H

#include "inventory.h"

#include <string>

class Chest
{
public:

	enum chest_content
	{
		nothing,
		consumable,
		equipment,
		mimic
	};

	Chest();
	~Chest() noexcept;
	void loot_chest(Inventory & inv);

private:
	std::string loot_string() const;
	int loot_m;
};

#endif /* Chest class */


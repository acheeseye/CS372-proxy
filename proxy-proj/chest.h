// chest.h
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

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
	std::string loot_string() const;
	void loot_chest(Inventory & inv);

private:
	int loot_m;
};

#endif /* Chest class */


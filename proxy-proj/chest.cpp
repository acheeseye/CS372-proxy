// chest.cpp
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data

#include "chest.h"
#include "inventory.h"

#include <ctime>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>
using std::rand;
using std::srand;

// Chest constructor
// seeds a random value between 0 and 4 as the chest content
// uses a for loop to simulate costly construction
// prints a message indicating construction
Chest::Chest()
{
	cout << "$$  Imaginarily large chest being constructed..." << endl;
	for (volatile int i = 0; i < 1000000000; ++i) {}
	srand(time(nullptr));
	loot_m = rand() % 4;
	cout << "$$      A chest was constructed!  >> Loot it";
}

// Chest destructor
// prints a message indicating destruction
Chest::~Chest() noexcept
{
	cout << "--  Chest destructed" << endl;
}

// loot_string
// returns the string form of lootable content
std::string Chest::loot_string() const
{
	switch(loot_m)
	{
	case nothing:
		return "$$      (nothing)";
	case consumable:
		return "$$      (consumable)";
	case equipment:
		return "$$      (equipment)";
	default: 
		return "###INVALID LOOT###";
	}
}

// loot_chest
// processes the chest according to the loot it contains
// then sets chest to containing nothing
void Chest::loot_chest(Inventory & inv)
{
	cout << "$$  A chest was looted!" << endl;
	if(loot_m == mimic)
	{
		cout << "**      (mimic) PREPARE FOR BATTLE (YOU OBLITERATED THE MIMIC)  >>  ok";
	}
	else
	{
		cout << loot_string() << "  >>  ok";
		inv.add_loot(loot_m);
	}
	loot_m = nothing;
}

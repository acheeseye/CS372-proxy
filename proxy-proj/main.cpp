// main.cpp
// Jason Hsi
// CS 372 Spring 2018 Software Construction
// Final Project
// Purpose: implement proxy for arbitrary data


#include "inventory.h"
#include "proxychest.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main()
{
	cout << "$$  WELCOME TO THE CHEST LOOTING SIMULATOR\n";
	cout << "$$  **************************************\n";
	cout << "$$  THE BIG IDEA OF THIS PROGRAM IS PROXYING.\n";
	cout << "$$  WE WILL ASSUME EACH CHEST IS A HUGE OBJECT\n";
	cout << "$$  THAT IS COSTLY TO CONSTRUCT ESPECIALLY IF\n";
	cout << "$$  IT IS NOT LOOTABLE (NEEDS PREMIUM ACCOUNT).\n";
	cout << "$$  THUS A PROXY CLASS WILL CHECK ACCESS BEFORE\n";
	cout << "$$  IT IS PASSED TO THE REAL CLASS FOR PROCESS.\n";
	cout << "$$  ONCE CONNECTION HAS BEEN MADE, THE OBJECT\n";
	cout << "$$  PERSISTS UNTIL EXITING PROGRAM WITH x.\n";
	cout << "$$  PLEASE TRY BOTH NORMAL AND PREMIUM INV.\n";
	cout << "$$  **************************************\n";
	cout << "$$  YOU CAN CONSTRUCT:\n";
	cout << "$$      A NORMAL INVENTORY  (n) -- can't loot anything\n";
	cout << "$$      A PREMIUM INVENTORY (p) -- can loot everything\n\n";
	cout << "$$  PLEASE CONSTRUCT AN INVENTORY...\n";

	char buf;
	Inventory my_inv;

	while(true)
	{
		cout << ">>> ";
		cin >> buf;
		if(buf == 'n')
		{
			break;
		}
		else if(buf == 'p')
		{
			my_inv.pay_299_99_per_month();
			break;
		}
		cout << "xx  INVALID INPUT TRY AGAIN" << endl;
	}

	cin.ignore();

	string prem_str;
	string icon_str;

	if(my_inv.is_premium())
	{
		prem_str = "PREMIUM";
		icon_str = "prem>>> ";
	}
	else
	{
		prem_str = "NORMAL";
		icon_str = "norm>>> ";
	}

	cout << "$$  YOU NOW HAVE A " + prem_str + " INVENTORY" << endl << endl;

	vector<ProxyChest> chests(5);

	cout << "----PRESS ENTER TO LOOT A CHEST or 'x' to quit" << endl << endl;
	while (true)
	{
		cout << icon_str;
		if(getchar() == 'x')
		{
			break;
		}
		const size_t chest_id = rand() % 5;
		cout << "$$  Random chest of 5 looted. ID: " << chest_id << endl;
		chests[chest_id].loot_chest(my_inv);
	}

	cout << "$$  Bye" << endl << endl;
	return 0;
}

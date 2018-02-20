#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "linklist.h"
using namespace std;


        

							  

void menu();
// Postcondition: A menu of commands and instructions for their use
// has been written to cout.

int main()
{
	char command;                // Each command letter
	int v;                       // Each value in a command

	linklist l;                 //Create list

	menu();                      // Show the menu.
	do
	{
		cout << "--> ";            // Issue a prompt.
		cin >> command;            // Read a command letter.
		switch (command)         // Carry out the command.
		{
		case 'e': 
			l.make_empty();
			break;

		case 'i': 
			int num;
			cout << "enter a number to be inserted" << endl;
			cin >> v;
			l.insert(v);
			break;

		case 'r': 
			int num;
			cout << "enter a number to remove" << endl;
			cin >> v;
			l.remove(v);
			break;

		case 'm': 
			l.isempty();

			break;

		case 'l': 
			l.length();
			break;

		case 'p':
			cout << "enter a number to see if its in the list" << endl;
			cin >> v;
			l.present(v);
			break;

		case 'k': 
			cout << "Enter the kth number to see whats inside the node"
				cin >> v;
			l.kth(v);
			break;

		case 'w': 
			l.display();
			break;

		case 'h': menu();
			break;

		default:;               // Null statement for an incorrect command
		}
	} while (command != 'q');

	return EXIT_SUCCESS;
}

void menu()
{
	cout << endl;
	
	cout << "  e n   -- Re-initialize list n to be empty." << endl;
	cout << "  i v n -- Insert the value v into list." << endl;
	cout << "  r v n -- Remove the value v from list." << endl;
	cout << "  l n   -- Report the length of list." << endl;
	cout << "  p v n -- Present value in list" << endl;
	cout << "  k v n -- Report kth value" << endl;
	cout << "  w n -- Write out the contents of bag n." << endl;
	cout << "  h -- See this menu." << endl;
	cout << "  q -- Quit the program." << endl << endl;
}
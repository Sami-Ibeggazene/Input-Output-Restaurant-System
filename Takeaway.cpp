
#define _CRT_SECURE_NO_WARNINGS
//including header files containing classes
#include "Menu.h"
#include "Order.h"
#include "Item.h"
//including libaries needed for program usage
#include <iostream>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//using namespace std so that std:: doesn't need to  be used
using namespace std;
//main ran on program start up
int main()
{
	string userCommand; // stores input from user
	vector <string> parameters; // stores input from user in vector
	std::string item_type, name, tempstring, line, scalories, svolume, ssharable, sprice, sabv, sdeal; //stores data about the correlating menu item
	std::string::size_type size; //used for string to double function
	Menu menu_list; //stores all the menu info from csv file
	Appetiser app1, app2, app3; //stores appetiser name and price
	Maincourse main1, main2, main3, main4; //stores main course name and price
	Beverage bev1, bev2, bev3, bev4, bev5; //stores beverage name and price
	int x = 0; //uses as counter

	std::ifstream myFileStream("menu.csv"); //creates file stream for menu.csv
	if (!myFileStream.is_open()) { //if file is not open states so
		std::cout << "File Failed to open" << std::endl;

	}
	if (myFileStream.is_open()) { //if file is open states so
		std::cout << "File opened" << std::endl;
	} 
	 
	Menu menu = Menu(); //creates menu object from Menu class
	while (getline(myFileStream, line)) { //while there's lines in the filestream 
		std::stringstream ss(line); //creates a string stream from line
		getline(ss, item_type, ','); // gets string from ss stopping at , inputting it into item_type
		menu.items.push_back(item_type); //inputting item_type into menu.items
		getline(ss, name, ',');// gets string from ss stopping at , inputting it into name
		menu.items.push_back(name);//inputting name into menu.items
		getline(ss, sprice, ',');// gets string from ss stopping at , inputting it into sprice
		menu.items.push_back(sprice);//inputting sprice into menu.items
		getline(ss, scalories, ',');// gets string from ss stopping at , inputting it into scalories
		menu.items.push_back(scalories);//inputting scalories into menu.items
		getline(ss, ssharable, ',');// gets string from ss stopping at , inputting it into ssharable
		if (ssharable == "y") { //if ssharable is "y" then replace with "(shareable)"
			ssharable = "(shareable)";
		}
		else //if ssharable is not "y" then replace with nothing
		{
			ssharable = "";
		}
		menu.items.push_back(ssharable);//inputting ssharable into menu.items
		getline(ss, sdeal, ','); // gets string from ss stopping at , inputting it into sdeal
		if (sdeal == "y") {//if sdeal is "y" then replace with "(2-4-1)"
			sdeal = "(2-4-1)";
		}
		else//if sdeal is not "y" then replace with nothing
		{
			sdeal = "";
		}
		menu.items.push_back(sdeal);//inputting sdeal into menu.items
		getline(ss, svolume, ',');// gets string from ss stopping at , inputting it into svolume
		menu.items.push_back(svolume);//inputting svolume into menu.items
		getline(ss, sabv, ',');// gets string from ss stopping at , inputting it into sabv
		menu.items.push_back(sabv);//inputting sabv into menu.items
	}
	for (int i = 0; i < 8; i++) { //pushing the first 8 elements of menu.items into app1.items
		app1.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into app2.items
		app2.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into app3.items
		app3.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into main1.items
		main1.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into main2.items
		main2.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into main3.items
		main3.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into main4.items
		main4.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into bev1.items
		bev1.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into bev2.items
		bev2.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into bev3.items
		bev3.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into bev4.items
		bev4.items.push_back(menu.items[x]);
		x++;
	}
	for (int i = 0; i < 8; i++) {//pushing the next 8 elements of menu.items into bev5.items
		bev5.items.push_back(menu.items[x]);
		x++;
	}

	// Creates an order object
	Order order = Order();


	
	while (userCommand != "exit") //loops while userCommand isn't equal to "exit"
	{
		//gives prompt on how to navigate the interace
		std::cout << "Enter one of the following commands:\n [menu] [add] [remove] [checkout] [help] [exit]" << std::endl;
		getline(cin, userCommand); //user input stored in userCommand
		char* cstr = new char[userCommand.length() + 1];//char cstr is the length of userCommand + 1
		strcpy(cstr, userCommand.c_str());
		
		char* token;
		token = strtok(cstr, " ");

		while (token != NULL) //when token is not empty push value into the end of parameters
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}
		
		string command = parameters[0]; //command is set to the first value of parameters

		if (command.compare("menu") == 0) {//if command is "menu" toString method prints all the menu items
			menu.toString(app1.items,
				app2.items,
				app3.items,
				main1.items,
				main2.items,
				main3.items,
				main4.items,
				bev1.items,
				bev2.items,
				bev3.items,
				bev4.items,
				bev5.items);
		}
		else if (command.compare("add") == 0)//runs if command is equal to "add"
		{

			Item* choice; //choice is declared as Item pointer

			std::cout << "Enter the number of the item you would like to add:" << std::endl;//prompts user to choice item number
			getline(cin, userCommand);//takes user command and inputs to Usercommand
			if (userCommand.compare("1") == 0) {//if UserCommand equals 1 adds item 1 to order and notifies users
				std::cout << app1.items[1] << " selected!" << std::endl;
				order.add(app1.items);
			}
			else if (userCommand.compare("2") == 0) {//if UserCommand equals 2 adds item 2 to order and notifies users
				std::cout << app2.items[1] << " selected!" << std::endl;
				order.add(app2.items);
			}
			else if (userCommand.compare("3") == 0) {//if UserCommand equals 3 adds item 3 to order and notifies users
				std::cout << app3.items[1] << " selected!" << std::endl;
				order.add(app3.items);
			}
			else if (userCommand.compare("4") == 0) {//if UserCommand equals 4 adds item 4 to order and notifies users
				std::cout << main1.items[1] << " selected!" << std::endl;
				order.add(main1.items);
			}
			else if (userCommand.compare("5") == 0) {//if UserCommand equals 5 adds item 5 to order and notifies users
				std::cout << main2.items[1] << " selected!" << std::endl;
				order.add(main2.items);
			}
			else if (userCommand.compare("6") == 0) {//if UserCommand equals 6 adds item 6 to order and notifies users
				std::cout << main3.items[1] << " selected!" << std::endl;
				order.add(main3.items);
			}
			else if (userCommand.compare("7") == 0) {//if UserCommand equals 7 adds item 7 to order and notifies users
				std::cout << main4.items[1] << " selected!" << std::endl;
				order.add(main4.items);
			}
			else if (userCommand.compare("8") == 0) {//if UserCommand equals 8 adds item 8 to order and notifies users
				std::cout << bev1.items[1] << " selected!" << std::endl;
				order.add(bev1.items);
			}
			else if (userCommand.compare("9") == 0) {//if UserCommand equals 9 adds item 9 to order and notifies users
				std::cout << bev2.items[1] << " selected!" << std::endl;
				order.add(bev2.items);
			}
			else if (userCommand.compare("10") == 0) {//if UserCommand equals 10 adds item 10 to order and notifies users
				std::cout << bev3.items[1] << " selected!" << std::endl;
				order.add(bev3.items);
			}
			else if (userCommand.compare("11") == 0) {//if UserCommand equals 11 adds item 11 to order and notifies users
				std::cout << bev4.items[1] << " selected!" << std::endl;
				order.add(bev4.items);
			}
			else if (userCommand.compare("12") == 0) {//if UserCommand equals 12 adds item 12 to order and notifies users
				std::cout << bev5.items[1] << " selected!" << std::endl;
				order.add(bev5.items);
			}
			else {//else notify use of inncorrect input
				std::cout << "Incorrect selection" << std::endl;
			}

		}
		else if (command.compare("remove") == 0)//if command equals "remove" run this
		{
			//promts the user to ennter number of item to remove
			std::cout << "Enter the number of the item you would like to remove:" << std::endl; 
			getline(cin, userCommand);//takes user command and inputs to Usercommand
			if (userCommand.compare("1") == 0) {//if UserCommand equals 1 remove item 1 from order and notifies users
				std::cout << app1.items[1] << " selected!" << std::endl;
				order.remove(app1.items);
			}
			else if (userCommand.compare("2") == 0) {//if UserCommand equals 2 remove item 2 from order and notifies users
				std::cout << app2.items[1] << " selected!" << std::endl;
				order.remove(app2.items);
			}
			else if (userCommand.compare("3") == 0) {//if UserCommand equals 3 remove item 3 from order and notifies users
				std::cout << app3.items[1] << " selected!" << std::endl;
				order.remove(app3.items);
			}
			else if (userCommand.compare("4") == 0) {//if UserCommand equals 4 remove item 4 from order and notifies users
				std::cout << main1.items[1] << " selected!" << std::endl;
				order.remove(main1.items);
			}
			else if (userCommand.compare("5") == 0) {//if UserCommand equals 5 remove item 5 from order and notifies users
				std::cout << main2.items[1] << " selected!" << std::endl;
				order.remove(main2.items);
			}
			else if (userCommand.compare("6") == 0) {//if UserCommand equals 6 remove item 6 from order and notifies users
				std::cout << main3.items[1] << " selected!" << std::endl;
				order.remove(main3.items);
			}
			else if (userCommand.compare("7") == 0) {//if UserCommand equals 7 remove item 7 from order and notifies users
				std::cout << main4.items[1] << " selected!" << std::endl;
				order.remove(main4.items);
			}
			else if (userCommand.compare("8") == 0) {//if UserCommand equals 8 remove item 8 from order and notifies users
				std::cout << bev1.items[1] << " selected!" << std::endl;
				order.remove(bev1.items);
			}
			else if (userCommand.compare("9") == 0) {//if UserCommand equals 9 remove item 9 from order and notifies users
				std::cout << bev2.items[1] << " selected!" << std::endl;
				order.remove(bev2.items);
			}
			else if (userCommand.compare("10") == 0) {//if UserCommand equals 10 remove item 10 from order and notifies users
				std::cout << bev3.items[1] << " selected!" << std::endl;
				order.remove(bev3.items);
			}
			else if (userCommand.compare("11") == 0) {//if UserCommand equals 11 remove item 11 from order and notifies users
				std::cout << bev4.items[1] << " selected!" << std::endl;
				order.remove(bev4.items);
			}
			else if (userCommand.compare("12") == 0) {//if UserCommand equals 12 remove item 12 from order and notifies users
				std::cout << bev5.items[1] << " selected!" << std::endl;
				order.remove(bev5.items);
			}
			else {//else notify use of inncorrect input
				std::cout << "Incorrect selection" << std::endl;
			}

		}
		else if (command.compare("checkout") == 0)//if command equals "checkout" run this
		{
			order.printReceipt(order.items); //uses printReceipt method to print the users order
			//asks user if they want to place order
			std::cout << "Do you want to place your order ?\n Type 'y' to confirm, or 'n' to go back and modify it." << std::endl;
			getline(cin, userCommand); //takes users response and stores in userCommand
			if (userCommand.compare("y") == 0) { //if userCommand equals "y" run this
				std::cout << "receipt created!" << std::endl; //notifies user receipt created!
				std::ofstream outfile("receipt.txt"); //creates receipt.txt if not created and opens stream for it
				//all this code below is the same as printReceipt method but everything is printed to the .txt instead of console
				int vecsize = order.items.size();
				int i = 0;
				double total = 0;
				std::string::size_type size;
				outfile << "----------------Receipt----------------" << std::endl;
				while (i < vecsize) {
					outfile << std::fixed;
					outfile << std::setprecision(2);
					outfile << order.items[i + 1] << " " << char(156);
					outfile << std::stod(order.items[i], &size) << std::endl;
					i += 2;
				}
				double k = 0;
				double n = 0;
				int l = 0;
				int h = 0;
				int r = 0;
				int s = 0;
				double savings = 0;
				double new_price = 0;
				for (std::vector<std::string>::const_iterator i = order.items.begin(); i != order.items.end(); i += 2) {
					n = std::stod(*i, &size);
					k += n;
				}

				for (std::vector<std::string>::const_iterator i = order.items.begin(); i != order.items.end(); ++i) {

					if (order.items[l] == "3.99") {
						h++;
					}
					l++;
				}
				if (h > 1) {
					r = h % 2;
					s = ((h - r) / 2) + r;
					new_price = s * 3.99;
					savings = (h * 3.99) - new_price;
					outfile << "2-4-1 discount applied! Savings: " << char(156) << savings << std::endl;
				}
				outfile << "Total: " << char(156) << k - savings << std::endl;
				outfile.close(); //close txt file
				order.items.clear();//clears order items ready for next order
				std::cout << "New Order:" << std::endl; //notifies user that the program is ready for a new order
			}
			else if (userCommand.compare("n") == 0) {//if userCommand equals "n" notify user that the order can now be modified
				std::cout << "modify order chosen" << std::endl;
			}
			else {//incorrect input given
				std::cout << "Incorrect selection" << std::endl;
			}
		}
		else if (command.compare("help") == 0)//if userCommand equals "help" print help on how to use the program
		{
			std::cout << "----------------Help----------------\n\n To view the menu input the command 'menu'\n\n To add an item to your order input the command 'add' and then when prompted enter the number corrilating to the desired item on the menu\n\n To remove an item from your order input the command 'remove' and then when prompted enter the number of the item you want to remove(same as menu number)\n\n To see you order input the command 'checkout' to which your order and total will be presented\n\n In the checkout option you can confirm your order by inputing 'y' which will create the receipt or to go back and change the order you can input 'n'\n\n if you have two items in the (2-4-1) deal then one of the cost of one of the items will be removed from the total cost\n\n" << std::endl;
		}

		parameters.clear();//clears parameters
		
	}

	std::cout << "Press any key to quit...";//tells user to press a key
	std::getchar();//detects users input

	
}
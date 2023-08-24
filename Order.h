#pragma once
#include "Menu.h"//Menu.h is included for class inheitance from Menu classes
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
//including libaries needed for program usage

class Order : public item_list {//delcaring class Order from item_list
public:
	double total;//delcaring total as a double

	std::string toString() {//declares toString method to return a string
		return "";
	}
	void printReceipt(std::vector<std::string>& vect1) {//declares printReceipt method

		int vecsize = items.size();//declares vecsize as the int of the size of items
		int i = 0;//declares i as int equal to 0
		double total = 0;//declares total as double equal to 0
		std::string::size_type size;//used for string to double conversion
		std::cout << "----------------Receipt----------------" << std::endl;//border showing start of receipt
		while (i < vecsize) {//runs while i is less than vecsize
			std::cout << std::fixed;//sets decimal place of numbers printed to 2
			std::cout << std::setprecision(2);
			std::cout << items[i + 1] << " " << char(156);//prints item name then £ sign
			std::cout << std::stod(items[i], &size) << std::endl;//prints item price as a double
			i += 2;//increases i by 2
		}

		calculateTotal(vect1);//calls calculateTotal method
		
		

	}
	void calculateTotal(std::vector<std::string>& vect1) {//declares calculateTotal method
		std::string::size_type size;//used for string to double conversion
		double k = 0;//declares k as double equal to 0
		double n = 0;//declares k as double equal to 0
		int l = 0;//declares l as int equal to 0
		int h = 0;//declares h as int equal to 0
		int r = 0;//declares r as int equal to 0
		int s = 0;//declares s as int equal to 0
		double savings = 0;//declares savings as double equal to 0
		double new_price = 0;//declares new_price as double equal to 0
		for (std::vector<std::string>::const_iterator i = items.begin(); i != items.end(); i += 2) {//itterates through every 2 elements in items
			n = std::stod(*i, &size);//n equals the value of i as a double
			k += n;//k == k + n
		}
		
		for (std::vector<std::string>::const_iterator i = items.begin(); i != items.end(); ++i) {//goes through all elements in items
			
			if (items[l] == "3.99") {//checks if an element equals to 3.99
				h++;//increases h by 1
			}
			l++;//increases l by 1
		}
		if (h > 1) {//if h is more than 1 run this
			r = h % 2;//r equals remainder of h/2
			s = ((h - r) / 2) + r;//s equals r plus the result of h-r/2
			new_price = s * 3.99;//new_price is s time 3.99
			savings = (h * 3.99) - new_price;//savings is h time 3.99 - new_price
			std::cout << "2-4-1 discount applied! Savings: " << char(156) << savings << std::endl;//prints the amount saved from 2-4-1 deal
		}
		total = k - savings;
		std::cout << "Total: " << char(156) << total << std::endl;//prints the total price
	}
	std::vector<std::string> add(std::vector<std::string> &vect1) {//declares add method for adding to the order
		items.push_back(vect1[2]);//adds the item price followed by the name
		items.push_back(vect1[1]);
		return items;//returns the items vector
	}
	std::vector<std::string> remove(std::vector<std::string>& vect1) {//declares remove method for removing from the order
		int n = 0;//declares n as int equal to 0
		int h = 0;//declares h as int equal to 0
		for (std::vector<std::string>::const_iterator i = items.begin(); i != items.end(); ++i) {//goes through all the element in items

			if (items[n] == vect1[1]) {//if items[1] equals the value of the second element of vect1 then run
				h = n - 1;//h equals the value of n minus 1
			}
			n++;//increase n by 1
		}
		items.erase(items.begin() + h);//delete the [h]th element from items
		items.erase(items.begin() + h);//delete the new [h]th element from items
		return items; //returns the items vector
	}
};
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
//including libaries needed for program usage

class item_list {//delcaring class item_list
public:
	std::vector<std::string> items;//delcaring items as vector of strings

	std::string toString() {//declares toString method to return a string
		return "";
	}
	
};

class Menu: public item_list {//delcaring class Menu from item_list
public:


	void toString(//declares toString method which takes all the menu item vectors and prints then in menu format
		std::vector<std::string> &vect1, 
		std::vector<std::string> &vect2, 
		std::vector<std::string> &vect3, 
		std::vector<std::string> &vect4, 
		std::vector<std::string> &vect5, 
		std::vector<std::string> &vect6, 
		std::vector<std::string> &vect7, 
		std::vector<std::string> &vect8, 
		std::vector<std::string> &vect9, 
		std::vector<std::string> &vect10, 
		std::vector<std::string> &vect11, 
		std::vector<std::string> &vect12) {
		std::string::size_type size;//declared for string to double conversion
		std::cout << std::fixed;//fixed an setprecision is used to set the number of decimal places printed for numbers
		std::cout << std::setprecision(2);
		std::cout << "----------------Appetisers----------------" << std::endl;//border for item type
		std::cout << "(1) " << vect1[1] << ": " << char(156) << std::stod(vect1[2], &size) << " " << vect1[3] + " cals " << vect1[4] << " " << vect1[5] << std::endl;
		std::cout << "(2) " << vect2[1] << ": " << char(156) << std::stod(vect2[2], &size) << " " << vect2[3] + " cals " << vect2[4] << " " << vect2[5] << std::endl;
		std::cout << "(3) " << vect3[1] << ": " << char(156) << std::stod(vect3[2], &size) << " " << vect3[3] + " cals " << vect3[4] << " " << vect3[5] << std::endl;
		std::cout << "----------------Main Dishes----------------" << std::endl;//border for item type
		std::cout << "(4) " << vect4[1] << ": " << char(156) << std::stod(vect4[2], &size) << " " << vect4[3] + " cals " << vect2[4] << std::endl;
		std::cout << "(5) " << vect5[1] << ": " << char(156) << std::stod(vect5[2], &size) << " " << vect5[3] + " cals " << vect5[4] << std::endl;
		std::cout << "(6) " << vect6[1] << ": " << char(156) << std::stod(vect6[2], &size) << " " << vect6[3] + " cals " << vect6[4] << std::endl;
		std::cout << "(7) " << vect7[1] << ": " << char(156) << std::stod(vect7[2], &size) << " " << vect7[3] + " cals " << vect7[4] << std::endl;
		std::cout << "----------------Beverages----------------" << std::endl;//border for item type
		std::cout << "(8) " << vect8[1] << ": " << char(156) << std::stod(vect8[2], &size) << " " << vect8[3] + " cals " << vect8[4] << "("+vect8[6]+"ml ," << vect8[7] + char(37) + " abv)" << std::endl;
		std::cout << "(9) " << vect9[1] << ": " << char(156) << std::stod(vect9[2], &size) << " " << vect9[3] + " cals " << vect9[4] << "(" + vect9[6] + "ml ," << vect9[7] + char(37) + " abv)" << std::endl;
		std::cout << "(10) " << vect10[1] << ": " << char(156) << std::stod(vect10[2], &size) << " " << vect10[3] + " cals " << vect10[4] << "(" + vect10[6] + "ml ," << vect10[7] + char(37) + " abv)" << std::endl;
		std::cout << "(11) " << vect11[1] << ": " << char(156) << std::stod(vect11[2], &size) << " " << vect11[3] + " cals " << vect11[4] << "(" + vect11[6] + "ml)" << std::endl;
		std::cout << "(12) " << vect12[1] << ": " << char(156) << std::stod(vect12[2], &size) << " " << vect12[3] + " cals " << vect12[4] << "(" + vect12[6] + "ml)" << std::endl;
		//prints each item vectors in format that user can understand, stod is used to convert price element from string to double so correct decimals are displayed
	}
	

	
};

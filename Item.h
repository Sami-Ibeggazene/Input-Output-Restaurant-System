#pragma once

class Item {//delcaring class Item
public:
		std::vector<std::string> items; //delcaring items as vector of strings
		double calories;//delcaring calories as a double
		std::string name;//delcaring name as a string
		double price;//delcaring price as a double

		std::string toString() {//declares toString method to return a string
			return "";
		}
};

class Appetiser : public Item {//delcaring class Appetiser from Item
public:
	bool sharable;//declares shareable as bool
	bool deal;//declares deal as bool

	std::string toString() {//declares toString method to return a string
		return "";
	}
};

class Maincourse : public Item {//delcaring class Maincourse from Item
public:

};

class Beverage : public Item {//delcaring class Beverage from Item
public:
	double abv;//declares abv as double
	double volume;//declares volume as double

	bool isAlcoholic() {
		return 0;
	}
	std::string toString() {//declares toString method to return a string
		return "";
	}
};
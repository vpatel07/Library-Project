#ifndef USERHEAD_H
#define USERHEAD_H

#include <iostream>
#include "BookHead.h"

class User { // User class and User Header File
private:
	std::string name, id; // Private Fields
	int num_books_borrowed; // Books borrowed

public:
	User(); // Empty Constructor
	User(std::string name, std::string id); // Parameterized Constructor

	void borrowBook(Book&); // Implements the book class and borrows book
	void returnBook(Book&); // Returns a book
	void printUserInfo(); // Prints all of the user fields
	std::string get_name(); // Get name function
	std::string get_id(); // Get Id Function

	~User(){}; // Null Destructor
};

#endif
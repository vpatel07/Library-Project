//
// Created by Vansh Patel on 4/27/23.
//

#ifndef OOP_PART_1_LIBRARY_H
#define OOP_PART_1_LIBRARY_H
#include <iostream>
#include <vector>
#include "BookHead.h"
#include "UserHead.h"

class Library { // Library class, fields are the book and user vectors
private: 
	std::vector<Book> books;
	std::vector<User> users;
public:
	void addBook(Book); // Adds a book to the vector
	void addUser(User); // Adds a user to the vector
	void printBookList(); // Print list function
	void printUserList();
	std::vector<Book> getBooks(); //getters
	std::vector<User> getUsers();

	~Library(){}; // Null destructors
};


#endif //OOP_PART_1_LIBRARY_H

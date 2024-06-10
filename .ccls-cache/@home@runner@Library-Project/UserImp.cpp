//
// Created by Vansh Patel on 4/27/23.
//
#include <iostream>
#include "BookHead.h"
#include "UserHead.h"

User::User() { // Initializes all of Uesr's fields
	name = "";
	id = "";
	num_books_borrowed = 0;
}

User::User(std::string userName, std::string userId) { // Sets the values of the parameters to the values of the field
	this -> name = userName;
	this -> id = userId;
	this -> num_books_borrowed = 0;
}

void User::borrowBook(Book & Book) { // Borrow book function
	++num_books_borrowed;
	Book.borrowBook(); // Extra: uses the borrow book function from the book class
}

void User::returnBook(Book & Book) { // Return book function
	--num_books_borrowed;
	Book.returnBook(); // Extra: uses the return book function from the book class
}

void User::printUserInfo() { // Prints all of the fields of user
	std::cout << "\n\n";
	std::cout << "----------------------------------" << std::endl;
	std::cout << "\t- Name: " << name;
	std::cout << "\n\t- ID: " << id;
	std::cout << "\n\t- Books Borrowed: " << num_books_borrowed;
	std::cout << "\n----------------------------------" << std::endl;
}

std::string User::get_name() { return name; } // Get function for name

std::string User::get_id() { return id; } // Get function for ID

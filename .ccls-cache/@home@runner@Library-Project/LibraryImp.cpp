//
// Created by Vansh Patel on 4/27/23.
//

#include "LibraryHead.h"
#include "UserHead.h"
#include "BookHead.h"
#include <iostream>

void Library::addBook(Book Book) { // Pushes back a book into the book vector
	books.push_back(Book);
}

void Library::addUser(User User) { // Pushes back a user into the user vector
	users.push_back(User);
}

void Library::printBookList() {
	for (int i = 0; i < books.size(); i++) { // Prints the title and author of each book
		std::cout << "\n-----------------------------------" << std::endl;
		std::cout << "Book: " << books[i].get_title() /*Title*/ << std::endl;
		std::cout << "Author: " << books[i].get_author() /*Author*/ << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
}

void Library::printUserList() {
	for (int i = 0; i < users.size(); i++) { // Prints the name and id of each user
		std::cout << "\n-----------------------------------" << std::endl;
		std::cout << "Username: " << users[i].get_name() /*Name*/ << std::endl;
		std::cout << "ID: " << users[i].get_id() /*ID*/<< std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
}

std::vector<Book> Library::getBooks() { return books; } // Get function for the book vector

std::vector<User> Library::getUsers() { return users; } // Get function for the user vector
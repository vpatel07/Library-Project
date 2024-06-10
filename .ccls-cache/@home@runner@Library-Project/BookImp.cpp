//
// Created by Vansh Patel on 4/27/23.
// Implementation file

#include "BookHead.h"
#include <iostream>

Book::Book() { // Empty constructor, initializes all of the fields
	title = "";
	author = "";
	isbn = "";
	num_copies = 0;
	num_borrowed = 0;
}

Book::Book(std::string bookTitle, std::string bookAuthor, std::string bookIsbn, int copies) { // Sets the fields to whatever the parameters of the constructor are
	title = bookTitle;
	author = bookAuthor;
	isbn = bookIsbn;
	num_copies = copies;
}

void Book::borrowBook() { // Borrow Book Function, decreases copies and increases the amount borrowed
	--num_copies;
	++num_borrowed;
}

void Book::returnBook() { // Returns a book, does the opposite of the above function
	++num_copies;
	--num_borrowed;
}

void Book::printBookInfo() { // Prints all of the fields in the book class
	std::cout << "\n\n";
	std::cout << "----------------------------------" << std::endl;
	std::cout << "\t- Book Name: " << title;
	std::cout << "\n\t- Author: " << author;
	std::cout << "\n\t- ISBN: " << isbn;
	std::cout << "\n\t- Copies Availiable: " << num_copies;
	std::cout << "\n\t- Copies Borrowed: " << num_borrowed << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

std::string Book::get_title() { return title; } // Get function for title

std::string Book::get_author() { return author; } // Get function for author

int Book::get_copies() { return num_copies; } // Get function for copies


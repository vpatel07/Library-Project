//
// Created by Vansh Patel on 4/27/23.
//

#ifndef OOP_PART_1_BOOK_H
#define OOP_PART_1_BOOK_H
#include <iostream>

class Book { // Header file
private:
	std::string title, author, isbn; // Private fields
	int num_copies, num_borrowed;

public:
	Book(); // Empty Constructor
	Book(std::string title, std::string author, std::string isbn, int copies); // Parameterized Consturctor

	void borrowBook(); // Methods for borrowing and returning books
	void returnBook();
	void printBookInfo(); // Prints all of the fields
	std::string get_title(); // Get method for title
	std::string get_author(); // Gets method for author
	int get_copies();

	~Book(){}; // Null Destructor
};


#endif //OOP_PART_1_BOOK_H

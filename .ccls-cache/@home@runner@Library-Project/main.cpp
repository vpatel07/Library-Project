/*
        - Name: Vansh Patel
        - Extra: Error Trap
        - Program Name: OOP Lab
    - Date: 5/19
*/

#include "BookHead.h"
#include "LibraryHead.h"
#include "UserHead.h"
#include <iostream>
#include <vector>

void printMenu(); // Method for printing the method

int main() {
  Library Library; // Creating a library object
  int userChoice; // Used to determine what to do

  while (true) {
    printMenu();
    std::cin >> userChoice;

    while (userChoice < 0 || userChoice > 8) { // Extra: error trap
      std::cout << "Bad Input: ";
      std::cin >> userChoice;
    }

    if (userChoice == 1) { // Choice 1: Borrow Book
      std::cout << "Please enter in your user name: ";
      std::string userName;

      std::cin.clear();
      std::getline(std::cin >> std::ws, userName); // Gets the whole word

      bool userFound = false; // Boolean for if the user is found
      int indexOfUser;

      for (int i = 0; i < Library.getUsers().size() /*size of user vector*/; i++) {
        if (userName == Library.getUsers()[i].get_name()) { // Getting the name of the current user in the list and comparing it to the name the user entered
          userFound = true; 
          indexOfUser = i;
          break;
        }
      }

      if (!userFound) { // Does this if user not found, sends back to menu
        std::cout << "User does not exist and therefore cannot borrow book, "
                     "sending back to menu";
      } else {
        std::cout << "What book do you want to borrow: ";
        std::string bookName;

        std::cin.clear();
        std::getline(std::cin >> std::ws, bookName); // Gets the name of the book the user wants to borrow

        bool bookFound = false; // boolean if the book is found or not
        int indexOfBook; 

        for (int i = 0; i < Library.getBooks().size(); i++) {
          if (bookName == Library.getBooks()[i].get_title()) { // Compares the title of the current book in the book vector to the title of the book that the user entered
            bookFound = true;
            indexOfBook = i;
            break;
          }
        }

        if (!bookFound) { // Does this if the book isnt found
          std::cout << "Book Not Found, sending you to menu" << std::endl;
        } else {
          if (Library.getBooks()[indexOfBook].get_copies() <= 0) { // Checks if there are any available copies
            std::cout << "Book cannot be borrowed, sending back to menu: ";
          } else {
            std::cout << "Borrowing " // Prints out relavent user information like the title of the book and whos borrwoing it
                      << Library.getBooks()[indexOfBook].get_title() << " for "
                      << Library.getUsers()[indexOfUser].get_name() << "\n\n"
                      << std::endl;

            Library.getUsers()[indexOfUser].borrowBook(Library.getBooks()[indexOfBook]); // Actually borrows the book under the user's name
          }
        }
      }

    } else if (userChoice == 2) { // Choice 2: Return book
      std::cout << "Please enter in your user name: ";
      std::string userName;

      std::cin.clear();
      std::getline(std::cin >> std::ws, userName);

      bool userFound = false; // Boolean for if the user is found
      int indexOfUser;

      for (int i = 0; i < Library.getUsers().size(); i++) { // Searches for the user, userFound is true if it is found
        if (userName == Library.getUsers()[i].get_name()) { // Gets the current name for the current user object
          userFound = true;
          indexOfUser = i;
          break;
        }
      }
      if (!userFound) { // Does this if the user isnt found
        std::cout << "User does not exist and therefore cannot return book, "
                     "sending back to menu";
      } else {
        std::cout << "What book do you want to return: ";
        std::string bookName; 

        std::cin.clear();
        std::getline(std::cin >> std::ws, bookName); // Gets the user's book that the user wants

        bool bookFound = false;
        int indexOfBook;

        for (int i = 0; i < Library.getBooks().size(); i++) { // Searches the book vector for the book that the user wants to return
          if (bookName == Library.getBooks()[i].get_title()) { // Specifically looking for the title
            bookFound = true;
            indexOfBook = i;
            break;
          }
        }

        if (!bookFound) {
          std::cout << "Book Not Found, sending you to menu" << std::endl;
        } else { // Return statement with relavent informatoin
          std::cout << "Returning "
                    << Library.getBooks()[indexOfBook].get_title() << " for "
                    << Library.getUsers()[indexOfUser].get_name() << std::endl;

          Library.getUsers()[indexOfUser].returnBook(Library.getBooks()[indexOfBook]); // Returns the book under the users name
        }
      }
    } else if (userChoice == 3) { //Choice 3: Entering in a User
      std::string name, id;

      std::cout << "What is your name: ";
      std::cin.clear();

      std::getline(std::cin >> std::ws, name); // Gets name

      std::cout << "What is the ID of the user: ";
      std::cin >> id;

      User CurrUser(name, id); // Creates a prototype user object

      CurrUser.printUserInfo(); // Prints all of the relavent info

      std::cout << "\nPlease confirm this information is correct (y/n): ";
      char confirm; // Confirmation message

      std::cin >> confirm;

      if (confirm == 'y') // Adds the user to the user database
        Library.addUser(CurrUser);
    } else if (userChoice == 4) { // Choice 4: Adding a New Book
      std::string bookName, authorName, isbn;
      int copies;

    // The next few lines get the relavent information for a book
      std::cout << "What is the book name: ";

      std::getline(std::cin >> std::ws, bookName);

      std::cout << "What is the authorName: ";
      std::cin.clear();

      std::getline(std::cin >> std::ws, authorName);

      std::cout << "What is the ISBN: ";
      std::cin >> isbn;

      std::cout << "How many copies exist: ";
      std::cin >> copies;

      Book CurrBook(bookName, authorName, isbn, copies); // Creates a book prototype object

      std::cout << "Would you like to review the book info before commmitting "
                   "it to the list (t/f) you have to review if you want to commit: "; // Confirmation message
      char seeBook;

      std::cin >> seeBook;

      if (seeBook == 't') {
        CurrBook.printBookInfo(); // Prints all of the book's information

        std::cout << "\nIs this information good to be added into the library "
                     "(y/n): ";
        char shouldEnter;

        std::cin >> shouldEnter; // Confirms if the book should be added to the database

        if (shouldEnter == 'y') { // Adds hte book to the database
          Library.addBook(CurrBook);
        }
      } else {
        std::cout << "Information will not be committed";
      }
    } else if (userChoice == 5) { // Option 5: Seeing all of the Books
      std::cout << "Would you like a detailed view or a simple view (d/s): ";
      char view;

      std::cin >> view;

      if (view == 'd') { // Detailed view, prints all of the book's information
        for (Book Book : Library.getBooks())
          Book.printBookInfo();
      } else {
        Library.printBookList(); // Prints a simplied list of the book's information
      }
    } else if (userChoice == 6) { // Choice 6: Seeing all usres
      std::cout << "Would you like a detailed view or a simple view (d/s): ";
      char view;

      std::cin >> view;

      if (view == 'd') { // Detailed view, see all fields inside of the user class
        for (User User : Library.getUsers())
          User.printUserInfo();
      } 
    else { // Simplified list of user information
        Library.printUserList();
      }
    } else if (userChoice == 7) { // Choice 7: Exit
      break;
    }
  }
}

void printMenu() { // Menu Method, just prints out the menu
  std::cout << "----------------------------------" << std::endl;
  std::cout << "   Welcome to the MCVTS Library   " << std::endl;
  std::cout << "----------------------------------" << std::endl;

  std::cout << "Would you like to: "
               "\n\t1) Borrow a Book\n"
               "\t2) Return a Book"
               "\n\t3) Enter in a User"
               "\n\t4) Enter in a book"
               "\n\t5) See all Books"
               "\n\t6) See all Users"
               "\n\t7) Exit"
            << std::endl;
}
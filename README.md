This C program is designed as a library management system to facilitate efficient organization and management of library resources.
This C program is a library management system enabling functions like adding, deleting, modifying books, along with searching and advanced searching. It includes sorting books by title, price, or publication date, login, saving changes, and quitting with options to discard changes or return to the main menu.

 Here's a detailed description of each function within the project:

1. `int isvalid(char s[])`: This function checks if a given string contains only digits, used for validating inputs like ISBN and year.

2. `int Login()`: Manages the login process by prompting users for a username and password, then verifies them against credentials stored in a file named "credentials.txt".

3. `int LOAD()`: Loads book information from a file named "books.txt" into an array of book structures (`x[]`) for further processing.

4. `void Search()`: Allows users to search for a book by its ISBN, providing details if found, otherwise indicating that the book is not in the library.

5. `void Advanced_Search()`: Provides advanced search functionality based on book titles, allowing users to search for books with partial title matches.

6. `void Add_Book()`: Enables users to add new books to the library by inputting ISBN, title, author, quantity, price, and publication date.

7. `void Delete_book()`: Allows users to delete a book from the library by providing its ISBN.

8. `void MODIFY()`: Facilitates modifications to existing book records, enabling changes to title, author, quantity, price, and publication date based on user input.

9. `void sortByTitle()`, `void sortByPrice()`, `void sortByDate()`: Functions for sorting books in the library by title, price, or publication date, respectively.

10. `void print()`: Provides options to users for sorting and printing the library's books based on title, price, or publication date.

11. `void SAVE()`: Saves the current library data back to the file "books.txt" for persistent storage.

12. `int Menu()`: Serves as the main menu function, allowing users to navigate through various functionalities like login, adding, deleting, modifying, searching, printing, saving changes, and quitting the program.

13. `void Quit()`: Enables users to quit the program with the option to discard changes or return to the main menu.

The combination of these functions provides users with a comprehensive library management system, offering features for efficient cataloging, manipulation, and retrieval of library resources.

#include <stdio.h>
#include <string.h>

typedef struct _Book {
	char *title;
	char *author;
	int pages;
} Book;

void initialize_book(Book *book, char *title_value, char *author_value, int pages_value) {
	book->title = strdup(title_value);
	book->author = strdup(author_value);
	book->pages = pages_value;
}

// void initialize_multiple_books(Books *book_array, char *title_array, char *author_array, int *pages_array) {
// 	for(int i = 0; i < sizeof(book_array) / sizeof(Book));
// }

void print_book(Book *book) {
	printf("Book title: %s\n", book->title);
	printf("Book author: %s\n", book->author);
	printf("Book pages: %d\n\n", book->pages);
}

int main(int argc, char *argv[]) {
	Book book1, book2, book3;
	Book books[3] = {book1, book2, book3};
	char *titles[3] = {"title 1", "title 2", "tales of mahmut"};
	char *authors[3] = {"torriatte", "yvz", "mahmut"};
	int pages[3] = {26, 52, 61};
	printf("size: %d\n", sizeof(pages) / sizeof(int));
	printf("size: %d\n", sizeof(Book));
	// initialize_multiple_books(&books, &titles, &authors, &pages);
	// initialize_book(&book1, "test title", "yvz", 31);
	// initialize_book(&book2, "book 2", "torriatte", 523);
	// initialize_book(&book3, "tales of mahmut", "mahmut", 61);
	// print_book(&book1);
	// print_book(&book2);
	// print_book(&book3);

	// use -> when accessing struct members with pointer reference, else use . operator.
	// book.title = "test title";
	// book.author = "yvz";
	// book.pages = 31;
	// printf("Book title: %s\n", book.title);

	return 0;
}

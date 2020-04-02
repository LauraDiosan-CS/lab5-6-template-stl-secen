#include "Book.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>

void tests()
{
	{
		//Book tests
		Book e = Book(1, 0, "Ion");
		Book e2 = Book(2, 10, "Baltagul");
		assert(e.getCode() == 1);
		assert(e.getPrice() == 0);
		assert(strcmp(e.getName(), "Ion") == 0);
		assert(e != e2);
		assert(e == e);
		//Repo tests
		Repo<Book> rep = Repo<Book>();
		assert(rep.getAll().size() == 0);
		rep.addItem(e);
		assert(rep.getAll().size() == 1);
		rep.addItem(e2);
		assert(rep.getAll().size() == 2);
	}
}
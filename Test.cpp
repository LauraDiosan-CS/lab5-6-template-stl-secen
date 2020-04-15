#include "Book.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>

void tests()
{
	{
		//Book tests
		Book e = Book("asdf", 0, "Ion");
		Book e2 = Book("dds", 10, "Baltagul");
		assert(strcmp(e.getAuthor(),"asdf")==0);
		assert(e.getPubDate() == 0);
		assert(strcmp(e.getName(), "Ion") == 0);
		assert(e != e2);
		assert(e == e);
		//Repo tests
		Repo<Book> rep;
		assert(rep.getAll().size() == 0);
		rep.addItem(e);
		assert(rep.getAll().size() == 1);
		rep.addItem(e2);
		assert(rep.getAll().size() == 2);
	}
}
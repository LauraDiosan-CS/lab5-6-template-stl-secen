#include "Book.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>
#include "FileRepo.h"
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
		rep.modifyElement(Book("ok", 0, "Ion"));
		Book b = rep.getAll().top();
		assert(strcmp(b.getAuthor(),"ok")==0);
		assert(rep.getAll().size() == 1);
		rep.addItem(e2);
		assert(rep.getAll().size() == 2);
		rep.setBorrowedStatus("Ion", true);
		assert(rep.getBorrowedStatus("Ion") == true);
		rep.removeElementByName("Ion");
		assert(rep.getAll().size()==1);
		FileRepo<Book> frepo("testing.txt");
		frepo.addItem(e);
		frepo.setBorrowedStatus("Ion", true);
		frepo.saveToFile();
		frepo.clear();
		frepo.loadFromFile();
		assert(frepo.getBorrowedStatus("Ion") == true);
		assert(frepo.getSize() == 1);
	}
}
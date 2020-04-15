#include "Service.h"
#include <algorithm>

Service::Service()
{
	rep = Repo<Book>();
}

Service::Service(Repo<Book>& rp)
{
	this->rep = rp;
}

Service::~Service()
{
}

void Service::addElement(const char* asdf, unsigned int sum, const char* name)
{
	Book e = Book(asdf, sum, name);
	rep.setBorrowedStatus(e.getName(), false);
	this->rep.addItem(e);
}

void Service::removeElementAtPos(int i)
{
	rep.removeElementAtPos(i);
}

bool Service::borrow(const char* title)
{
	if (!rep.getBorrowedStatus(title))
	{
		rep.setBorrowedStatus(title,true);
		return true;
	}
	return false;
}

bool Service::isBorrowed(const char* title)
{
	return rep.getBorrowedStatus(title);
}

std::priority_queue<Book> Service::getArray()
{
	return this->rep.getAll();
}

unsigned int Service::getSize()
{
	return this->rep.getSize();
}

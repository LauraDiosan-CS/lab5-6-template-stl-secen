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
	borrowedStatus[e.getName()]=false;
	this->rep.addItem(e);
}

void Service::removeElementAtPos(int i)
{
	rep.removeElementAtPos(i);
}

bool Service::borrow(const char* title)
{
	if (!borrowedStatus[title])
	{
		borrowedStatus[title] = true;
		return true;
	}
	return false;
}

bool Service::isBorrowed(const char* title)
{
	return borrowedStatus[title];
}

std::priority_queue<Book> Service::getArray()
{
	return this->rep.getAll();
}

unsigned int Service::getSize()
{
	return this->rep.getSize();
}

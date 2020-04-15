#pragma once
#include "Book.h"
#include "Repo.h"
#include <unordered_map>
class Service
{
private:
	Repo<Book> rep;
	std::unordered_map<std::string, bool> borrowedStatus;
public:
	Service();
	Service(Repo<Book>& rp);
	~Service();
	void addElement(const char* asdf, unsigned int sum, const char* name);
	void removeElementAtPos(int i);
	bool borrow(const char* title);
	bool isBorrowed(const char* title);
	std::priority_queue<Book> getArray();
	unsigned int getSize();
};



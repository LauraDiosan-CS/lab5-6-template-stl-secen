#pragma once
#include "Book.h"
#include "FileRepo.h"
#include <unordered_map>
#include <string>
class Service
{
private:
	std::string filename;
	FileRepo<Book> rep;
public:
	Service();
	Service(std::string fname);
	Service(FileRepo<Book>& rp);
	~Service();
	void addElement(const char* asdf, unsigned int sum, const char* name);
	void removeElementAtPos(int i);
	bool borrow(const char* title);
	bool isBorrowed(const char* title);
	bool unborrow(const char* title);
	std::priority_queue<Book> getArray();
	unsigned int getSize();
	void readFromFile();
	void writeToFile();
	void removeElementByName(const char* title);
	void modifyElement(const char* asdf, unsigned int sum, const char* name);
};



#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
class Book
{
private:
	char* m_author;
	unsigned int m_publicationDate;
	char* m_name;
public:
	//essential
	Book();
	~Book();
	Book(const Book& copy);
	Book(const char* asdf, unsigned int newPrice, const char* name);
	Book& operator = (const Book& exp);
	//non-essential
	bool operator == (const Book& exp);
	bool operator != (const Book& exp);
	char* getAuthor();
	unsigned int getPubDate();
	char* getName();
	void setName(const char* newName);
	void setAuthor(const char* newAuthor);
	void setPubDate(unsigned int pubdate);
	bool operator < (const Book& other) const;
	friend std::ostream & operator << (std::ostream& out, const Book& c);
	friend std::istream& operator >> (std::istream &in, Book& c);
};


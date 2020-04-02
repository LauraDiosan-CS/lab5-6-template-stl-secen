#pragma once
#include <unordered_map>
#include <string>
class Book
{
private:
	unsigned int m_code;
	unsigned int m_price;
	char* m_name;
public:
	//essential
	Book();
	~Book();
	Book(const Book& copy);
	Book(unsigned int newCode, unsigned int newPrice, const char* name);
	Book& operator = (const Book& exp);
	//non-essential
	bool operator == (const Book& exp);
	bool operator != (const Book& exp);
	unsigned int getCode();
	unsigned int getPrice();
	char* getName();
	bool operator < (const Book& other) const;
};


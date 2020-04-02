#include "Book.h"
#include <stdexcept>
#include <cstring>
Book::Book()
{
	m_code = 0;
	m_price = 0;
	m_name = new char[2];
	strcpy_s(m_name, 2, "a");
}

Book::~Book()
{
	if (m_name != nullptr)
		delete[] m_name;
}

Book::Book(const Book& copy)
{
	this->m_code = copy.m_code;
	this->m_price = copy.m_price;
	char* aux = new char[strlen(copy.m_name) + 1];
	strcpy_s(aux, strlen(copy.m_name) + 1, copy.m_name);
	this->m_name = aux;
	/*
	if (this->m_name == nullptr)
		m_name = new char[strlen(copy.m_name) + 1];
	if (strlen(m_name) < strlen(copy.m_name))
	{
		delete[] m_name;
		m_name = new char[strlen(copy.m_name)+1];
	}
	if (copy.m_name != nullptr)
		strcpy_s(m_name, strlen(copy.m_name) + 1, copy.m_name);
	else
		this->m_name = nullptr;*/
}

Book::Book(unsigned int newCode, unsigned int newPrice, const char* name)
{
	m_code = newCode;
	m_price = newPrice;
	m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);
}

Book& Book::operator=(const Book& exp)
{
	m_code = exp.m_code;
	m_price = exp.m_price;
	if (strlen(m_name) < strlen(exp.m_name))
	{
		delete[] m_name;
		m_name = new char[strlen(exp.m_name) + 1];
	}
	strcpy_s(m_name, strlen(exp.m_name) + 1, exp.m_name);
	return *this;
}

bool Book::operator==(const Book& exp)
{
	if (m_code != exp.m_code)
		return false;
	if (m_price != exp.m_price)
		return false;
	if (strcmp(m_name, exp.m_name))
		return false;
	return true;
}

bool Book::operator!=(const Book& exp)
{

	return !(*this == exp);
}

unsigned int Book::getCode()
{
	return this->m_code;
}

unsigned int Book::getPrice()
{
	return this->m_price;
}

char* Book::getName()
{
	return m_name;
}

bool Book::operator < (const Book& other) const
{
	return (this->m_code < other.m_code);
}


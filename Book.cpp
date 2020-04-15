#include "Book.h"
#include <stdexcept>
#include <cstring>
Book::Book()
{
	m_author = new char[2];
	strcpy_s(m_author, 2, "a");
	m_publicationDate = 0;
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
	this->m_publicationDate = copy.m_publicationDate;
	char* aux = new char[strlen(copy.m_name) + 1];
	strcpy_s(aux, strlen(copy.m_name) + 1, copy.m_name);
	this->m_name = aux;
	char* aux2 = new char[strlen(copy.m_author) + 1];
	strcpy_s(aux2, strlen(copy.m_author) + 1, copy.m_author);
	this->m_author = aux2;
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

Book::Book(const char* author, unsigned int newPrice, const char* name)
{
	m_publicationDate = newPrice;
	m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);
	m_author = new char[strlen(author) + 1];
	strcpy_s(m_author, strlen(author) + 1, author);
}

Book& Book::operator=(const Book& exp)
{
	m_publicationDate = exp.m_publicationDate;
	if (strlen(m_name) < strlen(exp.m_name))
	{
		delete[] m_name;
		m_name = new char[strlen(exp.m_name) + 1];
	}
	strcpy_s(m_name, strlen(exp.m_name) + 1, exp.m_name);
	if (strlen(m_author) < strlen(exp.m_author))
	{
		delete[] m_author;
		m_author = new char[strlen(exp.m_author) + 1];
	}
	strcpy_s(m_author, strlen(exp.m_author) + 1, exp.m_author);
	return *this;
}

bool Book::operator==(const Book& exp)
{

	if (m_publicationDate != exp.m_publicationDate)
		return false;
	if (strcmp(m_name, exp.m_name))
		return false;
	if (strcmp(m_author, exp.m_author))
		return false;
	return true;
}

bool Book::operator!=(const Book& exp)
{

	return !(*this == exp);
}

char* Book::getAuthor()
{
	return this->m_author;
}

unsigned int Book::getPubDate()
{
	return this->m_publicationDate;
}

char* Book::getName()
{
	return m_name;
}

bool Book::operator < (const Book& other) const
{
	return (this->m_publicationDate < other.m_publicationDate);
}


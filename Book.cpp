#include "Book.h"
#include <stdexcept>
#include <cstring>
#include <algorithm>
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

void Book::setName(const char* newName)
{
	delete[] this->m_name;
	this->m_name = new char[strlen(newName)+1];
	strcpy_s(this->m_name,strlen(newName)+1, newName);
}

void Book::setAuthor(const char* newAuthor)
{
	delete[] this->m_author;
	this->m_author = new char[strlen(newAuthor) + 1];
	strcpy_s(this->m_author,strlen(newAuthor)+1, newAuthor);
}

void Book::setPubDate(unsigned int pubdate)
{
	m_publicationDate = pubdate;
}

bool Book::operator < (const Book& other) const
{
	return (this->m_publicationDate < other.m_publicationDate);
}

std::ostream& operator<<(std::ostream& out, const Book& c)
{
	out << c.m_author << ';' << c.m_publicationDate << ';' << c.m_name;
	return out;
}

std::istream& operator>>(std::istream &is, Book& c)
{
	std::string author,pubdate,name;
	std::getline(is, author, ';');
	std::getline(is, pubdate, ';');
	std::getline(is, name, ';'); 
	author.erase(std::remove(author.begin(), author.end(), '\n'), author.end()); //remove any trailing newlines
	c.setAuthor(author.c_str());
	c.setPubDate(std::stoi(pubdate));
	name.erase(std::remove(name.begin(), name.end(), '\n'), name.end()); // remove any trailing newlines
	c.setName(name.c_str());
	if (false)
		is.setstate(std::ios::failbit);
	return is;

}

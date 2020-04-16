
#include "Console.h"
#include <iostream>
#include <string>
#include <algorithm>

void Console::showMenu()
{
	std::cout << "\n";
	std::cout << "1.Add Book\n";
	std::cout << "2.Modify Book\n";
	std::cout << "3.Remove Book\n";
	std::cout << "4.List All Books\n";
	std::cout << "5.Borrow Book\n";
	std::cout << "6.Return Book\n";
	std::cout << "0.Exit\n";
	std::cout << "Option: ";
}

void Console::handleInput()
{
	unsigned choice;
	std::cin >> choice;
	switch (choice)
	{
	case 0:
		this->isClosed = 1;
		break;
	case 1:
		this->handleAdd();
		break;
	case 2:
		this->handleModify();
		break;
	case 3:
		this->handleRemove();
		break;
	case 4:
		this->handleListAll();
		break;
	case 5:
		this->handleBorrowBook();
		break;
	case 6:
		this->handleReturnBook();
		break;
	}
}
void Console::handleReturnBook()
{
	std::string input;
	std::cout << "Please enter the name of the book: ";
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	if (!(this->m_sev.unborrow(input.c_str())))
	{
		std::cout << "Can't unborrow book!";
	}
}
void Console::handleBorrowBook()
{
	std::string input;
	std::cout << "Please enter the name of the book: ";
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	if (!(this->m_sev.borrow(input.c_str())))
	{
		std::cout << "Can't borrow book!";
	}
}
void Console::handleAdd()
{
	Book p = this->handleCreatePlayer();
	this->m_sev.addElement(p.getAuthor(), p.getPubDate(), p.getName());
	//TODO: Implement
}

void Console::handleModify()
{
	unsigned int pos = 0;
	Book p = this->handleCreatePlayer();
	this->m_sev.modifyElement(p.getAuthor(), p.getPubDate(), p.getName());
	//this->m_sev.modifyElement(pos, p.getAuthor(), p.getPubDate(), p.getName());
	//TODO: Implement
}

void Console::handleListAll()
{
	std::priority_queue<Book> playerArray = m_sev.getArray();
	
	unsigned int arrSize = m_sev.getSize();
	while (!playerArray.empty())
	{
		Book bf = playerArray.top();
		printPlayer(bf);
		std::cout << "\n";
		playerArray.pop();
	}
}

void Console::handleRemove()
{
	std::string str;
	std::cout << "\nName of the book: ";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	m_sev.removeElementByName(str.c_str());
}

Book Console::handleCreatePlayer()
{
	std::string title,author;
	unsigned int noOfWins;
	std::cout << "\nBook Publication Date: ";
	std::cin >> noOfWins;
	std::cout << "\nBook Title: ";
	std::getline(std::cin, title);
	std::getline(std::cin, title);
	std::cout << "\nBook Author: ";
	std::getline(std::cin, author);
	return Book(author.c_str(), noOfWins, title.c_str());
}

void Console::printPlayer(Book& pl)
{
	std::cout << "Title: " << pl.getName() << " Author: " << pl.getAuthor() << " Publication Date: " << pl.getPubDate();
	if (m_sev.isBorrowed(pl.getName()))
		std::cout << " TAKEN";
}


Console::Console()
{
	this->m_sev = Service("debug.txt");
	this->isClosed = false;
}

Console::~Console()
{
}

Console::Console(Service s)
{
	this->m_sev = s;
	this->isClosed = false;
}

void Console::run()
{
	m_sev.readFromFile();
	while (!(this->isClosed))
	{

		showMenu();
		handleInput();
		m_sev.writeToFile();
	}
}

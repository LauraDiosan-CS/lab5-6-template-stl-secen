#pragma once
#include "Service.h"
#include "Book.h"
class Console
{
private:
	Service m_sev;
	bool isClosed;
	void showMenu();
	void handleInput();
	void handleAdd();
	void handleModify();
	void handleListAll();
	void handleRemove();
	void handleBorrowBook();
	Book handleCreatePlayer();
	void printPlayer(Book& pl);
	void handleReturnBook();
public:
	Console();
	~Console();
	Console(Service s);
	void run();
};

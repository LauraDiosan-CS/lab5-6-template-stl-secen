#pragma once
#include <queue>
#include <unordered_map>
template <class T>
class Repo
{
protected:
	std::priority_queue<T> entities;
	std::unordered_map<std::string, bool> borrowedStatus;
public:
		Repo() { entities = std::priority_queue<T>(); }
	   ~Repo() {}
	   void addItem(T s){this->entities.push(s);}
	   std::priority_queue<T> getAll() {return this->entities;}
	   unsigned int getSize() { return entities.size(); }
	   void setBorrowedStatus(const char* name, bool value) { borrowedStatus[name] = value; }
	   bool getBorrowedStatus(const char* name) { return borrowedStatus[name]; }
	   void removeElementAtPos(int i) { entities.pop(); }
	   void clear() { while (!entities.empty()) { entities.pop(); } borrowedStatus.clear(); }
};


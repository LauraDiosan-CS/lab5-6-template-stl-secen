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
	   void removeElementByName(const char* title) 
	   { 
			std::priority_queue<T> aux; 
			while (!entities.empty()) 
			{
				T auxElem;
				auxElem = entities.top();
				entities.pop();
				if (strcmp(auxElem.getName(), title) == 0)
					continue;
				aux.push(auxElem);
			} 
			entities = aux;
		}
	   void modifyElement(T b)
	   {
		   std::priority_queue<T> aux;
		   while (!entities.empty())
		   {
			   T auxElem;
			   auxElem = entities.top();
			   entities.pop();
			   if (strcmp(auxElem.getName(), b.getName()) == 0)
			   {
				   aux.push(b);
				   continue;
			   }
			   aux.push(auxElem);
		   }
		   entities = aux;
	   }
};


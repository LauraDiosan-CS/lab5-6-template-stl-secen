#pragma once
#include <queue>
template <class T>
class Repo
{
private:
	std::priority_queue<T> entities;
public:
		Repo(){ }
	   ~Repo() {}
	   void addItem(T s){this->entities.push(s);}
	   std::priority_queue<T>getAll() {return this->entities;}

};


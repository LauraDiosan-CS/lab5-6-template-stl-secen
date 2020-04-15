#pragma once
#include "Repo.h"
#include <cstring>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>
template <class T>
class FileRepo :
	public Repo<T>
{
private:
	char* m_filename;
	char* m_filename2;
public:
	FileRepo() 
	{
		std::string newFilename = "debug.txt";
		m_filename = new char[strlen(newFilename.c_str()) + 1];
		strcpy_s(m_filename, strlen(newFilename.c_str())+1, newFilename.c_str());
		std::string newFilename2 = "debug2.txt";
		m_filename2 = new char[strlen(newFilename2.c_str()) + 1];
		strcpy_s(m_filename2, strlen(newFilename2.c_str())+1, newFilename2.c_str());
	};
	FileRepo(const char* newFilename)
	{
		m_filename = new char[strlen(newFilename)+1];
		strcpy_s(m_filename, strlen(newFilename)+1,newFilename);
		std::string newFilename2 = "debug2.txt";
		m_filename2 = new char[strlen(newFilename2.c_str()) + 1];
		strcpy_s(m_filename2, strlen(newFilename2.c_str())+1, newFilename2.c_str());
	}
	FileRepo(const char* newFilename,const char* newFilename2) {
		m_filename = new char[strlen(newFilename) + 1];
		strcpy_s(m_filename, strlen(newFilename) + 1, newFilename);
		m_filename2 = new char[strlen(newFilename2) + 1];
		strcpy_s(m_filename2, strlen(newFilename2) + 1, newFilename2);
	}
	~FileRepo() {}
	void saveToFile()
	{
		std::ofstream fout(m_filename);
		std::ofstream fout2(m_filename2);
		std::priority_queue<T> q = this->getAll();
		int size = this->getSize();
		fout << size<<'\n';
		while(!q.empty())
		{
			T elem = q.top();
			fout << elem << '\n';
			q.pop();
		}
		for (auto elem : this->borrowedStatus)
		{
			fout2 << elem.first << "\n" << elem.second<<"\n";
		}
	};
	void loadFromFile()
	{
		std::ifstream fin(m_filename);
		std::ifstream fin2(m_filename2);
		int size;
		fin >> size;
		this->clear();
		for (int i = 0; i < size; i++)
		{
			T elem;
			fin >> elem;
			this->addItem(elem);
		}
		std::string str;
		std::string val1;
		std::string val2; 
		bool isOdd = true;
		while (getline(fin2, str))
		{
			if (isOdd)
				val1 = str;
			else
			{
				val2 = str;
				if (val2 == "0")
					this->setBorrowedStatus(val1.c_str(), false);
				else
					this->setBorrowedStatus(val1.c_str(), true);
			}
			isOdd = !isOdd;
		}
	};
};


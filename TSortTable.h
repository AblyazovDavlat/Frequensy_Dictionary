#pragma once
#include "TRecord.h"
class TSortTable
{
	int MaxSize;
	TRecord *array;
	int curr;
	int dataCount;
public:
	TSortTable(int _size);
	~TSortTable();
	int GetDataCount();
	bool IsEmpty();
	bool IsFull();

	bool Find(TKey _key);
	void InsRec(TRecord rec);
	TRecord GetRec();
	void Sorting();
//-------------------------------------------------------------------------------------------
	void Print();
	void Reset();
	void GoNext();
	bool IsEnd();
//-------------------------------------------------------------------------------------------
	void Write(char* pFileName);
	void Read(char* pFileName);
};


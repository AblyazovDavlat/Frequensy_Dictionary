#include "stdafx.h"
#include "TSortTable.h"


TSortTable::TSortTable(int _size)
{
	MaxSize = _size;
	array = new TRecord[MaxSize];
	dataCount = 0;
	curr = -1;
}

TSortTable::~TSortTable()
{
	delete[] array;
}

int TSortTable::GetDataCount()
{
	return dataCount;
}
bool TSortTable::IsEmpty()
{
	return (dataCount == 0);
}
bool TSortTable::IsFull()
{
	return (dataCount == MaxSize);
}


bool TSortTable::Find(TKey _key)
{
	int l = 0, r = dataCount - 1;
	int m = 0;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (array[m].GetKey() == _key)
		{
			curr = m;
			return true;
		}
		if (array[m].GetKey() < _key)
			r = m - 1;
		else
			l = m + 1;
	}
	curr = l;
	return false;
}
void TSortTable::InsRec(TRecord rec)
{
	if (IsFull()) return ;
	if (!Find(rec.GetKey()))
	{
		dataCount++;
		for (int i = dataCount - 1; i > curr; i--)
		{
			array[i] = array[i - 1];
		}
		array[curr] = rec;
	}
	else
	{
		array[curr].SetValue(array[curr].GetValue() + 1);
	}
}
TRecord TSortTable::GetRec()
{
	if (curr >= 0 && curr < MaxSize)
		return array[curr];
}
void TSortTable::Read(char* pFileName)
{
	string str = "";
	ifstream TxtFile(pFileName);

	if (!TxtFile.fail())
	{
		while (!TxtFile.eof()) str += TxtFile.get();
		TxtFile.close();
	}
	else cout << "File doesn't exist" << endl;

	for (int i = 0; i < str.length(); i++)
	{
		char tmp = str[i];
		if (((int)tmp >= 65) && ((int)tmp <= 90))
		{
			tmp += 32;
		}
		str[i] = tmp;
	}

	string tmp = "";
	TRecord rec;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			rec.SetKey(tmp);
			rec.SetValue(1);
			InsRec(rec);
			tmp = "";
		}
		else
		{
			if (str[i] != '.' && str[i] != ';' && str[i] != ',' && str[i] != ':' && str[i] != '!' && str[i] != '?')
			tmp += str[i];
		}
	}
}

//printing

void TSortTable::Reset()
{
	curr = 0;
}

void TSortTable::GoNext()
{
	curr++;
}

bool TSortTable::IsEnd()
{
	return curr == dataCount;
}

void TSortTable::Print()
{
	for (curr = dataCount - 1; curr >= 0; curr--)
	{
		cout << GetRec().GetKey() << " ";
		cout << GetRec().GetValue() << endl;
	}
}
void TSortTable::Write(char* pFileName)
{
	ofstream fout(pFileName);
	for (curr = dataCount - 1; curr>=0; curr--)
	{
		fout << GetRec().GetKey() << " ";
		fout << GetRec().GetValue() << endl;
	}
	fout.close();
}
void TSortTable::Sorting()
{
	TRecord tmp;
	for (int i = 0; i < dataCount; i++)
	{
		for (int j = dataCount - 1; j > i;j--)
			if (array[j].GetValue() < array[j-1].GetValue())
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
	}
}

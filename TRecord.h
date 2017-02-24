#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

typedef string TKey;
typedef int TValue;

class TRecord
{
	TKey key;
	TValue value;
public:
	TRecord(TKey _key, TValue _value);
	TRecord();
	~TRecord();
	void SetKey(TKey _key);
	TKey GetKey();
	void SetValue(TValue _value);
	TValue GetValue();


};


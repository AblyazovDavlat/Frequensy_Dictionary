#include "stdafx.h"
#include "TRecord.h"

//construtrors
TRecord::TRecord(TKey _key, TValue _value)
{
	key = _key;
	value = _value;
}
TRecord::TRecord()
{
	key = " ";
	value = 0;
}

TRecord::~TRecord()
{
}

void TRecord::SetKey(TKey _key)
{
	key = _key;
}
TKey TRecord::GetKey()
{
	return key;
}
void TRecord::SetValue(TValue _value)
{
	value = _value;
}
TValue TRecord::GetValue()
{
	return value;
}


// FrequencyDictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TSortTable.h"

int main(int argc, char* argv[])
{

	TSortTable table(1000);
	table.Read(argv[1]);
	table.Sorting();
	//table.Print();
	table.Write(argv[2]);
	return 0;
}


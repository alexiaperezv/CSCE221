#include "CSVEditor.hpp"
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CSVEditor::CSVEditor(string &inputPath, string &rosterPath, string &outputPath, regex expr, int m)
{
	this->input = ifstream(inputPath);
	this->roster = ifstream(rosterPath);
	this->output = ofstream(outputPath);
	this->regexPattern = expr;
	this->hashTable = new HashTable<string>(m);
}

CSVEditor::~CSVEditor()
{
	input.close();
	roster.close();
	output.close();
	delete hashTable;
}

void CSVEditor::readCSVToTable()
{
	smatch m;
	if (!input.is_open())
	{
		return;
	}
	while (!input.eof())
	{
		string line;
		getline(input, line);
		regex_search(line, m, regexPattern); // looks for last two elements in row and stores into m
		//pair<int, string> p(stoi(m[1]),m[2]); // put uin and grade into key-value pair
		int k = stoi(m[1]);
		string v = m[2];
		hashTable->insert(k, v);
	}
}

void CSVEditor::writeCSVToFile()
{
	if (!roster.is_open() || !output.is_open())
	{
		return;
	}
	while (!roster.eof())
	{
		string line;
		getline(roster, line);
		if (line != "")
		{
			istringstream ss(line);
			string name;
			getline(ss, name, ',');
			string email;
			getline(ss, email, ',');
			string uin;
			getline(ss, uin, ',');
			output << name << "," << email << "," << uin;
			if (hashTable->search(stoi(uin)) != nullptr)
			{
				output << "," << *(hashTable->search(stoi(uin)));
			}
			output << endl;
		}
	}
}

tuple<int, int, double> CSVEditor::getStats()
{
	return make_tuple(hashTable->minChainLen(), hashTable->maxChainLen(), hashTable->averageChainLen());
}
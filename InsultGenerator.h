/*
Author: Christina Yan
Header file for insult generator.
*/

#pragma once
#ifndef InsultGenerator_H
#define InsultGenerator_H

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;

class InsultGenerator {
public:
	InsultGenerator();
	void initialize();
	string talkToMe();
	vector<string> generate(const int n);
	vector<string> generateAndSave(const string s, const int n);

private:
	int generateRandNum();
	vector<string> col1, col2, col3, all3;
	set<string> insultSet;
};

class FileException {
public:
	FileException(const string&);
	string what() const;
private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what() const;
private:
	string message;
};

#endif

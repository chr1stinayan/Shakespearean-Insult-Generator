// Insult Generator implementation file

#include "stdafx.h"
#include "InsultGenerator.h"
using namespace std;

// null constructor
InsultGenerator::InsultGenerator() {}

// initializer will read in the text file line by line, then split each line into its 3 respective "column vectors"
void InsultGenerator::initialize() {
	string line;
	ifstream fileIn("insults.txt");
	if (fileIn.fail()) {
		throw FileException("Illegal file!");
		return;
	}
	stringstream ss;
	while (!fileIn.eof()) { //eof function used to to tell if error state flag is true or false to prevent the program from crashing, continue reading in file if no error
		getline(fileIn, line);
		ss.clear();
		ss.str(" ");
		ss << line;
		while (ss >> line) { //split line code using stringstream from https://www.eecis.udel.edu/~breech/progteam/stringstream.html
			all3.push_back(line);
		} // end pushback while
	} // end filein while
	for (int i = 0; i < all3.size(); i += 3) {
		col1.push_back(all3[i]);
		col2.push_back(all3[i + 1]);
		col3.push_back(all3[i + 2]);
	} //end for 
	fileIn.close();
} // end readtextfile method 


  // this function generates a random number
int InsultGenerator::generateRandNum() {
	int num;
	num = rand() % 49;
	return num;
} //end generate rand num

  // returns 1 insult
string InsultGenerator::talkToMe() {
	int num1, num2, num3;
	num1 = generateRandNum();
	num2 = generateRandNum();
	num3 = generateRandNum();
	string insult;
	insult = "Thou " + col1[num1] + " " + col2[num2] + " " + col3[num3] + "!";
	return insult;
}

// this method generates n insults and returns it as a vector of strings
vector<string> InsultGenerator::generate(int n) {
	if (n > 10000 || n < 1) { //check if number of insults is within accepted range of 1-10000
		throw NumInsultsOutOfBounds("Illegal number of insults!");
		return vector<string>();
	}
	set<string> insultSet; //use set for efficiency and also automatically checks for duplicates, and won't add redundant values 
	while (n > insultSet.size()) {
		string temp(talkToMe());
		insultSet.insert(temp);
	}//end while
	vector<string> returnedInsults(insultSet.begin(), insultSet.end()); //copy set into vector because c++ cannot return a set of strings
	return returnedInsults;
} //end generate

  // this method generates n insults, outputs insults into a specified file, and returns insults as vector of strings
vector<string> InsultGenerator::generateAndSave(string filename, int n) {
	ofstream outputFile(filename);
	set<string> insultSet;
	if (n < 1 || n > 10000) {
		throw NumInsultsOutOfBounds("Illegal number of insults!");
		return vector<string>();
	}
	else {
		while (n > insultSet.size()) {
			string insult = talkToMe();
			insultSet.insert(insult);
			outputFile << insult;
			outputFile << "\n";
		} //end while
	}//end else
	vector<string> returnedInsults(insultSet.begin(), insultSet.end());
	return returnedInsults;
}//end method

 // FileException class to throw an error if file can't be read 
FileException::FileException(const string& m) : message(m) {}

string FileException::what() const {
	return message;
}

//NumInsultsOutOfBounds class to throw error if provided number of insults is out of bounds
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}

string NumInsultsOutOfBounds::what() const {
	return message;
}


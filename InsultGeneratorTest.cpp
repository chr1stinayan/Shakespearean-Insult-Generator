/*
  Author: Christina Yan 
  Testing file reads in text file, generates 1 random insult/100 unique insults, and saves a user-determined number of insults into a new file.
 */


#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "InsultGenerator.h"

using namespace std;

int main() {

	InsultGenerator ig;
	vector<string> insults;
	double start, finish;

	//Load all the stored phrases from the source text file. If it doesn't work, throw an exception.
	try {
		ig.initialize();
	} catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}//end try-catch

	//talkToMe() returns a single random insult.
	cout << "A single insult:" << endl;
	cout << ig.talkToMe() << endl;


	//generate() generates the requested number of unique insults.
	cout << "\n100 insults, all different:" << endl;
	insults = ig.generate(100);
	if (insults.size() > 0)
		for (int i = 0; i < 100; i++)
			cout << insults[i] << endl;
	else
		cerr << "Insults could not be generated!" << endl;

	//generateAndSave() generates the requested number of unique insults and saves them to the filename
	//supplied in alphabetical order.  If there's a problem, the method throws an exception.
	try {
		ig.generateAndSave("Nothing.txt", 40000);
	} catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}//end try-catch

	cout << "\nSaving 1000 unique insults to a file...";
	try {
		ig.generateAndSave("SavedInsults.txt", 1000);
	} catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}//end try-catch
	cout << "done." << endl;

	return 0;

} //end main

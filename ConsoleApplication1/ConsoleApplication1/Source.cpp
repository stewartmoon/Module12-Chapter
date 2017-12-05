#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string replace_all(string str, const string &from, const string &to);
void Replace(string& s, double v);
void Greeting();
string run();

const int NUMBER_OF_CHAPTERS = 20;

int main()
{
	Greeting();
	string userquestion;
	do
	{
		userquestion = run();
	} while (userquestion!= "n");

return 0;
}


void Greeting()
{
	//Prompt user with hello greeting
	cout << "Hello and welcome to my magic eight ball." << endl;
	cout << "Ask any question your heart desires to know the answer too." << endl;
	cout << "But be warned you may not like the answer." << endl;
	cout << "Enter 'n' at anytime to quit the program. " << endl;
	cout << endl;
}

string run()
{
	//Declare output/input streams
	int number = NUMBER_OF_CHAPTERS;

	double next;
	string name;
	vector<string> lines;

	ifstream inStream;
	ofstream outStream;

	string userquestion;

	//Read from the text-file
	inStream.open("C:/Users/StewartMoon/Desktop/Answers.txt");
	//Check to make sure file opened

	if (inStream.fail())
	{
		cout << "Fail to Open File. " << endl;
	}
	//Read each line of the text into a vector
	for (string line; getline(inStream, line);)
	{
		lines.push_back(line);
	}

	//Output persons answer to a question
	for (int i = 0; i <= 7; i++)
	{
		cout << "Please enter a question: ";
		cin >> userquestion;

		//Logic to exit program
		if (userquestion == "n")
		{
			break;
		}
		//Logic to output every new text file with different line
		else if (i == 0)
		{
			Replace(lines[0], number);
			//replace_all(lines[0], "#N", to_string(number));
		}
		cout << lines[i] << endl;
	}
	//subtract count of Chapter after each loop
	number--;

	//Logic to reset count of Chapter
	if (number == 0)
	{
		number = 20;
	}

	//close inStream
	inStream.close();
	return userquestion;
}
string replace_all(string str, const string &from, const string &to)
{
	int pos = 0;
	int flen = from.length();
	int tlen = to.length();
	while ((pos = str.find(from, pos)) != -1)
	{
		str.replace(pos, flen, to);
		pos += tlen;
	}
	return str;
}

void Replace(string& s, double v) 
{
	auto it = s.find("#N");
	if (it != string::npos) s.replace(it, 2, to_string(v));
}
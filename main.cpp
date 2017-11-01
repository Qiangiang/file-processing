// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib> // exit function prototype
//#include <stdio.h>
//#include "LRUCache.h"
//#include "Valid_sqaure.h"
//#include "ImageSmoother.h"
//#include "ReverseFile.h"
//#include "skiplist_template.h"
//#include "SkipList.h"
//#include "reverse_file.h"
//#include "DrawACircle.h" 
using namespace std;




void reverseBuffer(char * c, long n) {
	for (int i = 0, j = n - 2; i < j; i++, j--) {
		char temp = c[i];
		c[i] = c[j];
		c[j] = temp;
	}
}
void reverseFile(string name)
{
	fstream inCredit(name, ios::in | ios::binary | ios::out);
	if (!inCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	inCredit.seekg(0, inCredit.end);
	int fileSize = inCredit.tellg();
	cout << "fileSize is "<<fileSize << endl;
	inCredit.seekg(0);
	int bufferSize = 7;
	char * buffer1 = new char[bufferSize];
	char * buffer2 = new char[bufferSize];
	int i = 0, j = fileSize - bufferSize;
	for (; i <= j; i += bufferSize - 1, j -= bufferSize - 1) {

		inCredit.seekg(i);
		inCredit.get(buffer1, bufferSize);

		inCredit.seekg(j);
		inCredit.get(buffer2, bufferSize);

		reverseBuffer(buffer1, bufferSize);
		reverseBuffer(buffer2, bufferSize);

		inCredit.seekp(i);
		inCredit.write(buffer2, bufferSize - 1);

		inCredit.seekp(j);
		inCredit.write(buffer1, bufferSize - 1);
	}
	// post processing
	 if(i < j + bufferSize - 1 - 1){
		 // read i j + n - i size into buffer 1;
		 cout << inCredit.tellg() << endl;
		 inCredit.seekg(i);
		 inCredit.get(buffer1, j + bufferSize - i);
		 
		 //swap in buffer
		 reverseBuffer(buffer1, j + bufferSize - i);
		 
		 // write buffer 1 to i j + n  - i size 
		 inCredit.seekp(i);
		 inCredit.write(buffer1, j + bufferSize - 1 - i);
	 }
}



void createFile(string name)
{

	ofstream outCredit(name, ios::out | ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	char s[] = "abcdefghijklmn";
	outCredit.write(s, sizeof(s));

}



void readFile(string name) {
	ifstream inCredit(name, ios::in | ios::binary);
	if (!inCredit) {
		cerr << "File could not be opend." << endl;
		exit(EXIT_FAILURE);
	}
	char c;
	while (inCredit.get(c)) {
		cout << c;
	}
	cout << endl;
}

void updateFile(string name) {
	fstream inCredit(name, ios::out |ios::in | ios::binary);
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	inCredit.write(s, sizeof(s));	
}



void deleteContent(string name) {
	std::ofstream ofs;
	ofs.open(name, std::ofstream::out | std::ofstream::trunc | ofs.binary);
	ofs.close();
}
int main()
{
	updateFile("one.dat");
	//deleteContent("one.dat");
	reverseFile("one.dat");
	readFile("one.dat");
	
	return 0;
}
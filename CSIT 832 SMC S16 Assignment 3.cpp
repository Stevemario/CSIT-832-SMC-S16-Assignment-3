//Los Angeles Valley College
//CSIT 832
//Spring 2016
//Steve Mario Correa
//Assignment 3
//This software sorts LAVC courses by section number.
#include "selection sort.hpp"
#include "bubble sort.hpp"
#include "insertion sort.hpp"
#include "csit_class.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
enum class sort_methods {
	_predecessor,
	Selection,
	Bubble,
	Insertion,
	Heap,
	Quick,
	Merge,
	_successor
};
void getSortMethod (sort_methods&, bool&);
void load (const std::string&, std::vector <csit_class>&);
void sort (const sort_methods&, std::vector <csit_class>&);
void display (const std::vector <csit_class>&);
void getOptionName (std::string&, const sort_methods&);
bool canReadALineInto (std::string&, std::ifstream&);
void main () {
	sort_methods sortMethodChoice;
	bool choseValidSortMethod;
	std::vector <csit_class> FallCSITClasses;
	bool programShouldEnd = false;
	do {
		getSortMethod (sortMethodChoice, choseValidSortMethod);
		if (choseValidSortMethod) {
			load ("classes.txt", FallCSITClasses);
			sort (sortMethodChoice, FallCSITClasses);
			display (FallCSITClasses);
			FallCSITClasses.clear ();
		} else if (sortMethodChoice == sort_methods::_successor)
			programShouldEnd = true;
	} while (programShouldEnd == false);
}
void getSortMethod (sort_methods& sortMethodChoice, bool& choseValidSortMethod) {
	unsigned int option;
	int sort_methods_prececessor = int (sort_methods::_predecessor);
	int sort_methods_successor = int (sort_methods::_successor);
	unsigned int nOptions = sort_methods_successor - sort_methods_prececessor;
	std::string optionName;
	choseValidSortMethod = false;
	std::cout << "Would you like to";
	for (
		option = 1;
		option < nOptions;
		option++
	) {
		getOptionName (optionName, sort_methods (sort_methods_prececessor + option));
		std::cout << "\n" << option << ". Sort by " << optionName << ",";
	}
	std::cout << " or\n" <<
		nOptions << ". Exit\n";
	std::cin >> option;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max (), '\n');
	std::cout << "\n";
	if (option < nOptions) {
		choseValidSortMethod = true;
		sortMethodChoice = sort_methods (sort_methods_prececessor + option);
	} else if (option == nOptions)
		sortMethodChoice = sort_methods::_successor;
}
void load (const std::string& sourceFileName, std::vector <csit_class>& CSITClasses) {
	std::ifstream sourceFile;
	bool mistakesWereMade = false;
	std::string lineRead;
	char chRead;
	std::string sRead;
	int courseNumber;
	int sectionNumber;
	csit_class::members destination = csit_class::members::CourseNumber;
	sourceFile.open (sourceFileName);
	while (mistakesWereMade == false &&
		(
			lineRead.empty () == false ||
			canReadALineInto (lineRead, sourceFile)
		)
	) {
		chRead = lineRead [0];
		lineRead.erase (0, 1);

		switch (chRead) {
			default:
			{
				sRead += chRead;
				break;
			}
			case '\t':
			{
				if (destination == csit_class::members::CourseNumber) {
					courseNumber = std::stoi (sRead);
					sRead.clear ();
					destination = csit_class::members::SectionNumber;
				} else
					mistakesWereMade = true;
				break;
			}
			case '\n':
			{
				if (destination == csit_class::members::SectionNumber) {
					sectionNumber = std::stoi (sRead);
					sRead.clear ();
					CSITClasses.push_back (csit_class (courseNumber, sectionNumber));
					destination = csit_class::members::CourseNumber;
				} else
					mistakesWereMade = true;
				break;
			}
		}
	}
	sourceFile.close ();
}
void sort (const sort_methods& sortMethodChoice, std::vector <csit_class>& CSITClasses) {
	void (*mySortingFunction)(std::vector <csit_class>&);
	bool mistakesWereMade = false;
	switch (sortMethodChoice) {
		case sort_methods::Selection:
		{
			mySortingFunction = selectionSort;
			break;
		}
		case sort_methods::Bubble:
		{
			mySortingFunction = bubbleSort;
			break;
		}
		case sort_methods::Insertion:
		{
			mySortingFunction = insertionSort;
			break;
		}
		default:
		{
			mistakesWereMade = true;
			break;
		}
	}
	if (mistakesWereMade == false)
		mySortingFunction (CSITClasses);
}
void display (const std::vector <csit_class>& CSITClasses) {
	int nClasses = CSITClasses.size ();
	const csit_class* currentClass;
	for (
		int classIndex = 0;
		classIndex < nClasses;
		classIndex++
	) {
		currentClass = & CSITClasses [classIndex];
		std::cout << currentClass->sectionNumber () << "\t" <<
			currentClass->courseNumber () << "\n";
	}
	std::cout << "\n";
}
void getOptionName (std::string& optionName, const sort_methods& option) {
	switch (option) {
		case sort_methods::Selection:
		{
			optionName = "Selection";
			break;
		}
		case sort_methods::Bubble:
		{
			optionName = "Bubble";
			break;
		}
		case sort_methods::Insertion:
		{
			optionName = "Insertion";
			break;
		}
		case sort_methods::Heap:
		{
			optionName = "Heap";
			break;
		}
		case sort_methods::Quick:
		{
			optionName = "Quick";
			break;
		}
		case sort_methods::Merge:
		{
			optionName = "Merge";
			break;
		}
		default:
		{
		}
	}
}
bool canReadALineInto (std::string& line, std::ifstream& dataFile) {
	bool canReadALine = false;
	std::getline (dataFile, line);
	if (line.empty () == false) {
		canReadALine = true;
		line += '\n';
	}
	return canReadALine;
}
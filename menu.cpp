#include "lab.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <climits>
#include <stdio.h>
using namespace std;
string menu(int &x)
{
	cout<<"Please make a selection from the following:\n"<<endl;
	
	cout<<"1: Print out wine between two scores, (eg 90 and 92).\n"<<endl;
	
	cout<<"2: Print out wine between two prices, (eg 20 and 50).\n"<<endl;
	
	cout<<"3: Print out all wine assorted by price along with average price.\n"<<endl;
	
	cout<<"4: Print out all wine assorted by score along with average score.\n"<<endl;
	
	cout<<"5: Print out all wine assorted by score then by price along with average price.\n"<<endl;

	cout<<"6: Quit program.\n"<<endl;
	
	int selection;
	
	cin>>selection; cout<<endl;
	
	if(selection == 1)
	{
		string lowerBound;
		string upperBound;
		bool passCheck = false;
		do{
		cout<<"Please enter the lower score: ";
		cin>>lowerBound; cout<<endl;
		
		cout<<"Please enter the upper score: ";
		cin>>upperBound; cout<<endl;
		if(cin.fail() || stoi(upperBound)<stoi(lowerBound) || stoi(lowerBound)<0 || stoi(upperBound) > 100)
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Error, please enter a valid choice.\n"<<endl;
		}
		else passCheck = true;
		
		}while(!passCheck);
		
		
		string ssearchStream = "Select * from wineInfo where score > "+ lowerBound +" and score < " + upperBound;
		return ssearchStream;
	}
	else if(selection == 2)
	{
		
		string lowerBound;
		string upperBound;
		bool passCheck = false;
		do{
		cout<<"Please enter the lower price limit: ";
		cin>>lowerBound; cout<<endl;
		
		cout<<"Please enter the upper price limit: ";
		cin>>upperBound; cout<<endl;
		if(cin.fail() || stoi(upperBound)<stoi(lowerBound) || stoi(lowerBound)<0)
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Error, please enter a valid choice.\n"<<endl;
		}
		else passCheck = true;
		
		}while(!passCheck);
		
		
		string ssearchStream = "Select * from wineInfo where price > "+ lowerBound +" and price < " + upperBound;
		return ssearchStream;
		
	}
	
	else if(selection == 3)
	{
		x = 1;
		return "Select * from wineInfo where price > 0 order by price ASC";
		
	}
	else if(selection == 4)
	{
		x = 1;
		return "Select * from wineInfo where price > 0 order by score ASC";
		
	}
	else if(selection == 5)
	{
		x = 1;
		return "Select * from wineInfo where price > 0 order by score, price ASC";
		
	}
	else if(selection == 6)
	{
		exit(0);
	}
	else
	{
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Error, please enter a valid choice.\n"<<endl;
	}
}

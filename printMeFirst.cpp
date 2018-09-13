/* This function takes user the author's name, and course info, 
 * and prints it out along with the current time.
 * @input string name: author's name.
 * @input string courseInfo: wine info.
 * 
 */
#include "lab.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

void printMeFirst(string name,string courseInfo)
{
	cout<<"Program written by: "+name<<endl;
	cout<<"Course info: "+courseInfo<<endl;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout<<"Date: "<<dt<<endl;
}

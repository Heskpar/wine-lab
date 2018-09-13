/*

http://www.codingfriends.com/index.php/2010/02/17/mysql-connection-example/

To compile up this program you will need to link to the mysql libraries and headers that are used within the program, e.g. mysql.h at the top of the program. To gain access to these, there is a nice mysql_config (you may need to install it via your package manager system if you do not have it already).

Here are my outputs of what is required on the command line for the g++ compiler



g++ -I/usr/include/mysql winedb.cpp -o winedb -L/usr/lib/mysql -lmysqlclient


./windb "select * from wineInfo where price > 100"

*/
#include "lab.h"
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "dbconnect.h"
#include <string.h>

using namespace std;
 
 
 
 
/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main(int argc, char* argv[])
{
  printMeFirst("Muhammed Mahmood", "CS 116");
  	
  MYSQL *conn;		// the connection
  MYSQL_RES *res;	// the results
  MYSQL_ROW row;	// the results row (line by line)
 
  struct connection_details mysqlD;
  mysqlD.server = (char *)"localhost";  // where the mysql database is
  mysqlD.user = (char *)"root";		// the root user of mysql	
  mysqlD.password = (char *)"password"; // the password of the root user in mysql
  mysqlD.database = (char *)"mysql";	// the databse to pick
 
  // connect to the mysql database
  conn = mysql_connection_setup(mysqlD);

  
 
while(1)
{
  // assign the results return to the MYSQL_RES pointer
  int getAverage = 0;
  double average = 0;
  int totalWine = 0;
  if (argc < 1)
  {
     cout << "argv[0]: " << argv[0] << endl;
     printf("\nUsage: %s  \"SQL statement here\"\n", argv[0]);
     printf("if no argument given, default is:\n %s show tables\n", argv[0]);
     res = mysql_perform_query(conn, (char *)"show tables");
     printf("MySQL Tables in mysql database:\n");
  }
  else
  {	
	
     // use wine database
     res = mysql_perform_query(conn, (char *)"use wine");
     string ssearchStream = menu(getAverage);
     
	 char* searchStream= new char[ssearchStream.size()+1];
	 strcpy(searchStream,ssearchStream.c_str());
	
     res = mysql_perform_query(conn,searchStream);
     delete searchStream;
     /*
      * you need to print out the header.  Make sure it it 
      * nicely formated line up.  Modify the cout statement
      * below so the header is nicely line up.  Hint: use left and setw
      * 
      * WineName   Vitange  Rating  Price  Type
      * */
     cout<<"--------------------------------------------------------------------"<<endl;
     cout.width(30); 
     cout<<left<< "Wine Name";
     cout.width(11);
     cout<<left<< "| Vintage";
     cout.width(9); 
	 cout<<left<< "| Rating";
	 cout.width(9);
	 cout<<left<< "| Price"; 
	 cout.width(8);
	 cout<<left<< "| Type";
	 cout<<right<<"|";
	 cout<< endl;
	 cout<<"-------------------------------------------------------------------|"<<endl;
	 
  }

//cout>>"Please enter a lower and upper score."

  while ((row = mysql_fetch_row(res)) !=NULL)
  {
	average += stod(row[3]);
	totalWine++;
	
		  
   /* print out each row of the data extracted from
		   * MySQL database
		   * Make sure the output is line up with the header
		   * Hint: use left and setw
		   */

	 cout.width(30);
	  cout<<left << row[0]  << "| ";// coulumn (field) #1 - Wine Name
	 cout.width(9);
	  cout<<left<< row[1] << "| "; // field #2 - Vintage
	 cout.width(7); 
	  cout<<left<< row[2] << "| "; // field #3 - Rating
	 cout.width(7);
	  cout<<left<< row[3] << "| ";// field #4 - Price
	 cout.width(6); 
	  cout<<left<< row[5] << "| "; // field #5 - Wine type
	  cout<< endl; // field #7 - UPC
      
  }
   cout<<"--------------------------------------------------------------------"<<endl;
   if(getAverage == 1)
   {
	   cout.width(25);
	   cout<<left<<"Total wine: "<<left<<totalWine;
	   cout.width(20);
	   cout<<left<<"    | Average Price: "<<left<<average/totalWine;
	   cout.width(14);
	   cout<<right<<"|"<<endl;
	    cout<<"--------------------------------------------------------------------"<<endl;
   }
}
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
  	

  return 0;
}

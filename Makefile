#
#
CC=g++ -std=c++11
#
CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient



all: winedb

winedb: winedb.o dbconnect.o menu.o lab.h printMeFirst.o
	$(CC) winedb.o dbconnect.o menu.o printMeFirst.o -o winedb $(LFLAGS)

dbconnect.o: dbconnect.cpp
	$(CC) $(CFLAGS) dbconnect.cpp

winedb.o: winedb.cpp lab.h 
	$(CC) $(CFLAGS) winedb.cpp

menu.o: menu.cpp lab.h
	$(CC) $(CFLAGS) menu.cpp
printMeFirst.o: printMeFirst.cpp lab.h
	$(CC) $(CFLAGS) printMeFirst.cpp

clean:
	rm *.o winedb

run:
	./winedb "select * from wineInfo where price > 100"

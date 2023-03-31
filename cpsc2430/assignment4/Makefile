assignment4: assignment4.o CovidDB.o DataEntry.o
	g++ -o assignment4 assignment4.o CovidDB.o DataEntry.o
assignment4.o: assignment4.cpp CovidDB.h
	g++ -c -Wall -Werror -pedantic assignment4.cpp
CovidDB.o: CovidDB.cpp CovidDB.h
	g++ -c -Wall -Werror -pedantic CovidDB.cpp
DataEntry.o: DataEntry.cpp DataEntry.h
	g++ -c -Wall -Werror -pedantic DataEntry.cpp
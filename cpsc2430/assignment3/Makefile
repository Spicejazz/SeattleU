bsttest: assignment3.o BST.o
	g++ -o bsttest assignment3.o BST.o
assignment3.o: assignment3.cpp BST.h
	g++ -c -Wall -Werror -pedantic assignment3.cpp
BST.o: BST.cpp BST.h
	g++ -c -Wall -Werror -pedantic BST.cpp
g++ -Wall -Werror -pedantic -std=c++11 \
  Person.h Person.cpp Location.h Location.cpp\
  PersonLocationEvent.h PersonLocationEvent.cpp\
  EventQueue.h EventQueue.cpp tests.cpp\
  -lgtest -lpthread -o tests
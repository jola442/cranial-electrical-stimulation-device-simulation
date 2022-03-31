fp:	main.o session.o
	g++ -o A2 main.o session.o

main.o:	main.cpp defs.h
	g++ -c main.cpp

session.o: session.cpp session.h defs.h
	g++ -c session.cpp

clean:
	rm -f *.o fp
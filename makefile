booking: password_MANAGE.o main.o
	g++ password_MANAGE.o main.o -o booking

password_MANAGE.o:password_MANAGE.cpp
	g++ -c password_MANAGE.cpp

main.o:main.cpp
	g++ -c main.cpp


clean:
	rm*.o booking
count:string.o  testString.o
	gcc string.o  testString.o -o count

testString.o:testString.c
	gcc -c testString.c -o testString.o

string.o:string.c
	gcc -c string.c -o string.o


clean:
	@rm -rf *.o count
	
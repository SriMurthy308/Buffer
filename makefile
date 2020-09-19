all: buffer.out

buffer.out: buffer.o erase.o insert.o load.o main.o replace.o save.o
	 g++ -o buffer.out buffer.o erase.o insert.o load.o main.o replace.o save.o

buffer.o: Buffer.cpp
	 g++ -c -std=c++11 Buffer.cpp -o buffer.o
	 
insert.o: Insert.cpp
	 g++ -c -std=c++11 Insert.cpp -o insert.o
     
erase.o: Erase.cpp
	 g++ -c -std=c++11 Erase.cpp -o erase.o
	 
replace.o: Replace.cpp
	g++ -c -std=c++11 Replace.cpp -o replace.o

load.o: Load.cpp
	g++ -c -std=c++11 Load.cpp -o load.o

save.o: Save.cpp
	g++ -c -std=c++11 Save.cpp -o save.o
	
main.o: main.cpp
	g++ -c -std=c++11 main.cpp -o main.o
	 
clean:
	 rm buffer.o insert.o erase.o replace.o load.o save.o main.o buffer.out

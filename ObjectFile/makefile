Memory: main.o memory.o ConfigRead.o List.o Node.o
	g++ -pthread -o ../Memory main.o memory.o ConfigRead.o List.o Node.o GenerateLog.o

main.o: ../main.cpp ../memory.h ../ConfigRead.h
	g++ -c ../main.cpp

GenerateLog.o: ../GenerateLog.cpp ../GenerateLog.h ../ConfigRead.h
	g++ -c ../GenerateLog.cpp
    
memory.o: ../memory.cpp ../memory.h ../ConfigRead.h ../LinkedList/List.h
	g++ -c ../memory.cpp

ConfigRead.o: ../ConfigRead.cpp ../ConfigRead.h
	g++ -c ../ConfigRead.cpp

List.o: ../LinkedList/List.cpp ../LinkedList/List.h ../LinkedList/Node.h
	g++ -c ../LinkedList/List.cpp

Node.o: ../LinkedList/Node.cpp ../LinkedList/Node.h
	g++ -c ../LinkedList/Node.cpp

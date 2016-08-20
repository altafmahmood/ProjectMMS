MemoryManagement: main.o GenerateLog.o memory.o ConfigRead.o List.o Node.o
	g++ -pthread -o ../MemoryManagement main.o memory.o GenerateLog.o ConfigRead.o List.o Node.o
	rm -f main.o memory.o GenerateLog.o ConfigRead.o List.o Node.o

main.o: ../src/main.cpp ../src/memory.h ../src/ConfigRead.h
	g++ -c ../src/main.cpp

GenerateLog.o: ../src/GenerateLog.cpp ../src/GenerateLog.h ../src/ConfigRead.h
	g++ -c ../src/GenerateLog.cpp

memory.o: ../src/memory.cpp ../src/memory.h ../src/ConfigRead.h ../src/LinkedList/List.h ../src/GenerateLog.h
	g++ -c ../src/memory.cpp

ConfigRead.o: ../src/ConfigRead.cpp ../src/ConfigRead.h
	g++ -c ../src/ConfigRead.cpp

List.o: ../src/LinkedList/List.cpp ../src/LinkedList/List.h ../src/LinkedList/Node.h
	g++ -c ../src/LinkedList/List.cpp

Node.o: ../src/LinkedList/Node.cpp ../src/LinkedList/Node.h
	g++ -c ../src/LinkedList/Node.cpp



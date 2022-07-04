snake.x: main.o
	g++ -std=c++11 main.o -o snake.x

main.o: main.cpp
	g++ -std=c++11 main.cpp -o main.o -c

clean:
	rm -f snake.x *.o
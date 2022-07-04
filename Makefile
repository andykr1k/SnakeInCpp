snake.x: main.o
	g++ -std=c++17 main.o -o snake.x

main.o: main.cpp
	g++ -std=c++17 main.cpp -o main.o -c

clean:
	rm -f *.o snake.x 
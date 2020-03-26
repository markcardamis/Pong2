CC=clang++
CFLAGS=-std=c++11 -stdlib=libc++
OUTPUT=main.out
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
SOURCES=src/*.cpp

clang++ -std=c++11 -stdlib=libc++ -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system *.cpp -o main.out

all: prog

prog:
	$(CC) $(CFLAGS) $(LIBS) $(SOURCES) -o $(OUTPUT)

clean:
	rm main.out

all: main.o client.o user.o artist.o track.o music.o podcast.o album.o playlist.o ui.o
	g++ -Wall -ansi -pedantic -g -o ./bin/program.out ./build/*.o

main.o:
	g++ -c ./src/main.cpp -I ./include -o ./build/main.o

client.o:
	g++ -c ./src/client/client.cpp -I ./include -o ./build/client.o

artist.o:
	g++ -c ./src/client/artist/artist.cpp -I ./include -o ./build/artist.o

track.o:
	g++ -c ./src/media/track/track.cpp -I ./include -o ./build/track.o

album.o:
	g++ -c ./src/media/album/album.cpp -I ./include -o ./build/album.o

playlist.o:
	g++ -c ./src/media/playlist/playlist.cpp -I ./include -o ./build/playlist.o

user.o:
	g++ -c ./src/client/user/user.cpp -I ./include -o ./build/user.o

music.o:
	g++ -c ./src/media/track/music/music.cpp -I ./include -o ./build/music.o

podcast.o:
	g++ -c ./src/media/track/podcast/podcast.cpp -I ./include -o ./build/podcast.o

ui.o:
	g++ -c ./src/userinterface/ui.cpp -I ./include -o ./build/ui.o

clear:
	rm ./build/*.o
	rm ./bin/*.out

run:
	./bin/program.out
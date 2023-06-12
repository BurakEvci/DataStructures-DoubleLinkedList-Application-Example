tum: derleme calistirma


derleme:
	g++ -I ./include/ -o ./lib/KonsoldaGoruntuleme.o -c ./src/KonsoldaGoruntuleme.cpp
	g++ -I ./include/ -o ./lib/DosyaOkuma.o -c ./src/DosyaOkuma.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirListesiNode.o -c ./src/SatirListesiNode.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiNode.o -c ./src/YoneticiNode.cpp

	g++ -I ./include/ -o ./bin/main ./lib/KonsoldaGoruntuleme.o  ./lib/DosyaOkuma.o ./lib/SatirListesi.o ./lib/SatirListesiNode.o ./lib/YoneticiListesi.o  ./lib/YoneticiNode.o   ./src/main.cpp

calistirma:
	./bin/main
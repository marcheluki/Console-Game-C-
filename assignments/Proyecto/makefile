all: clean compile run

compile: MainJuego.cpp
	g++ *.cpp -o build/exercise
run: 
	clear
	g++ *.cpp -o build/exercise
	build/exercise
clean:
	rm -f build/exercise
	rm -f build/dexercise
debug: 
	g++ *.cpp -g -o dexercise
	gdb dexercise
	rm -f dexercise
debugvs:
	g++ *.cpp -g -o build/dexercise

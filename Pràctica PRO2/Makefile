OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Poblacio.o Individu.o Especie.o Parellcromosomes.o
	g++ -o program.exe program.o Poblacio.o Individu.o Especie.o Parellcromosomes.o
	rm *.o

Especie.o: Especie.cc Especie.hh
	g++ -c Especie.cc $(OPCIONS)

Poblacio.o: Individu.hh Arbre.hh
	g++ -c Poblacio.cc $(OPCIONS)

Individu.o: Individu.cc Individu.hh Parellcromosomes.hh Especie.hh
	g++ -c Individu.cc $(OPCIONS)

Parellcromosomes.o: Parellcromosomes.cc Parellcromosomes.hh
	g++ -c Parellcromosomes.cc $(OPCIONS)

program.o: program.cc Poblacio.hh Individu.hh Especie.hh
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch

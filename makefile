CXX=g++
CXXFLAGS=-Wall -ggdb -I include
AR=/usr/bin/ar -r 

src := $(wildcard src/*.cpp) # Génère la liste des fichier .cpp contenu dans le dossier src
obj := $(subst src, build, $(src:.cpp=.o)) #Génère la liste des fichiers .o (n'existe pas encore mais prend juste les titres des cpp)

.PHONY: directories

all: directories librogue.a rogue 
	@echo $(obj)

rogue: main.cpp librogue.a
	$(CXX) $(CXXFLAGS) $^ -lncurses -o $@ 

librogue.a: ${obj}
	${AR} $@ $^

build/%.o: src/%.cpp include/%.h
	$(CXX) $(CXXFLAGS) -lncurses -o $@ -c $<

directories: build

build:
	mkdir -p $@

clean: 
	rm rogue
	rm librogue.a
	rm -r build

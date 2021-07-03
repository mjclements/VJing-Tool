C_COMPILER	=	gcc
CXX_COMPILER	=	g++

#FLAGS	=	-lole32
FLAGS 	=	''
##All objects files will be stored in the ./lib directory
##All header files should be present in the ./include directory

#Audiostream being in the main directory is feeling kinda like a hack
all:	main.cpp visualizers analyzers connectors
	$(CXX_COMPILER) main.cpp AudioStream.cpp $(shell find lib/*.o)  -I'./include/' $(FLAGS)

##Build every cpp file in Visualizers/ directory
visualizers:	Visualizers/
	$(CXX_COMPILER) ./Visualizers/*.cpp -o ./lib/ -c $(FLAGS)

##Build every cpp file in Analyzers/ directory
analyzers:	$(shell find Analyzers -type f)
	cd lib && $(CXX_COMPILER)  -c ../Analyzers/*.cpp -I../include/ -L'../lib' $(FLAGS)


##Build every cpp file in Connectors/ directory
connectors:	$(shell find Connectors -type f)
	cd lib && $(CXX_COMPILER)  -c ../Connectors/*.cpp -I../include/ -L'../lib' $(FLAGS)

clean:	
	rm lib/*
	rm a.out
	rm a.exe

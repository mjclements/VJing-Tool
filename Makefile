C_COMPILER	=	gcc
CXX_COMPILER	=	 C://ProgramData/chocolatey/bin/c++.exe  

#FLAGS	=	-lole32
FLAGS 	= -lsfml-window -lsfml-system -lsfml-graphics -lole32
##All objects files will be stored in the ./lib directory
##All header files should be present in the ./include directory

#Audiostream being in the main directory is feeling kinda like a hack
all:	main.cpp
	cd lib && $(CXX_COMPILER)  -c ../Connectors/*.cpp -I'../include/' -L'../lib' $(FLAGS)
	cd lib && $(CXX_COMPILER)  -c ../Analyzers/*.cpp -I'../include/' -L'../lib' $(FLAGS)
	cd lib && $(CXX_COMPILER)  -c ../Visualizers/*.cpp -I'../include/' -L'../lib' $(FLAGS)
	$(CXX_COMPILER) main.cpp AudioStream.cpp $(shell find lib/*.o)  -I'./include/'  $(FLAGS)
	

# ##Build every cpp file in Visualizers/ directory
# visualizers:	$(shell find Visualizers/)
# 	cd lib && $(CXX_COMPILER)  -c ../Visualizers/*.cpp -I'../include/' -L'../lib' $(FLAGS)

# ##Build every cpp file in Analyzers/ directory
# analyzers:	$(shell find Analyzers)
# 	cd lib && $(CXX_COMPILER)  -c ../Analyzers/*.cpp -I'../include/' -L'../lib' $(FLAGS)

# ##Build every cpp file in Connectors/ directory
# connectors:	$(shell find Connectors)
# 	cd lib && $(CXX_COMPILER)  -c ../Connectors/*.cpp -I'../include/' 

clean:	
	rm lib/*
	rm a.out
	rm a.exe
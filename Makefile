CC = g++
AR = ar  

CFLAG = -W -Wall -g

AST_SRCS := $(wildcard compiler/ast/*.cpp)
AST_OBJS := $(AST_SRCS:.cpp=.o)
AST_OBJS_BUILD := $(addprefix build/,${AST_OBJS})
OBJ_DIR = build/

aloc: build/compiler/cppfront.o build/compiler/preprocessor.o build/compiler/utils.o build/compiler/code_parser.o $(AST_OBJS_BUILD) readytomake
	$(CC) $(CFLAG) build/compiler/cppfront.o build/compiler/preprocessor.o build/compiler/utils.o $(AST_OBJS_BUILD) -lLLVM -o aloc 

build/compiler/preprocessor.o: compiler/preprocessor.cpp compiler/preprocessor.hpp compiler/compileerror.hpp readytomake
	$(CC) $(CFLAG) -c -I ./compiler/ compiler/preprocessor.cpp -o build/compiler/preprocessor.o

build/compiler/cppfront.o: compiler/cppfront.cpp compiler/preprocessor.hpp compiler/compileerror.hpp readytomake
	$(CC) $(CFLAG) -c -I ./compiler/ compiler/cppfront.cpp -o build/compiler/cppfront.o
	
build/compiler/utils.o: compiler/utils.cpp readytomake
	$(CC) $(CFLAG) -c -I ./compiler/ compiler/utils.cpp -o build/compiler/utils.o

build/compiler/code_parser.o: compiler/code_parser.cpp readytomake
	$(CC) $(CFLAG) -c -I ./compiler/ compiler/code_parser.cpp -o build/compiler/code_parser.o

$(AST_OBJS_BUILD):$(OBJ_DIR)%.o : %.cpp readytomake
	$(CXX) $(CFLAGS) -c $< -o $@ 

readytomake: clean
	mkdir build
	mkdir build/compiler
	mkdir build/ast
	touch readytomake

.PHONY : clean,install
install: aloc readytomake
	mv aloc /usr/bin/
clean:
	-rm -r aloc build readytomake

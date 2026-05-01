PROJECT_DIR=.
# Use -I for include paths. 
CFLAGS=-I${PROJECT_DIR}/include/ -std=c++14 
CXX=g++

# Core logic files
FILES=data_structures/disjoint_set.cpp \
      graph.cpp \
      main.cpp \
      sort/msort.cpp \
      sort/hsort.cpp \
      algorithms/topologicalsort.cpp \
      algorithms/rbtree.cpp

# Windows Binary Extension
EXE=.exe

# OpenCV Configuration (pkg-config is rare on Windows, usually manual paths are needed)
OPENCV=0
ifeq ($(OPENCV), 1)
    # If using vcpkg or manual install, replace these with actual paths
    LDFLAGS+= -lopencv_world450 
    CFLAGS+= -DOPENCV=1
endif

SRC_DIR=${PROJECT_DIR}/src/
SRC_FILES=$(addprefix ${SRC_DIR}, ${FILES})
ALG_DIR=${SRC_DIR}algorithms/

# Default target: Compiles and then runs the .exe
all: bin/integrated$(EXE)
	./bin/integrated$(EXE)

# Compiles everything into a single integrated binary
# mkdir -p is the shell-safe way to handle directory creation safely
bin/integrated$(EXE): ${SRC_FILES} ${ALG_DIR}kruskal.cpp ${ALG_DIR}dijkstra.cpp ${ALG_DIR}prim.cpp
	mkdir -p bin
	${CXX} ${CFLAGS} -DKRUSKAL -DDIJKSTRA -DPRIM -DINTEGRATED $^ ${LDFLAGS} -o $@ 

# Cleanup
clean:
	rm -rf bin
	@echo Cleaned build directory.
OBJS= depthTest.o glad.o
main: $(OBJS)
	clang++ -o depthTest $(OBJS) -ldl -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lassimp -L ./external/assimp-master/lib/

depthTest.o: glad.o
	clang++ -c -std=c++11 -ggdb depthTest.cpp -I ./external/glad/include/ -I ./external/ -I ./external/assimp-master/include/

glad.o: 
	clang++ -c ./external/glad/src/glad.c -I ./external/glad/include/

clean:
	rm -f depthTest $(OBJS)	

#assimp: error while loading shared libraries: libassimp.so.4: cannot open shared object file: No such file or directory
#export LD_LIBRARY_PATH=/usr/local/lib
all: compile_fdr compile_datastructures compile_fileOperations compile run 

compile_fdr:
	gcc -I ./inc/lfdr -o ./obj/dllist.o -c ./src/lfdr/dllist.c
	gcc -I ./inc/lfdr -o ./obj/fields.o -c ./src/lfdr/fields.c
	gcc -I ./inc/lfdr -o ./obj/jrb.o -c ./src/lfdr/jrb.c
	gcc -I ./inc/lfdr -o ./obj/jval.o -c ./src/lfdr/jval.c
	

	ar ruv ./lib/lfdr.a ./obj/dllist.o ./obj/fields.o ./obj/jrb.o ./obj/jval.o 

compile_datastructures:
	gcc -I ./inc/utils/Boolean -o ./obj/Boolean.o -c ./src/utils/dataTypes/Boolean.c
	gcc -I ./inc/utils/dataTypes -o ./obj/Stack.o -c ./src/utils/dataTypes/Stack.c


compile_fileOperations:
	gcc -I ./inc/utils/fileOperations -o ./obj/readFile.o -c ./src/utils/fileOperations/readFile.c
	gcc -I ./inc/utils/fileOperations -o ./obj/writeFile.o -c ./src/utils/fileOperations/writeFile.c

#ar ruv ./lib/fileOperations.a ./obj/readFile.o ./obj/writeFile.o

compile:

#gcc -I ./inc -o ./bin/output ./obj/dllist.o ./obj/fields.o ./obj/jrb.o ./obj/jval.o ./src/main.c
	
	gcc -g -I/inc/ -o  ./obj/main.o -c ./src/main.c
	gcc -g -o ./bin/output ./obj/Boolean.o ./obj/Stack.o ./obj/readFile.o ./obj/main.o ./lib/lfdr.a

	


run:
	./bin/output ./data/input.dat

clean:
	rm -f ./obj/*.o
	rm -f ./lib/*.a
	rm -f ./bin/output
all: compile_fdr compile_datastructures compile_parser compile_fileOperations compile run 

compile_fdr:
	gcc -I ./inc/lfdr -o ./obj/dllist.o -c ./src/lfdr/dllist.c
	gcc -I ./inc/lfdr -o ./obj/fields.o -c ./src/lfdr/fields.c
	gcc -I ./inc/lfdr -o ./obj/jrb.o -c ./src/lfdr/jrb.c
	gcc -I ./inc/lfdr -o ./obj/jval.o -c ./src/lfdr/jval.c
	ar ruv ./lib/lfdr.a ./obj/dllist.o ./obj/fields.o ./obj/jrb.o ./obj/jval.o 

compile_datastructures:
	gcc -I ./inc/utils/dataTypes -o ./obj/Boolean.o -c ./src/utils/dataTypes/Boolean.c
	gcc -I ./inc/utils/dataTypes -o ./obj/String.o -c ./src/utils/dataTypes/String.c
	gcc -I ./inc/utils/dataTypes -o ./obj/CodeLine.o -c ./src/utils/dataTypes/CodeLine.c

compile_parser:
	gcc -I ./inc/parser -o ./obj/operatorsEnum.o -c ./src/parser/operatorsEnum.c
	gcc -I ./inc/generator -o ./obj/textGenerator.o -c ./src/generator/textGenerator.c
	gcc -I ./inc/parser -o ./obj/parser.o -c ./src/parser/parser.c

compile_fileOperations:
	gcc -I ./inc/utils/fileOperations -o ./obj/readFile.o -c ./src/utils/fileOperations/readFile.c
	gcc -I ./inc/utils/fileOperations -o ./obj/createFile.o -c ./src/utils/fileOperations/createFile.c

#ar ruv ./lib/fileOperations.a ./obj/readFile.o ./obj/writeFile.o

compile:

#gcc -I ./inc -o ./bin/output ./obj/dllist.o ./obj/fields.o ./obj/jrb.o ./obj/jval.o ./src/main.c
	
	gcc -g -I/inc/ -o  ./obj/main.o -c ./src/main.c
	gcc -g -o ./bin/output ./obj/String.o ./obj/Boolean.o  ./obj/CodeLine.o  ./obj/operatorsEnum.o ./obj/textGenerator.o ./obj/parser.o ./obj/readFile.o ./obj/createFile.o ./obj/main.o ./lib/lfdr.a

	


run:
	./bin/output ./data/input.dat

clean:
	rm -f ./obj/*.o
	rm -f ./lib/*.a
	rm -f ./bin/output
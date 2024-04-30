all: compile_fdr compile run 

compile_fdr:
	gcc -I ./inc/lfdr -o ./obj/dllist.o -c ./src/lfdr/dllist.c
	gcc -I ./inc/lfdr -o ./obj/fields.o -c ./src/lfdr/fields.c
	gcc -I ./inc/lfdr -o ./obj/jrb.o -c ./src/lfdr/jrb.c
	gcc -I ./inc/lfdr -o ./obj/jval.o -c ./src/lfdr/jval.c
	

	ar ruv ./lib/lfdr.a ./obj/dllist.o ./obj/fields.o ./obj/jrb.o ./obj/jval.o 

compile:

#gcc -I ./inc -o ./bin/output ./obj/dllist.o ./obj/fields.o ./obj/jrb.o ./obj/jval.o ./src/main.c
	gcc -g -I/inc/ -o ./obj/main.o -c ./src/main.c
	gcc -g -o ./bin/output ./obj/main.o ./lib/lfdr.a

	


run:
	./bin/output

clean:
	rm -f ./obj/*.o
	rm -f ./lib/*.a
	rm -f ./bin/output
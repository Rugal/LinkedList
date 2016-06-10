CC=gcc -std=c11 -g3 -w -o $@
COMPILE=-c $<
VPATH=include
OUT=a.out

#Build all
all: ${OUT}

#Build server
${OUT}: main.o linked_list.o
	${CC} $^
main.o: main.c
	${CC} -I ${VPATH} ${COMPILE}
linked_list.o: implement/linked_list.c node.o
	${CC} -I ${VPATH} ${COMPILE}
node.o: implement/node.c
	${CC} -I ${VPATH} ${COMPILE}


clean:
	rm *.o ${OUT}

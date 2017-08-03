CC=gcc

all: mysh

mysh:	main.c ./tokenize/makeArgs.o ./utils/myUtils.o ./process/process.o ./pipes/pipes.o ./myshrc/startCheck.o ./history/history.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./cd/cd.o ./path/path.o ./pipes/pipeArg.o
	gcc -g main.c ./tokenize/makeArgs.o ./utils/myUtils.o ./process/process.o ./pipes/pipes.o ./myshrc/startCheck.o ./history/history.o ./linkedlist/linkedList.o ./linkedlist/listUtils.o ./cd/cd.o ./path/path.o ./pipes/pipeArg.o -o mysh

makeArgs.o:	./tokenize/makeArgs.c ./tokenize/makeArgs.h
	gcc -g -c ./tokenize/makeArgs.c

linkedList.o:	./linkedlist/linkedList.c ./linkedlist/linkedList.h ./linkedlist/genericData.h ./linkedlist/requiredIncludes.h
	gcc -g -c ./linkedlist/linkedList.c

myUtils.o:	./utils/myUtils.c ./utils/myUtils.h
	gcc -g -c ./utils/myUtils.c

process.o:	./process/process.c ./process/process.h
	gcc -g -c ./process/process.c	

pipes.o:	./pipes/pipes.c ./pipes/pipes.h
	gcc -g -c ./pipes/pipes.c

startCheck.o: ./myshrc/startCheck.c ./myshrc/startCheck.h
	gcc -g -c ./myshrc/startCheck.c

history.o:	./history/history.c ./history/history.h
	gcc -g -c ./history/history.c

listUtils.o:	./linkedlist/listUtils.c ./linkedlist/listUtils.h
	gcc -g -c ./linkedlist/listUtils.c

cd.o:	./cd/cd.c ./cd/cd.h
	gcc -g -c ./cd/cd.c

path.o: ./path/path.c ./path/path.h
	gcc -g -c ./path/path.c

pipeArg.o: ./pipes/pipeArg.c ./pipes/pipeArg.h
	gcc -g -c ./pipes/pipeArg.c

clean:
	rm ./pipes/pipes.o	
	rm ./utils/myUtils.o
	rm ./process/process.o
	rm ./tokenize/makeArgs.o
	rm ./myshrc/startCheck.o
	rm ./history/history.o
	rm ./linkedlist/linkedList.o
	rm ./linkedlist/listUtils.o
	rm ./cd/cd.o
	rm ./path/path.o
	rm ./pipes/pipeArg.o
	rm mysh


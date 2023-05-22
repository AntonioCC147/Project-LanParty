build:
	gcc main.c ./src/tasksFunctions.c ./src/list.c ./src/queue.c ./src/stack.c ./src/BSTandAVL.c -o lanParty
run:
	./lanParty c.in d.in r.out
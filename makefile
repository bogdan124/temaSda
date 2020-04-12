build:
	gcc -o tenis main.c library/alocmem/alocmem.c library/stack/stack.t3.c library/queue/queue.t3.c library/lists/createList.t1.t2.c library/usable/usable.t1.t2.c library/filesFunc/file.ALL_TASK.c library/math/math.t2.t3.c library/tree/tree.t4.t5.c library/tasks/task1/task1.c library/tasks/task2/task2.c library/tasks/task3/task3.c library/tasks/task4/task4.c library/tasks/task5/task5.c -lm -g
run:
	./tenis cerinte.in date.in rezultate.out
clean:
	rm tenis

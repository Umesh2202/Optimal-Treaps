all:	treap.o
	gcc -o all treap.o
treap.o:	treap.c
	gcc -c treap.c

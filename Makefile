final:	main.o treap.o restaurant.o
		cc -o treap main.o treap.o restaurant.o
main.o:	main.c
		cc -c main.c
treap.o:	treap.h treap.c
		cc -c treap.c
restaurant.o:	restaurant.h restaurant.c
		cc -c restaurant.c	
clean:
		rm *.o final
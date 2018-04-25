.PHONY:clean
main:linkqueue.c
	gcc $^ -o $@
clean:
	rm -f main

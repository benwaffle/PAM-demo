CFLAGS=-std=gnu11
LDLIBS=-lpam -lpam_misc
pam-demo: pam-demo.c

.PHONY: clean
clean:
	rm pam-demo

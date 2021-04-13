string:
	- gcc -g -Wall -std=c11 main.c string.h test.h

test:
	- ./a.out

clean:
	- rm ./a.out




string:
	- gcc -march=native -O3 -std=c11 test/main.c test/test.h string.c string.h -o beta

testing:
	- gcc -Wall -Wextra -ggdb3 -march=native -fsanitize=address -fno-omit-frame-pointer -std=c11 test/main.c test/test.h string.c string.h -o debug_sa
	- gcc -Wall -Wextra -ggdb3 -march=native -fsanitize=leak -fno-omit-frame-pointer -std=c11 test/main.c test/test.h string.c string.h -o debug_sl
	- ./debug_sa
	- ./debug_sl

clean:
	- rm beta debug_sa debug_sl





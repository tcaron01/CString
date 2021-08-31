string:
	- gcc -march=native -O3 -std=c11 main.c string.c string.h -o beta

test:
	- gcc -Wall -Wextra -ggdb3 -march=native -fsanitize=address -fno-omit-frame-pointer -std=c11 main.c string.c string.h -o beta
	- ./beta
	- gcc -Wall -Wextra -ggdb3 -march=native -fsanitize=leak -fno-omit-frame-pointer -std=c11 main.c string.c string.h -o beta
	- ./beta

clean:
	- rm ./beta





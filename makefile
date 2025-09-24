main : ./main.c
	gcc ./main.c ./src/printf.c ./src/get_format.c ./src/formats/print_char.c ./src/formats/print_int.c ./src/formats/print_string.c ./src/formats/print_pointer.c -o build/program
	./build/program

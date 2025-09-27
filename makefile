main : ./main.c
	gcc ./main.c ./src/printf.c ./src/get_format.c ./src/formats/print_char.c ./src/formats/print_int.c ./src/formats/print_string.c ./src/formats/print_pointer.c ./src/formats/print_percent.c ./src/get_flags.c ./src/get_width.c ./src/utils/set_width.c ./src/formats/print_uint.c ./src/formats/print_double.c ./src/utils/round.c -o build/program -lm
	./build/program

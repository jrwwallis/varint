# 1st rule is default for `make` with target specified
default: varint_test

%.o: %.s
	$(CC) -c $< -o $@

varint_test: varint.o varint_test.o

clean:
	rm -f varint_test *.o

# Encapsulate command to generate initial ASM from C
varint.intel.s:
	$(CC) -march=native -mbmi -Os -c varint.c -S -masm=intel -o varint.intel.s

CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=libmyBank.o
FLAGS= -Wall -g

make mybanks:
libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs libmylib.a $(OBJECTS_LIB)	

make mybankd:
libmyBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmylib.so $(OBJECTS_LIB)

make mains:
mains: $(OBJECTS_MAIN) libmylib.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a

make maind:
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so

make all:
  libmyBank.so libmyBank.a mains maind

make clean:
	rm -f *.o *.a *.so progmains progmaind

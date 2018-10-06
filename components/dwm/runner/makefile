APP=runner
SRC=$(APP).c
objects=$(APP).o logo.o
#CFLAGS=-O3 -m64
#CFLAGS=-O0 -g3
all:$(APP)
$(APP): $(objects)
	gcc -o$(APP) $(objects) `pkg-config gtk+-2.0 --libs`
$(APP).o: $(SRC)
	gcc -std=gnu99 -c -o$(APP).o -DLANG_RUS $(CFLAGS) `pkg-config gtk+-2.0 --cflags` $(SRC)
logo.o: logo.c
	gcc -c -ologo.o logo.c
clean:
	rm -f $(APP) $(objects)

install: $(APP)
	cp $(APP) /usr/bin

APP=dwm_calendar
SRC=$(APP).c
objects=$(APP).o
#CFLAGS=-O3 -m64
#CFLAGS=-O0 -g3
all:$(APP)
$(APP): $(objects)
	gcc -o$(APP) $(objects) `pkg-config gtk+-2.0 --libs`
$(APP).o: $(SRC)
	gcc -c -o$(APP).o $(CFLAGS) `pkg-config gtk+-2.0 --cflags` $(SRC)
clean:
	rm -f $(APP) $(objects)
install: $(APP)
	cp $(APP) /usr/bin

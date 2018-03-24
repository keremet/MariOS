CC=gcc

PROG=crttymon

SOURCES= sttyparse.c tmexpress.c tmlog.c tmsac.c tmutil.c \
	sttytable.c tmglobal.c tmparse.c tmsig.c tmutmp.c \
	tmautobaud.c tmhandler.c tmpeek.c tmterm.c ttymon.c \
	tmchild.c tmlock.c tmpmtab.c tmttydefs.c ulockf.c



OBJECTS=$(SOURCES:.c=.o)

all: $(PROG)

$(PROG): $(OBJECTS)
	gcc -o $@ $(OBJECTS) -lpam -lsec -lnsl -ldevinfo

clean:
	rm -rf $(PROG) $(OBJECTS)

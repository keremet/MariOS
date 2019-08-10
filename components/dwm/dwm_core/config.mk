export OSTYPE = $(shell uname)

# dwm version
VERSION = 6.1

# Customize below to fit your system

# paths
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Xinerama, comment if you don't want it
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

# freetype
FREETYPELIBS = -lfontconfig -lXft
ifeq ($(OSTYPE), OpenBSD)
  FREETYPEINC = /usr/X11R6/include/freetype2
else
  FREETYPEINC = /usr/include/freetype2
endif

# includes and libs
INCS = -I${X11INC} -I${FREETYPEINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS}

# flags
CPPFLAGS = -D_XPG6 -D_BSD_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}

#debug
#CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
#LDFLAGS  = ${LIBS}

#release
CFLAGS   = -std=gnu99 -pedantic -Wall -Wno-deprecated-declarations -O3 ${INCS} ${CPPFLAGS}
LDFLAGS  = -s ${LIBS}


# Solaris
#CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC = gcc

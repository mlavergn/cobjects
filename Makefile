###############################################
#
# Makefile
#
###############################################

CC       :=  clang
INCL     := -I/usr/include -I..
#CFLAGS   := -g -O2 $(INCL) -shared -fPIC
CFLAGS   := -std=c11 -g -O2 $(INCL) -mmacosx-version-min=10.9 -fPIC -fnested-functions -fms-extensions -Wno-microsoft

LD       :=  clang
LIBS     := 
LDFLAGS  := -L/usr/local/lib -L/usr/lib64 $(LIBS)

DEFS     := -DHAVE_CONFIG_H

SRCS     := main.c cobject.c
ONAME    := demo

all: clean $(ONAME)

$(ONAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(ONAME) $(LIBS)

clean:
	rm -rf $(ONAME) $(ONAME).dSYM $(ONAME).tar.gz

dist: clean
	tar -czvf $(ONAME).tar.gz Makefile $(SRCS)

.POSIX:

DEST = /usr/bin
SRC = hp.c dgn.c npc.c rl.c
EXES = $(SRC:.c=)
COMMON = common

all: $(EXES)

options:
	@echo "DEST   = $(DEST)"
	@echo "SRC    = $(SRC)"
	@echo "EXES   = $(EXES)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "CC     = $(CC)"

clean:
	rm -f $(EXES)

install: all
	cp -f $(EXES) $(DEST)

uninstall:
	@$(foreach EXE,$(EXES), rm -f $(DEST)/$(EXE))

dist: clean
	mkdir -p rpg_tools-dist
	cp -R README TODO Makefile $(COMMON).* $(SRC) rpg_tools-dist
	tar -cf - rpg_tools-dist | gzip > rpg_tools.tar.gz
	rm -rf rpg_tools-dist

hp:
	$(CC) $(CFLAGS) $@.c $(COMMON).c -o $@

dgn:
	$(CC) $(CFLAGS) $@.c -o $@

rl:
	$(CC) $(CFLAGS) $@.c $(COMMON).c -o $@

npc:
	$(CC) $(CFLAGS) $@.c $(COMMON).c -o $@

.PHONY: all options clena install uninstall dist

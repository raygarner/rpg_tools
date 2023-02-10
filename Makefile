.POSIX:

DEST = /usr/bin
EXES = hp dgn npc rl
COMMON = common.c

all: $(EXES)

options:
	@echo "CFLAGS = $(CFLAGS)"
	@echo "CC     = $(CC)"

clean:
	rm -f $(EXES)

install: all
	cp -f $(EXES) $(DEST)

uninstall:
	@$(foreach EXE,$(EXES), rm -f $(DEST)/$(EXE))

hp:
	$(CC) $(CFLAGS) $@.c $(COMMON) -o $@

dgn:
	$(CC) $(CFLAGS) $@.c -o $@

rl:
	$(CC) $(CFLAGS) $@.c $(COMMON) -o $@

npc:
	$(CC) $(CFLAGS) $@.c $(COMMON) -o $@

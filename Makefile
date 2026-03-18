all: mac

mac:
	clang -o mac rosetta.c
	otool -tvV ./mac > mac-dump
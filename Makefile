all: mac

mac:
	clang -o mac rosetta2.c
	otool -tvV ./mac > mac-dump
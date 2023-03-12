cc = gcc
SRCDIR = src
INCLUDE = include
TARGET = moon
LIBS = -lpthread -lSDL2 -lSDL2_mixer
CFLAGS = -I$(INCLUDE)

$(TARGET) : $(SRCDIR)/flowers_and_dreams.c $(SRCDIR)/intro.c $(SRCDIR)/loneliness.c $(SRCDIR)/losing.c $(SRCDIR)/main.c $(SRCDIR)/map.c $(SRCDIR)/moon.c $(SRCDIR)/pain.c $(SRCDIR)/sprites.c $(SRCDIR)/util.c $(SRCDIR)/examples.c
	$(cc) $(SRCDIR)/flowers_and_dreams.c $(SRCDIR)/intro.c $(SRCDIR)/loneliness.c $(SRCDIR)/losing.c $(SRCDIR)/main.c $(SRCDIR)/map.c $(SRCDIR)/moon.c $(SRCDIR)/pain.c $(SRCDIR)/sprites.c $(SRCDIR)/util.c $(SRCDIR)/examples.c $(CFLAGS) -o $(TARGET) $(LIBS)

file2array : misc/file2array.c
	$(cc) misc/file2array.c -o misc/file2array


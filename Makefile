# make exe または make ocexeで実行

TARGET = clock.exe

SRCS = display.c \
	clock.c \
	main.c \
	shape.c \

OBJS = ${SRCS:.c=.o}

HEADERS = wintime.h

# Linux
# CC = gcc
# CCFLAGS = -Wall
# LD = gcc
# LDFLAGS = 
# LIBS = -lm -lglpng -lglut -lGLU -lGL

# windows
CC = i686-pc-cygwin-gcc
CCFLAGS = -Wall -I/usr/include/opengl
LD = $(CC)
LDFLAGS =
LIBS = -lm -lglpng -lglut32 -lglu32 -lopengl32

$(TARGET) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBS)

.c.o :
	$(CC) $(CCFLAGS) -c $<

$(OBJS) : $(HEADERS) Makefile

c :
	rm -f $(OBJS) $(TARGET) core *~

oc :
	rm -f $(OBJS) core *~

exec :
	rm -f $(TARGET) core *~

exe : $(TARGET)
	./$(TARGET)

ocexe : $(TARGET)
	rm -f $(OBJS) core *~
	./$(TARGET)
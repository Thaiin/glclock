# make exe または make ocexeで実行

TARGET = clock.exe

SRCS = callbackfunc.c \
	genericfunc.c \
	printclock.c \
	printtime.c \
	setting.c \
	arc.c \
	main.c

SRCSRC = clockicon.rc

OBJS = ${SRCS:.c=.o} \
	clockicon.o

HEADERS = define.h \
	includefile.h \
	struct.h \
	prototype.h

# windows (LDをi686-pc-cygwin-windresに変更)
CC = i686-pc-cygwin-gcc
CCFLAGS = -Wall -I/usr/include/opengl
LD = i686-pc-cygwin-windres
LDFLAGS =
LIBS = -lm -lglpng -lglut32 -lglu32 -lopengl32

$(TARGET) : $(OBJS)
	$(LD) -i $(SRCSRC) clockicon.o
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBS)

.c.o :
	$(CC) $(CCFLAGS) -c $<

$(OBJS) : $(HEADERS) Makefile

c :					# oファイル, exeファイルを消去
	rm -f $(OBJS) $(TARGET) core *~

oc :				# oファイルを消去
	rm -f $(OBJS) core *~

exec :				# exeファイルを消去
	rm -f $(TARGET) core *~

exe : $(TARGET)		# コード変更を確認して実行する
	./$(TARGET)

ocexe : $(TARGET)	# ocとexeの機能を持つコマンド
	rm -f $(OBJS) core *~
	./$(TARGET)
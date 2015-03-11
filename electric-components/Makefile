LD_NAMES = iec61850
LD_NAMES += pthread
LD_NAMES += curl

LDLIBS = $(addprefix -l, $(LD_NAMES))

CFLAGS += -Wall

all: gebrick.x

gebrick.x: electric_common.o static_model_ge_brick.o gebrick.o
	gcc -o gebrick.x electric_common.o static_model_ge_brick.o gebrick.o $(LDLIBS)

electric_common.o: electric_common.h electric_common.c
	gcc -c electric_common.c

static_model_ge_brick.o: static_model_ge_brick.h static_model_ge_brick.c
	gcc -c static_model_ge_brick.c

gebrick.o: electric_common.h electric_common.c static_model_ge_brick.h static_model_ge_brick.c gebrick.c
	gcc -c gebrick.c

clean:
	rm *.o
	rm gebrick.x
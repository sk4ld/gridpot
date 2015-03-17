LD_NAMES = iec61850
LD_NAMES += pthread
LD_NAMES += curl

LIBIEC61850 = ../libiec61850-0.8.5

LDLIBS = $(addprefix -l, $(LD_NAMES))

CFLAGS += -Wall

all: gebrick.x ied_attack.x

gebrick.x: electric_common.o static_model_switch_control.o gebrick.o
	gcc $(CFLAGS) -o gebrick.x electric_common.o static_model_switch_control.o gebrick.o $(LDLIBS)

electric_common.o: electric_common.h electric_common.c
	gcc -c electric_common.c

static_model_ge_brick.o: static_model_ge_brick.h static_model_ge_brick.c
	gcc -c static_model_ge_brick.c

static_model_switch_control.o: static_model_switch_control.h static_model_switch_control.c
	gcc -c static_model_switch_control.c

gebrick.o: electric_common.h electric_common.c static_model_ge_brick.h static_model_ge_brick.c gebrick.c
	gcc -c gebrick.c

gebrickmodel: gebrick.icd
	java -jar $(LIBIEC61850)/tools/model_generator/genmodel.jar gebrick.icd
	mv static_model.h static_model_ge_brick.h
	mv static_model.c static_model_ge_brick.c

switchcontrolmodel: switch_control.icd
	java -jar $(LIBIEC61850)/tools/model_generator/genmodel.jar switch_control.icd
	mv static_model.h static_model_switch_control.h
	mv static_model.c static_model_switch_control.c

clean:
	rm *.o
	rm *.x

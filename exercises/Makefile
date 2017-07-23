SRCDIR := ch19/03
USE_STD_LIB_FACILITIES := 0


# Not to be modified

CC := g++
DEBUG := -g
STD := -std=gnu++11

SRC := $(wildcard $(SRCDIR)/*.cpp)

PROJ_ROOT := /home/philip/Desktop/c++/programming_principles
INC_ROOT := -I$(PROJ_ROOT)/programs/include

ifeq ($(USE_STD_LIB_FACILITIES),0)
    INCS :=
else
    INCS := $(INC_ROOT)
endif

LIBS :=

all:
	$(CC) $(DEBUG) $(STD) $(SRC) $(INCS) $(LIBS)

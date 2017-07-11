SRCDIR := ch18/array
USE_FLTK := 0



# Not to be modified

CC := g++
DEBUG := -g
STD := -std=gnu++11

SRC := $(wildcard $(SRCDIR)/*.cpp)


ROOT_DIR := /home/philip/Desktop/c++/programming_principles
LIB_DIR  := $(ROOT_DIR)/libraries
FLTK_DIR := $(LIB_DIR)/fltk-1.3.4-1
INC_ROOT_DIR := $(ROOT_DIR)/programs/include
GRAPHICS_DIR := $(INC_ROOT_DIR)/graphics

INC_ROOT := -I$(INC_ROOT_DIR)
INC_FLTK := -I$(FLTK_DIR) -I/usr/include/freetype2
INC_GRAPHICS := -I$(GRAPHICS_DIR)

LIB_FLTK := $(FLTK_DIR)/lib/libfltk.a $(FLTK_DIR)/lib/libfltk_images.a -lXfixes -lXext -lfontconfig -lpthread -ldl -lm -lX11
LIB_FLTK += -L/usr/local/lib -ljpeg


ifeq ($(USE_FLTK),0)
    INCS := $(INC_ROOT)
    LIBS := 
else
    INCS := $(INC_ROOT) $(INC_FLTK) $(INC_GRAPHICS)
    LIBS := $(LIB_FLTK)

    # Additional source files
    SRC += $(wildcard $(GRAPHICS_DIR)/*.cpp)
endif


all:
	$(CC) $(DEBUG) $(STD) $(SRC) $(INCS) $(LIBS)

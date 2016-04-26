Target := IrrlichtBin
Sources := main.cpp
IrrlichtHome := ..
BinPath = ../bin/
USERCPPFLAGS = 
USERCXXFLAGS = -O3 -ffast-math
USERCXXFLAGS = -g -Wall
USERLDFLAGS =
CPPFLAGS = -I$(IrrlichtHome)/include -I/usr/X11R6/include $(USERCPPFLAGS)
CXXFLAGS = $(USERCXXFLAGS)
LDFLAGS = $(USERLDFLAGS)
DESTPATH = $(BinPath)/$(Target)$(SUF)
LDFLAGS = -L/usr/X11R6/lib$(LIBSELECT) -L../lib/ -lIrrlicht -lGL -lGLU -lXrandr -lXext -lX11  -lXxf86vm

all: all_linux

all_linux:
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Sources) -o $(DESTPATH) $(LDFLAGS)

clean: clean_linux clean_win32
	$(warning Cleaning...)

fclean:	clean
	@$(RM) $(DESTPATH)

re:	fclean all

clean_linux clean_win32:
	@$(RM) $(DESTPATH)

.PHONY: all all_win32 static_win32 clean clean_linux clean_win32

#multilib handling
ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif
#solaris real-time features
ifeq ($(HOSTTYPE), sun4)
LDFLAGS += -lrt
endif


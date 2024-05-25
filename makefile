# General
OBJDIR := obj
BINDIR := bin

EXE := $(BINDIR)/minesweeper

# Compiling
CXX := g++
CXXFLAGS := -std=c++23
LDFLAGS :=

PPFLAGS := -IMSBase/MSBits/ -IMSBase/ -MMD -MP

# Sources
SRC := main.cpp
SRC += $(wildcard MSBase/*.cpp)

ifeq ($(DISPLAY), cli_debug)
	SRC += CLIDebugDisplay.cpp
endif

ifeq ($(DISPLAY), cli)
	SRC += CLIDisplay.cpp
endif

ifeq ($(DISPLAY), cli_both)
	SRC += CLIDebugDisplay.cpp
	SRC += CLIDisplay.cpp
endif

# Objects
OBJ := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

# Use flags
ifeq ($(COLOR), true)
	CXXFLAGS += -D__USE_COLOR
endif

# Rules
.PHONY : all clean

all : $(EXE)

$(EXE) : $(OBJ) | $(BINDIR)
	@echo "Linking executable: $@"
	@$(CXX) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o : %.cpp
	@echo "CXX: $@"
	@mkdir -p $(@D)
	@$(CXX) $(PPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BINDIR) :
	@mkdir -p $(BINDIR)

clean :
	@rm -rv $(BINDIR) $(OBJDIR)

-include $(OBJ:.o=.d)

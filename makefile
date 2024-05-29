# General
OBJDIR := obj
BINDIR := bin
CLIDIR := CLI
SFMLDIR := SFML

EXE := $(BINDIR)/minesweeper

# Compiling
CXX := g++
CXXFLAGS := -std=c++23
LDFLAGS :=

PPFLAGS := -IMSBase/MSBits/ -IMSBase/ -ICLI/ -ISFML/ -MMD -MP

# Sources
SRC := main.cpp
SRC += $(wildcard MSBase/*.cpp)

ifeq ($(DISPLAY), cli_debug)
	SRC += $(CLIDIR)/DebugDisplay.cpp
else ifeq ($(DISPLAY), cli)
	SRC += $(CLIDIR)/Display.cpp
else ifeq ($(DISPLAY), cli_both)
	SRC += $(CLIDIR)/DebugDisplay.cpp
	SRC += $(CLIDIR)/Display.cpp
else ifeq ($(DISPLAY), sfml_debug)
	SRC += $(SFMLDIR)/DebugDisplay.cpp
else ifeq ($(DISPLAY), sfml)
	SRC += $(SFMLDIR)/Display.cpp
else ifeq ($(DISPLAY), sfml_both)
	SRC += $(SFMLDIR)/DebugDisplay.cpp
	SRC += $(SFMLDIR)/Display.cpp
else
	SRC += $(wildcard $(CLIDIR)/*Display.cpp)
	SRC += $(wildcard $(SFMLDIR)/*Display.cpp)
	SFML := true
endif

ifeq ($(CONTROLLER), cli)
	SRC += $(CLIDIR)/Controller.cpp
endif

ifeq ($(SFML), true)
	SRC += $(wildcard SFMLBase/*.cpp)
endif

# Objects
OBJ := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

# Use flags
ifeq ($(COLOR), true)
	CXXFLAGS += -D__USE_COLOR
endif

ifeq ($(SFML), true)
	LDFLAGS += -lsfml-system -lsfml-window -lsfml-graphics
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

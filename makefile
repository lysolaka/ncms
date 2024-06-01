# General
OBJDIR := obj
BINDIR := bin

MSBASEDIR := MSBase
CLIDIR := CLI
SFMLBASEDIR := SFMLBase
SFMLDIR := SFML

# Compiling
CXX := g++
CXXFLAGS := -std=c++23
LDFLAGS :=
SFML_LDFLAGS := -lsfml-system -lsfml-window -lsfml-graphics

PPFLAGS := -IMSBase/MSBits/ -IMSBase/ -ICLI/ -ISFMLBase/ -ISFML/ -MMD -MP

# Sources
SRC_MSBASE := $(wildcard $(MSBASEDIR)/*.cpp)
SRC_SFMLBASE := $(wildcard $(SFMLBASEDIR)/*.cpp)

SRC_CLI := $(CLIDIR)/Controller.cpp
SRC_CLI += $(CLIDIR)/Display.cpp
SRC_CLI += $(CLIDIR)/MainMenu.cpp
SRC_CLI += CLI.cpp

SRC_CLI_DEBUG := $(CLIDIR)/Controller.cpp
SRC_CLI_DEBUG += $(CLIDIR)/DebugDisplay.cpp
SRC_CLI_DEBUG += $(CLIDIR)/MainMenu.cpp
SRC_CLI_DEBUG += CLIDebug.cpp

SRC_SFML := $(SFMLDIR)/Controller.cpp
SRC_SFML += $(SFMLDIR)/Display.cpp
SRC_SFML += SFML.cpp

SRC_SFML_DEBUG := $(SFMLDIR)/Controller.cpp
SRC_SFML_DEBUG += $(SFMLDIR)/DebugDisplay.cpp
SRC_SFML_DEBUG += SFMLDebug.cpp

# Objects
OBJ_MSBASE := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC_MSBASE))
OBJ_SFMLBASE := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC_SFMLBASE))

OBJ_CLI := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC_CLI))
OBJ_CLI += $(OBJ_MSBASE)

OBJ_CLI_DEBUG := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC_CLI_DEBUG))
OBJ_CLI_DEBUG += $(OBJ_MSBASE)

OBJ_SFML := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC_SFML))
OBJ_SFML += $(OBJ_SFMLBASE)
OBJ_SFML += $(OBJ_MSBASE)

OBJ_SFML_DEBUG := $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC_SFML_DEBUG))
OBJ_SFML_DEBUG += $(OBJ_SFMLBASE)
OBJ_SFML_DEBUG += $(OBJ_MSBASE)

# Use flags
ifeq ($(COLOR), true)
	CXXFLAGS += -D__USE_COLOR
endif

ifeq ($(OPTIMISE), true)
	CXXFLAGS += -O2
endif

# Rules
.PHONY : all clean cli cli_debug sfml sfml_debug

all : cli cli_debug sfml sfml_debug

cli : $(OBJ_CLI) | $(BINDIR)
	@echo "Linking executable: bin/cli_sweeper"
	@$(CXX) $(LDFLAGS) $^ -o bin/cli_sweeper

cli_debug : $(OBJ_CLI_DEBUG) | $(BINDIR)
	@echo "Linking executable: bin/cli_sweeper_debug"
	@$(CXX) $(LDFLAGS) $^ -o bin/cli_sweeper_debug

sfml : $(OBJ_SFML) | $(BINDIR)
	@echo "Linking executable: bin/sfml_sweeper"
	@$(CXX) $(LDFLAGS) $(SFML_LDFLAGS) $^ -o bin/sfml_sweeper

sfml_debug : $(OBJ_SFML_DEBUG) | $(BINDIR)
	@echo "Linking executable: bin/sfml_sweeper_debug"
	@$(CXX) $(LDFLAGS) $(SFML_LDFLAGS) $^ -o bin/sfml_sweeper_debug

$(OBJDIR)/%.o : %.cpp
	@echo "CXX: $@"
	@mkdir -p $(@D)
	@$(CXX) $(PPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BINDIR) :
	@mkdir -p $(BINDIR)

clean :
	@rm -rv $(BINDIR) $(OBJDIR)

-include $(OBJ:.o=.d)

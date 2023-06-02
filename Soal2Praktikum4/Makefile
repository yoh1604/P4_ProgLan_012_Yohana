# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -Iinclude

# Directories
SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGETDIR := bin
TARGET := $(TARGETDIR)/end_of_us

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Platform-specific variables and commands
ifeq ($(OS),Windows_NT)
	RM := del /Q
	FixPath = $(subst /,\,$1)
	MKDIR := mkdir
else
	RM := rm -rf
	FixPath = $1
	MKDIR := mkdir -p
endif

# Default target
all: $(TARGET)

# Create build directory
$(BUILDDIR):
	$(MKDIR) $(call FixPath,$(BUILDDIR))

# Create target directory
$(TARGETDIR):
	$(MKDIR) $(call FixPath,$(TARGETDIR))

# Compile source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link object files into executable
$(TARGET): $(OBJECTS) | $(TARGETDIR)
	$(CXX) $^ -o $(call FixPath,$(TARGET))

# Clean the build directory
clean:
	$(RM) $(call FixPath,$(BUILDDIR)) $(call FixPath,$(TARGET))

# Phony targets
.PHONY: all clean
CC=clang++
CFLAGS=-c -pthread -std=c++11 -g -D_GLIBCXX_DEBUG 
LDFLAGS=-lpthread -lrt 
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(addprefix obj/, $(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE=logger

all: $(SOURCES) $(EXECUTABLE)

config:
	@echo "================================================"
	@tput setf 2
	@echo "Libs:"
	@tput setf 7
	@echo "$(LIBS)"
	@echo "================================================"
	@tput setf 2
	@echo "Objects:"
	@tput setf 7
	@echo "$(OBJECTS)"
	@echo "================================================"
	@tput setf 2
	@echo "Sources:"
	@tput setf 7
	@echo "$(SOURCES)"
	@echo "================================================"
	@tput setf 2
	@echo "Executable file:"
	@tput setf 7
	@echo "$(EXECUTABLE)"
	@echo "================================================"

clean:
	@tput setf 2
	@echo "Cleaning object files...    $(OBJECTS)"
	@rm -f obj/*.o
	@echo "Cleaning executable file... $(EXECUTABLE)"
	@rm -f $(EXECUTABLE)
	@echo "Cleaning done!"
	@tput setf 7

$(EXECUTABLE): $(OBJECTS)
	@tput setf 5
	@echo "Linking libs..."
	@tput setf 7
	@tput sgr0
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@

obj/%.o: src/%.cpp
	@tput bold
	@tput setf 2
	@echo "Compiling $(^)"
	@echo "       to $(@)"
	@tput setf 7
	@$(CC) $(CFLAGS) $< -o $@

help h:
	@echo -n "Usage: "
	@tput setf 2
	@echo "make [option]"
	@tput setf 7
	@echo "Avaliable options are:"
	@tput setf 3
	@echo -n "       all    "
	@tput setf 7
	@echo "- build whole workspace "
	@tput setf 3
	@echo -n "       config "
	@tput setf 7
	@echo "- shows configuration of workspace "
	@tput setf 3
	@echo -n "       clean  "
	@tput setf 7
	@echo "- cleans workspace from temporary files "

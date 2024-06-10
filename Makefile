NAME =			efDesktop
LIBNAME =
LIBFILE =		lib$(LIBNAME).a

SRC =			$(wildcard ./src/*.cpp)	\
			$(wildcard ./src/*/*.cpp) \

OBJS =			$(SRC:.cpp=.o)
INCLUDE =		-I./include
CPP =			g++

FLAGS =			-Wall -Wextra
GCOV_FLAGS =		--coverage
LDFLAGS =		-L./ -rdynamic

GDB_FLAGS =		-O0 -g -ggdb -g3
GCOV_FLAGS =		-O0 --coverage
LAPIN_FLAGS =		-L./ -llapin -lsfml-graphics -lsfml-audio -lsfml-window		\
			-lsfml-system -lstdc++ -lm -ldl -lpthread			\
			-lopencv_imgproc -lopencv_highgui				\
		        -lopencv_objdetect -lopencv_videoio				\
	                -lopencv_core -lavcall						\

OPT_FLAGS += $(GDB_FLAGS)
ifeq ($(GCOV), 1)
	OPT_FLAGS += $(GCOV_FLAGS)
endif

OPT_FLAGS += $(LAPIN_FLAGS)

all: $(NAME)

rerun: fclean run

run: $(NAME)

$(LIBFILE): $(OBJS)
	ar rsc $(LIBFILE) $(OBJS)

lib:$(LIBFILE)

.cpp.o:
	$(CPP) $(FLAGS) $(OPT_FLAGS) $(TEST_INCLUDE) $(INCLUDE) -c $< -o $@

clean:
	rm -f Makefile~
	rm -f $(shell find ./ -name "*.o")
	rm -f $(shell find ./ -name "*~")
	rm -f $(shell find ./ -name "*.gcno")
	rm -f $(shell find ./ -name "*.gcov")

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

tree: fclean
	tree

report:$(NAME)
	./$(NAME)
	lcov --capture --directory . --output-file main_coverage.info
	genhtml main_coverage.info --output-directory report
	firefox report/index.html

$(NAME):$(OBJS)
	$(CPP) $(OBJS) $(OPT_FLAGS) $(LDFLAGS) -o $(NAME)




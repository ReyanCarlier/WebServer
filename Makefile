################################################################################
#                         MAKEFILE FOR C++ PROJECTS                            #
#						    MADE BY: Reyan CARLIER                             #
#						      VERSION: 1.0.1                                   #
################################################################################


################################################################################
#                                    CONFIG                                    #
################################################################################

# Name of the binary to create :
TARGET = WebServer

# Compiler to use :
CXX = c++

# Flags to use :
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

################################################################################
#                                   SOURCES                                    #
################################################################################

# Add here the name of the files you want to compile (without the extension) :
SRCS_FILES	:=		WebServer \
					Server

SRCS_FILES	:= 		$(addsuffix .cpp, $(SRCS_FILES))

# Add here the name of the directory where .cpp files are located :
SRCS_DIR	= 		src/

VPATH		= 		$(SRCS_DIR)

################################################################################
#                                  HEADERS                                     #
################################################################################

# Add here the name of the directory where .hpp files are located :
HEADS_DIR 	= 		include/

# Add here the name of the directory where .hpp files are located, without the / :
HEADS_DIRN 	= 		include

################################################################################
#                                  OBJECTS                                     #
################################################################################

# Add here the name of the directory where .o files are created :
OBJS_DIR	= 		obj/

OBJS_DIRN	= 		$(OBJS_DIR)

OBJS		=		$(patsubst %.cpp,$(OBJS_DIR)%.o,${SRCS_FILES})

OBJS_DUP	=		$(patsubst %.cpp,%.o,${SRCS_FILES})

NEW_OBJS	=		0

################################################################################
#                                  DEPS                                     #
################################################################################

# Add here the name of the directory where .d files are created :
DEPS_DIR 	= 		deps/

DEPS_DIRN	=		$(DEPS_DIR)

DEPS		=		$(patsubst %.o,${DEPS_DIR}%.d,${OBJS_DUP})

NEW_DEPS	=		0

################################################################################
#                                   RULES                                      #
################################################################################

CLR_RMV		:=		\033[0m
RED		    :=		\033[1;31m
GREEN		:=		\033[1;32m
YELLOW		:=		\033[1;33m
BLUE		:=		\033[1;34m
CYAN 		:=		\033[1;36m
RM		    :=		rm -rf

all: $(TARGET)

${TARGET}:	${DEPS} | ${OBJS}
			@echo "$(BLUE)Generated $(NEW_OBJS) objects successfully ! ✔️"
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(TARGET) ${CLR_RMV}binary ..."
			@ $(CXX) $(CXXFLAGS) -I$(HEADS_DIR) $(OBJS) -o $(TARGET)
			@echo "$(YELLOW)$(TARGET) $(GREEN)binary created ✔️"

$(OBJS_DIR)%.o: %.cpp | makedir_objs
	@if [ ! $(NEW_OBJS) != 0 ]; then echo "$(BLUE)Generating $(YELLOW)$(TARGET) $(BLUE)objects :"; else : ; fi
	$(eval NEW_OBJS=$(shell echo $$(($(NEW_OBJS)+1))))
				@ echo "$(CLR_RMV)- $(CYAN)$@";
				@ $(CXX) $(CXXFLAGS) -I$(HEADS_DIR) -c $< -o $@

TMP_FILE =

BLOCK_DEPS = 0

${DEPS_DIR}%.d : %.cpp | makedir_deps
	@ if [ ! $(NEW_DEPS) != 1 ]; then \
		if [ ! $(BLOCK_DEPS) != 1 ]; then \
			echo "$(BLUE)Generating $(YELLOW)$(TARGET) $(BLUE)dependencies :"; \
		fi \
	fi
	$(eval NEW_DEPS=$(shell echo $$(($(NEW_DEPS)+1))))
	@ if [ ! $(BLOCK_DEPS) != 0 ]; then echo "$(CLR_RMV)- $(CYAN)$@"; fi
	@ if [ ! $(BLOCK_DEPS) != 0 ]; then echo -n "$@ " > $@.tmp; fi
	$(eval TMP_FILE=$(shell echo $@ | sed "s/$(DEPS_DIR)$(OBJS_DIR)"g))
	$(eval TMP_FILE=$(shell echo $(TMP_FILE) | sed "s/.d/.o/g"))
				@ if [ ! $(BLOCK_DEPS) != 0 ]; then $(CXX) -I$(HEADS_DIR) $(CXXFLAGS) -MM -MP -MT $(TMP_FILE) $< >> $@.tmp; fi
				@ if [ ! $(BLOCK_DEPS) != 0 ]; then mv $@.tmp $@; fi

makedir_objs:
	@ if [ ! -e "$(OBJS_DIRN)" ]; then \
		if [ ! $(BLOCK_DEPS) != 0 ]; then \
			mkdir -p $(OBJS_DIRN); \
			echo "$(GREEN)Creation ${CLR_RMV}of ${CYAN}objects ${CLR_RMV}directory ✔️"; \
		fi \
	fi

makedir_deps:
	@ if [ ! -e "$(DEPS_DIRN)" ]; then \
		if [ ! $(BLOCK_DEPS) != 0 ]; then \
			mkdir -p $(DEPS_DIRN); \
			echo "$(GREEN)Creation ${CLR_RMV}of ${CYAN}depends ${CLR_RMV}directory ✔️"; \
		fi \
	fi

clean:
	$(eval BLOCK_DEPS=$(shell echo $$(($(BLOCK_DEPS)+1))))
	@if [ ! -e "$(OBJS_DIR)" ]; then echo "$(YELLOW)$(TARGET) $(CLR_RMV)objects folder already $(RED)deleted $(CLR_RMV)! ✔️" ; else ${RM} $(OBJS_DIR); echo "$(RED)Deleted $(YELLOW)$(TARGET) $(BLUE)objects $(CLR_RMV)folder ✔️"; fi
	@if [ ! -e "${DEPS_DIRN}" ]; then echo "$(YELLOW)$(TARGET) $(CLR_RMV)dependencies folder already $(RED)deleted $(CLR_RMV)! ✔️" ; else ${RM} ${DEPS_DIRN}; echo "$(RED)Deleted $(YELLOW)$(TARGET) $(BLUE)dependencies $(CLR_RMV)folder ✔️"; fi
			
fclean: 	clean
	@if [ ! -e "$(TARGET)" ]; then echo "$(YELLOW)$(TARGET) $(CLR_RMV)binary already $(RED)deleted $(CLR_RMV)! ✔️"; else ${RM} ${TARGET}; echo "$(RED)Deleted $(YELLOW)$(TARGET) $(CLR_RMV)binary ✔️"; fi

unblock:
	$(eval BLOCK_DEPS=$(shell echo $$(($(BLOCK_DEPS)-1))))

re: fclean unblock all

.PHONY: clean fclean re all

ifeq (,$(filter clean, $(MAKECMDGOALS)))
	-include $(DEPS)
endif

%.o: %.cpp Makefile
	@ $(CXX) $(CXXFLAGS) -MMD -MP $< -o $@
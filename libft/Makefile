MAKEFLAGS 		+= --no-print-directory --silent

CFLAGS			?= -Wall -Wextra -Werror
AFLAGS			?= -S -masm=intel -fverbose-asm
ARFLAGS			?= -rcs

AR        		:= ar
CC				:= cc
NAME 			:= libft.a

INC_DIR			:= includes
OBJ_DIR     	:= obj
ASM_DIR     	:= asm

LIBFT_SRCS := \
	ft_atoi.c		ft_bzero.c		ft_calloc.c	\
	ft_isalnum.c	ft_isalpha.c 	ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_isspace.c \
	ft_itoa.c		ft_memchr.c \
	ft_memcmp.c		ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_putchar_fd.c \
	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c		ft_strchr.c \
	ft_strdup.c		ft_striteri.c	ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c \
	ft_strlen.c		ft_strmapi.c	ft_strncmp.c	ft_strnstr.c	ft_strrchr.c \
	ft_strtrim.c	ft_substr.c		ft_tolower.c	ft_toupper.c \
	\
	ft_lstadd_back_bonus.c		ft_lstadd_front_bonus.c			ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c		ft_lstiter_bonus.c				ft_lstlast_bonus.c \
	ft_lstmap_bonus.c			ft_lstnew_bonus.c				ft_lstsize_bonus.c \

GNL_SRCS := \
	get_next_line_bonus.c		get_next_line_utils_bonus.c

PRINTF_SRCS := \
	ft_printf.c					ft_printf_process_nbr.c			ft_printf_process_str.c \
	ft_printf_process_hex.c		ft_printf_setparams.c

PRINTF_FD_SRCS := \
	ft_printf_fd.c				ft_printf_fd_process_nbr.c		ft_printf_fd_process_str.c \
	ft_printf_fd_process_hex.c	ft_printf_fd_setparams.c

EXTRA_SRCS := \
	ft_cputchar_fd.c			ft_cputnchar_fd.c				ft_cputstrn_fd.c \
	ft_ltoa.c					ft_max.c						ft_min.c \
	ft_nblen.c					ft_unblen.c						ft_utoa_base.c \
	ft_strtolower.c				ft_strtoupper.c					ft_issign.c \
	ft_split_charset.c			ft_strchr_charset.c				ft_atoi_overflow.c

LIBFT_OBJS  	:= $(addprefix $(OBJ_DIR)/libft/, $(LIBFT_SRCS:.c=.o))
PRINTF_OBJS 	:= $(addprefix $(OBJ_DIR)/ft_printf/, $(PRINTF_SRCS:.c=.o))
PRINTF_FD_OBJS	:= $(addprefix $(OBJ_DIR)/ft_printf_fd/, $(PRINTF_FD_SRCS:.c=.o))
GNL_OBJS    	:= $(addprefix $(OBJ_DIR)/get_next_line/, $(GNL_SRCS:.c=.o))
EXTRA_OBJS  	:= $(addprefix $(OBJ_DIR)/extras/, $(EXTRA_SRCS:.c=.o))


LIBFT_ASMS  	:= $(addprefix $(ASM_DIR)/libft/, $(LIBFT_SRCS:.c=.s))
PRINTF_ASMS 	:= $(addprefix $(ASM_DIR)/ft_printf/, $(PRINTF_SRCS:.c=.s))
PRINTF_FD_ASMS	:= $(addprefix $(ASM_DIR)/ft_printf_fd/, $(PRINTF_FD_SRCS:.c=.s))
GNL_ASMS    	:= $(addprefix $(ASM_DIR)/get_next_line/, $(GNL_SRCS:.c=.s))
EXTRA_ASMS  	:= $(addprefix $(ASM_DIR)/extras/, $(EXTRA_SRCS:.c=.s))

ALL_ASMS  	:= $(LIBFT_ASMS) $(PRINTF_ASMS) $(PRINTF_FD_ASMS) $(GNL_ASMS) $(EXTRA_ASMS)
ALL_OBJS    := $(LIBFT_OBJS) $(PRINTF_OBJS) $(PRINTF_FD_OBJS) $(GNL_OBJS) $(EXTRA_OBJS)

ifneq (,$(filter asm,$(MAKECMDGOALS)))
	ASM = $(AFLAGS)
endif

HIDE	= \033[?25l				# Cache le curseur
SHOW	= \033[?25h				# Affiche
UPC		= \033[A
DWC		= \033[B
RTC		= \033[C
LTC		= \033[D
GTO		= \033[$(X);$(Y)H
UPNC	= \033[$(N)A			# Deplace N vers le haut
DWNC	= \033[$(N)B
RTNC	= \033[$(N)C
LTNC	= \033[$(N)D
CLS 	= \033[2J 				# clear screen
CLL		= \033[2K				# clear line

RST = \033[0m
BLD = \033[1m
DIM = \033[2m
ITA = \033[3m
UNL = \033[4m
INV = \033[7m
HID = \033[8m
STK = \033[9m

BK = \033[30m
RD = \033[31m
GR = \033[32m
YE = \033[33m
BL = \033[34m
MG = \033[35m
TL = \033[36m
WT = \033[37m

LBK = \033[90m # Gris clair
LRD = \033[91m # Rouge clair
LGR = \033[92m # Vert clair
LYE = \033[93m # Jaune clair
LBL = \033[94m # Bleu clair
LMG = \033[95m # Magenta clair
LTL = \033[96m # Cyan clair
LWT = \033[97m # Blanc brillant

FBK = \033[40m
FRD = \033[41m
FGR = \033[42m
FYE = \033[43m
FBL = \033[44m
FMG = \033[45m
FTL = \033[46m
FWT = \033[47m

# =============================== Compilation ================================

export OBJ_COUNT := $(words $(ALL_OBJS))
MAX := $(shell v=$$(expr $(shell stty size | awk '{print $$2}') - 12); [ $$v -gt 100 ] && echo 100 || echo $$v)
MIN := $(shell expr $(MAX) - 30)

all: .dispcat $(NAME)


#   _._     _,-'""`-._
#  (,-.`._,'(       |\`-/|
#      `-.-' \ )-`( , o o)    _
#            `-    \`_`"'-  (( )_ (
#                           <;___)_) 
#                             " "  

.dispcat:
	@export COUNT=0
	@clear
	@printf "\033[K\n\033[K\n\e[?25l"
	@echo "      _._     _,-'\"\"\`-._\033[K"
	@echo "     (,-.\`._,'(       |\\\`-/|\033[K"
	@echo "         \`-.-' \\ )-\`( , ~ ~)\033[K"
	@echo "               \`-    \\\`_\`\"'-\033[K"
	@printf "\n\n"

$(NAME): $(ALL_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(ALL_OBJS) > /dev/null 2>&1; \
	printf "\033[5;25Ho\033[5;27Ho\n\n\n\n"; \
	printf "\033[9;16H\033[32m[OK]\033[0m"; \
	echo -n "\e[?25h\n"; \
	echo "\n"; \

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(eval COUNT := $(shell expr $(COUNT) + 1))
	@COL=$$(expr $(MAX) - \( $(MIN) \* $(COUNT) / $(OBJ_COUNT) \)); \
	CNT=$$(expr $(COUNT)); \
	THRESH=$$(expr $(MAX) - 30); \
	CAP=5; \
	if [ "$$THRESH" -gt "$$CAP" ]; then \
		printf "\033[5;%sH   _\033[K\n" "$$COL"; \
		printf "\033[6;%sH (( )_ (\033[K\n" "$$COL"; \
		printf "\033[7;%sH <;___)_) \033[K\n" "$$COL"; \
		if [ $$(expr $$COL % 2) -eq 0 ]; then \
			printf "\033[8;%sH   \" \"  \033[K\n" "$$COL"; \
		else \
			printf "\033[8;%sH  \"   \"  \033[K\n" "$$COL"; \
		fi; \
		printf "\033[9;2Hlibft : %2d/%2d" "$$CNT" "$$OBJ_COUNT"; \
	fi
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


# =============================== Assemblage ================================



asm: $(ALL_ASMS)

$(ASM_DIR)/%.s: %.c
	@mkdir -p $(@D)
	@$(CC) $(AFLAGS) -I$(INC_DIR) -S $< -o $@



# =============================== Nettoyage ================================




clean:
	@rm -rf $(OBJ_DIR) $(ASM_DIR)
	@find . -name *.o -exec rm {} \;
	@find . -name *.s -exec rm {} \;
	@find . -name *.d -exec rm {} \;
	@find . -name .main -exec rm {} \;

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all $(NAME) re clean fclean asm
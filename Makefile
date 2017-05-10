##
## Makefile for Makefile in /home/pion_b/gfx/gfx_colle_fantasy/colle1
## 
## Made by Virgile Pion
## Login   <pion_b@epitech.net>
## 
## Started on  Wed Jan 13 18:49:06 2016 Virgile Pion
## Last update Wed Mar 15 17:34:53 2017 virgile
##


CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./include/
CFLAGS	+=	-W -Wall -Werror -lm -Ofast

LIB	=	-lc_graph_prog

SRC	=	src/main.c			\
		src/load_plan.c			\
		src/load_sphere.c		\
		src/load_cone.c			\
		src/load_cyl.c			\
		src/my_put_pixel.c		\
		src/draw_sphere.c		\
		src/draw_plan.c			\
		src/list_event.c		\
		src/draw_cone.c			\
		src/draw_cyl.c			\
		src/my_draw_line.c		\
		src/my_line.c			\
		src/framebuffer.c		\
		src/mainloop.c			\
		src/event.c			\
		src/calc_dir_vector.c		\
		src/intersect_sphere.c		\
		src/intersect_plane.c		\
		src/my_math2.c			\
		src/get_next_line.c		\
		src/my_load_map.c		\
		src/my_getnbr.c			\
		src/make_pos.c			\
		src/make_default_light.c	\
		src/my_maths.c			\
		src/my_load_pos.c		\
		src/is_on_light.c		\
		src/rotate.c			\
		src/my_strncmp.c		\
		src/my_parse_nb.c		\
		src/eq_solver.c			\
		src/move_obj.c			\
		src/translate.c			\
		src/sphere.c			\
		src/cone.c			\
		src/cylinder.c			\
		src/plane.c			\
		src/my_draw_objects.c		\
		src/light.c

OBJ	=	$(SRC:.c=.o)

NAME	=	raytracer1

all	:	prepare $(NAME) umbreon

prepare	:
		@echo "[\033[91m?\033[0m] \033[91mCompilation...\033[0m"

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME) $(CFLAGS)
		@echo "[\033[92mOK\033[0m] \033[92mCompilation !\033[0m"

clean	:
		$(RM) $(OBJ)
		@echo "[\033[92mOK\033[0m] \033[91mSuppression des .o\033[0m"

fclean	:	clean
		$(RM) $(NAME)
		@echo "[\033[92mOK\033[0m] \033[91mSuppression du binaire\033[0m"

re	:	fclean all

umbreon	:	
		@echo "\033[90m                                     &xu.                      .\033[0m"
		@echo "\033[90m             .                      !MQ|?95.                 .JTJ.\033[0m"
		@echo "\033[90m            .dM                       JMh.&g=d..            .MM:JF\033[0m"
		@echo "\033[90m            MM\"J                       JMF = .,=2           M\"M:JF\033[0\
m"
		@echo "\033[90m           N#\"g|dF                     .?b, JJf1,F        ..5 7u7!\033[0m\
"
		@echo "\033[90m           MNN&cv7r                       9gMMM#.?N       .b.. J\033[0m"
		@echo "\033[90m           MMM=dp,S,                        JMMNm?T.       M#\".J\033[0m"
		@echo "\033[90m          ^MMM'?                            .7#MM+dNjb..JM#4.M\033[0m"
		@echo "\033[90m           F ?   .Tg                          bMMMMM5.\`\.JMNKF\033[0m"
		@echo "\033[90m            ^. .&,5 M                        JMMMMMM&,7gYgJ7#5.\033[0m"
		@echo "\033[90m             MNMn.E.!d                      .MMM@\"\"WNb....J#.J"
		@echo "\033[90m              JMMNK!:d                     .JMMMF   .MMMMY7.  J\033[0m"
		@echo "\033[90m              .JMMNJ:d   .........     ...NMMMMMF    !MMT6J, /J?\033[0m"
		@echo "\033[90m               .YMMN.cGg&MMiJN.M.dh+JggdMMMMMMMMNm... MMiJs..\"\033[0m"
		@echo "\033[90m                 \`MMMar7MMMMNe7g\"QgMMMMMMMMMM\\dMMMMMMMMMM\'\`gF\033[0m"
		@echo "\033[90m                  .MMMMMMMMMMMMMMMMMMMMMMMMNJ7h.BYMMMMMMMP3\033[0m"
		@echo "\033[90m                  NMMMMMMMMMMMMMMMMMMMMMMNIlJ5Jx?dFJY\"H\033[0m"
		@echo "\033[90m                 .MMMMMMMMMMMMMMMMMMMMMMMMMMMg;?#?:d\033[0m"
		@echo "\033[90m                 N.MMMMMMMMMMMMMMMMMMMMMMMMMMM#B.M+d\033[0m"
		@echo "\033[90m               .JNs?MMMF. dMMMMMMMMMMMMMMMMMMMNmjmM\033[0m"
		@echo "\033[90m              .JMMF M\"i.M# ,TM#7MMaJ.gj?9TMMMMM#T.M\033[0m"
		@echo "\033[90m              JMMMF M .##B ..M@D     MMNM#.MM\"\"\"gM\"\033[0m"
		@echo "\033[90m             dMMM#T.Mj, 5 JJMF!     .MMMM#.M!u+J?b\033[0m"
		@echo "\033[90m            #MMMMt MMMNN##\"\"        MMMMMF.M JMF #\033[0m"
		@echo "\033[90m            NMMM   MMMMF$$          gMMMMT!  J!\`\`gb\033[0m"
		@echo "\033[90m            MMMd   MMMM$$         ..#4&M?    .dMMMM\033[0m"
		@echo "\033[90m            MMMM   MMMMF         Jb.F5       .4MMMWW,.\033[0m"
		@echo "\033[90m             M:dM. MMMM@I,          \`          @#?dL.F\033[0m"
		@echo "\033[90m                   ?4Mp.F'                      \"???\'\033[0m"
		@echo "\033[94m                             Done !                     \033[0m"

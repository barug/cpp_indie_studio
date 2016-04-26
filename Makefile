all:	library

library:
	make -C ./source/

library-re:
	make -C ./source/ re

clean:
	make -C ./source/ clean

fclean:
	make -C ./source/ fclean

re:	fclean library-re all

.PHONY:	clean fclean all re

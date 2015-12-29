all:
	gcc -Wall -c -o ME4.o ME4_02.c
	gcc -Wall -c -o MP1.o MP1.c
	gcc -Wall -o MP1.cgi ME4.o MP1.o -L/opt/lampp/lib -lmysqlclient
	gcc -Wall -c -o MAP2.o MAP2.c
	gcc -Wall -c -o rand.o rand.c
	gcc -Wall -c -o stats.o stats.c
	gcc -Wall -c -o battle.o battle.c
	gcc -Wall -o battle.cgi ME4.o battle.o rand.o stats.o -L/opt/lampp/lib -lmysqlclient
	gcc -Wall -o MAP2.cgi ME4.o MAP2.o -L/opt/lampp/lib -lmysqlclient
	sudo cp index.html /opt/lampp/htdocs/
	sudo cp MP1.cgi /opt/lampp/cgi-bin/
	sudo cp MAP2.cgi /opt/lampp/cgi-bin/
	sudo cp battle.cgi /opt/lampp/cgi-bin/
	# sudo cp battle_screen.html /opt/lampp/htdocs
	sudo cp style.css /opt/lampp/htdocs
	sudo cp MP1_map_screen_style.css /opt/lampp/htdocs
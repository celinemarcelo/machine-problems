all:
	gcc -Wall -c -o ME4.o ME4_02.c
	gcc -Wall -c -o MP1.o MP1.c
	gcc -Wall -o MP1.cgi ME4.o MP1.o -L/opt/lampp/lib -lmysqlclient
	gcc -Wall -c -o rand.o rand.c
	gcc -Wall -c -o MAP2.o MAP2.c
	gcc -Wall -c -o stats.o stats.c
	gcc -Wall -c -o battle.o battle.c
	gcc -Wall -o battle.cgi ME4.o battle.o rand.o stats.o -L/opt/lampp/lib -lmysqlclient
	gcc -Wall -o MAP2.cgi ME4.o MAP2.o rand.o -L/opt/lampp/lib -lmysqlclient
	sudo mkdir /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp index.html /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp MP1.cgi /opt/lampp/cgi-bin/
	sudo cp MAP2.cgi /opt/lampp/cgi-bin/
	sudo cp battle.cgi /opt/lampp/cgi-bin/
	sudo cp style.css /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp MP1_map_screen_style.css /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp icon.ico /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp gam134.cur /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp 101-dearly-beloved.mp3 /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp A-Walk-in-Andante.mp3 /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp mana.ttf /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp prstart.ttf /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp zig.ttf /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp -avr 2.1.4 /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp -avr mp1_images /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo cp -avr bootstrap-3.3.5-dist /opt/lampp/htdocs/MP1_Marcelo_Baquiran
	sudo chmod -R 777 /opt/lampp/htdocs/MP1_Marcelo_Baquiran
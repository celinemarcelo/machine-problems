all:
	gcc -Wall -c -o ME4.o ME4_02.c
	gcc -Wall -c -o MP1.o MP1.c
	gcc -Wall -o MP1.cgi ME4.o MP1.o `mysql_config --cflags --libs`
	gcc -Wall -c -o rand.o rand.c
	gcc -Wall -c -o MAP2.o MAP2.c
	gcc -Wall -c -o stats.o stats.c
	gcc -Wall -c -o battle.o battle.c
	gcc -Wall -o battle.cgi ME4.o battle.o rand.o stats.o `mysql_config --cflags --libs`
	gcc -Wall -o MAP2.cgi ME4.o MAP2.o rand.o `mysql_config --cflags --libs`

	sudo cp MP1.cgi /usr/lib/cgi-bin/
	sudo cp MAP2.cgi /usr/lib/cgi-bin/
	sudo cp battle.cgi /usr/lib/cgi-bin/

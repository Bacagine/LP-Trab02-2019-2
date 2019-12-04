# Makefile criado por Gustavo Bacagine <gustavobacagine@protonmail.com>
#
# Data de criação: 21/11/2019
# Data da última modificação: 02/12/2019 
#
# Lojinha_do_Berg é um aplicativo que controla as vendas da lojinha de \
  departamentos do Berg
# Git Hub: https://github.com/Bacagine/LP-Trab02-2019-2

lojinha_do_berg: main.o compras.o clientes.o menu.o clear_buffer.o developers.o
	gcc -o lojinha_do_berg main.o compras.o clientes.o menu.o clear_buffer.o developers.o
main.o: main.c compras.h clientes.h clear_buffer.h
	gcc -c main.c
compras.o: compras.c compras.h clear_buffer.h
	gcc -c compras.c
clientes.o: clientes.c clientes.h clear_buffer.h
	gcc -c clientes.c
menu.o: menu.c menu.h
	gcc -c menu.c
clear_buffer.o: clear_buffer.c clear_buffer.h
	gcc -c clear_buffer.c
developers.o: developers.c developers.h
	gcc -c developers.c
clean:
	rm -f *.o
realclean: clean
	rm -f lojinha_do_berg
	rm -f *.dat
# Para instalar a aplicação use o terminal \
  como super usuario ou como usuario root \
  e digite o comando make install
#install: \
	mkdir /opt/Lojinha_do_Berg \
	cp -r lojinha_do_berg icons /opt/Lojinha_do_Berg \
	cp lojinha_do_berg.desktop /usr/share/applications \
	chmod +x /usr/share/applications/lojinha_do_berg.desktop \
#	desktop-file-install /usr/share/applications/lojinha_do_berg.desktop
#uninstall: \
	rm -rf /opt/Lojinha_do_Berg \
	rm -rf /usr/share/applications/lojinha_do_berg.desktop \

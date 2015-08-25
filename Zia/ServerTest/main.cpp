#include <iostream>
#include "SocketTCP.h"
#include "AcceptorTcp.h"

int	main()
{
	ip::tcp::socket	client;
	ip::tcp::AcceptorTcp	acceptor(ip::tcp::endpoint(ip::Address::fromString("192.168.1.30"), 80));
	std::cout << "Serveur bind sur la socket 127.0.0.1 port 80" << std::endl;
	std::cout << "en attente d'un client ...";	
	acceptor.accept(client);
	std::cout << "OK !" << std::endl;
	std::cout << "Le client se connecte a partir de l'ip suivante : " << client.remote().address().toString() << std::endl;
	int	size = 500;
	std::cout << "debut de la discution avec un buffer de taille : " << size << std::endl;
	while (1)
	{
		std::string buffer("\0", size);
		int nb_read = client.recv(buffer);	
		std::cout << "nb_read = " << nb_read << std::endl;
		if (nb_read == 0 ||nb_read == -1)
			break;
		buffer.erase(nb_read);
		std::cout << buffer << std::endl;
	}
	std::cout << "Fin de la connection" << std::endl;
	client.close();
}
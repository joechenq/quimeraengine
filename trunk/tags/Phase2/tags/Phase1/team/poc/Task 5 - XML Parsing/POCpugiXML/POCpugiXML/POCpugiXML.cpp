#include "pugixml.hpp"

#include <iostream>
#include <stdio.h>

bool buscanombre(pugi::xml_node node);

int main()
{

    pugi::xml_document doc;

	// Se carga el documento
	pugi::xml_parse_result result = doc.load_file("players.xml");

	// Se comprueba que el documento se ha parseado bien
	std::cout << "Load result: " << result.description() << std::endl;

	// Se asigna a una variable el primer nodo del documento
	pugi::xml_node players = doc.first_child();
	
	// Se busca por predicado el nodo buscado: <PlayerList>
	// El predicado es la funci�n buscanombre, que est� definida y comentada al final del documento.
	// La funci�n find_node hace una b�squeda recursiva sobre el SUB�rbol que define el nodo al que se aplica.
	// es decir, se debe aplicar a un nodo que sea padre en alg�n grado del nodo buscado.
	std::cout << "Encontrado: " << players.find_node(buscanombre).name() << std::endl;
	
	// La parte que sigue aqu� son iteraciones para buscar <PlayerList> de forma manual
	// as� se ilustran las dos formas de buscar nodos. Esto es por tanto redundante
	std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;

	players = players.first_child();
	std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;

	while (strcmp(players.name(),"Team")) {
		players = players.next_sibling();
		std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;
	}
	
	players = players.first_child();
	std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;

	while (strcmp(players.name(),"PlayerList")) {
		players = players.next_sibling();
		std::cout << "Nodo: " << players.name() << " (" << players.type() << "): " << players.child_value() << std::endl;
	}

	// Una vez encontrado <PlayerList> de forma manual, iteramos para encontrar 
	// todos los jugadores y sus nombres
	players = players.first_child();
	
	while (players) {
		std::cout << "Jugador: " << players.first_child().next_sibling().child_value() << std::endl;
		players = players.next_sibling();
		
	}
		
	getchar();
	return 0;
}

// Esta es la funci�n que hace de predicado. Debe ser una funcion bool
// que compare la propiedad buscada (nombre, atributo, valor, etc) con un
// valor dado que es el buscado. La funci�n debe llevar como par�metro
// un xml_node. No he probado si se pueden poner m�s par�metros para hacer
// predicados gen�ricos
bool buscanombre(pugi::xml_node node)
{
    return (!strcmp(node.name(), "PlayerList"));
}
/*
 * ESTRUCTURA Y REPRESENTACION DE DATOS
 * PROYECTO 2
 *
 * INTEGRANTES
 * ACOSTA, RODOLFO
 * CASTILLO, ALBERTO
 * LI, JAVIER
 *
 */

#include <iostream>
 
class LinkedList
{
public:
	static const int MAX_NODES = 10; // Numero maximo de tareas
 
private:
	struct Node // Estructura del Nodo
	{
        std::string info;
		int siguiente;
	};
 
	Node m_nodes[MAX_NODES]; // Arreglo de los Nodos
	int m_siguienteLibre;
	int m_principio;
 
public:
	LinkedList() : m_siguienteLibre(0), m_principio(-1) { }
 
	bool addFirst(std::string x) // Agregar al inicio
	{
		if (m_siguienteLibre >= MAX_NODES){
            std::cout << "Lista llena" << std::endl;
			return false;
        }
 
		int i = m_siguienteLibre++;
		m_nodes[i].info = x;
		m_nodes[i].siguiente = m_principio;
		m_principio = i; 
		return true;
	}
 
	bool addLast(std::string x) // Agregar al final
	{
		if (m_siguienteLibre >= MAX_NODES){
            std::cout << "Lista llena" << std::endl;
			return false;
        }
 
		if (m_principio < 0) 
			return addFirst(x);
 
		int i = m_siguienteLibre++;
		m_nodes[i].info = x;
		m_nodes[i].siguiente = -1;
 
		int cola = m_principio;
 
		while (m_nodes[cola].siguiente >= 0)
			cola = m_nodes[cola].siguiente;
 
		m_nodes[cola].siguiente = i;
		return true;
	}

    void eliminar(std::string dato){ // Eliminar dato
        int ant = 0;
        int act = m_principio;
        bool salir = false;

        while((m_nodes[act].info != dato) && (salir == false)){
            if(m_nodes[act].siguiente >= 0){
                ant = act;
                act = m_nodes[act].siguiente;
            }else{
                salir = true;
            }
        }

        if(ant <= 0){
            m_principio = m_nodes[m_principio].siguiente;
        }else{
            if(salir == true){
                std::cout << "No existe el dato" << std::endl;
            }else{
                m_nodes[ant].siguiente = m_nodes[act].siguiente;
            }
        }

    }
 
	void print() // Imprimir lista
	{
		int count = 0;
 
		for (int i = m_principio; i >= 0; i = m_nodes[i].siguiente)
		{
			std::cout << "Tarea " << count
                    << " " 
					  << m_nodes[i].info << std::endl;
			count++;
		}
        std::cin.ignore();
	}
};
 
int main()
{
    int opc; 
    std::string valor;
	LinkedList list;

    std::cout << "LISTA DE TAREAS" << std::endl;
 
    do{
        std::cout << "SELECCIONE UNA OPCIÓN" << std::endl;
        std::cout << "1. Crear lista" << std::endl;
        std::cout << "2. Añadir tarea" << std::endl;
        std::cout << "3. Eliminar tarea" << std::endl;
        std::cout << "4. Imprimir lista" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cin >> opc;

        switch(opc){
            case 1:
                std::cout << "Inserte la primera tarea" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, valor);
                list.addFirst(valor);
                break;
            case 2:
                std::cout << "Escriba 'inicio' para insertar al inicio" << std::endl;
                std::cout << "Cualquier otro para insertar al final" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, valor);
                if(valor == "inicio"){
                    std::cout << "Escriba la tarea a añadir" << std::endl;
                std::getline(std::cin, valor);
                    list.addFirst(valor);
                }else{
                    std::cout << "Escriba la tarea a añadir" << std::endl;
                std::getline(std::cin, valor);
                    list.addLast(valor);
                }
                break;
            case 3:
                std::cout << "Escriba la tarea a eliminar" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, valor);
                list.eliminar(valor);
                break;
            case 4:
                list.print();
                break;
            case 0:
                std::cout << "Hasta luego!" << std::endl;
                break;
            default:
                std::cout << "Introduzca un valor dentro del rango" << std::endl;
        }
    }while(opc != 0);
 
	return 0;
}

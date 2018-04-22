/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"
#include <fstream>

Filmoteca::Filmoteca(string prop) {
	Pelicula aux = Pelicula();
	cent = new NodoF(aux, NULL);
	cab = new NodoF(aux, cent);
	propietario = prop;
}

Filmoteca::~Filmoteca() {
}

bool Filmoteca::estaVacia() {
	bool resul = false;
	//completar
	pNodo anterior, actual;
	anterior = cab;
	actual = anterior->sig;
	if (actual == cent)
		resul = true;
	return resul;
}

string Filmoteca::getPropietario() {
	return propietario;
}

void Filmoteca::setPropietario(string p) {
	propietario = p;
}
bool Filmoteca::insertarPelicula(Pelicula peli) {
	bool resul = false;
	//completar
	pNodo anterior, actual;
	anterior = cab;
	actual = anterior->sig;
	cent->info = peli;
	while (actual->info.getTitulo().compare(peli.getTitulo()) < 0) {
		anterior = anterior->sig;
		actual = anterior->sig;
	}
	if (((actual->info.getTitulo().compare(peli.getTitulo()) < 0) == 0)
			&& (actual == cent)) {
		pNodo nueva;
		nueva = new NodoF(peli, actual);
		anterior->sig = nueva;
		resul = true;
	} else if (actual->info.getTitulo().compare(peli.getTitulo()) > 0) {
		pNodo nueva;
		nueva = new NodoF(peli, actual);
		anterior->sig = nueva;
		resul = true;
	}
	return resul;
}
bool Filmoteca::eliminarPelicula(string titulo) {
	bool resul = false;
	//completar
	pNodo anterior, actual;
	anterior = cab;
	actual = anterior->sig;
	cent->info.setTitulo(titulo);
	while (actual->info.getTitulo().compare(titulo) != 0) {
		anterior = anterior->sig;
		actual = actual->sig;
	}
	if (actual != cent) {
		anterior->sig = actual->sig;
		delete (actual);
		resul = true;
	}
	return resul;
}
Pelicula Filmoteca::buscarPelicula(string t) {
	Pelicula resul;
	pNodo anterior, actual;
	anterior = cab;
	actual = anterior->sig;
	cent->info.setTitulo(t);
	while (actual->info.getTitulo().compare(t) != 0) {
		anterior = anterior->sig;
		actual = anterior->sig;
	}
	if (actual == cent)
		resul = Pelicula();
	else
		resul = actual->info;
	return resul;
}
void Filmoteca::mostrarFilmoteca() {
	pNodo anterior, actual;
	int contador = 1;
	anterior = cab;
	actual = anterior->sig;
	while (actual != cent) {
		cout << endl;
		cout << "PELICULA " << contador << ":\n" << actual->info.aCadena();
		contador++;
		anterior = anterior->sig;
		actual = anterior->sig;
	}
}
bool Filmoteca::guardarEnFichero(string f) {
	bool resul = false;
	//completar
	string nomFich = propietario + f + ".txt";
	ofstream fichero(nomFich.c_str());
	pNodo anterior, actual;
	anterior = cab;
	actual = anterior->sig;
	while (actual != cent) {
		fichero << actual->info.formatoFichero()<<endl;
		anterior = anterior->sig;
		actual = anterior->sig;
	}
	fichero.close();
	return resul;
}
void Filmoteca::recuperarDeFichero(string f) {
	ifstream fichero(f.c_str());
	string pelicula;
	Pelicula otra;
	while (getline(fichero, pelicula)) {
		otra = Pelicula(pelicula);
		insertarPelicula(otra);
	}
	fichero.close();
}


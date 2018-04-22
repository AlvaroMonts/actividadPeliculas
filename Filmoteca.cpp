/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"
#include <fstream>

Filmoteca::Filmoteca(string prop) {
	Pelicula aux;
	aux = Pelicula();
	cent = new NodoF(aux, NULL);
	cab = new NodoF(aux, cent);
	propietario = prop;
}

Filmoteca::~Filmoteca() {
}

bool Filmoteca::estaVacia() {
	bool resul = false;
	NodoF *ant, *act;
	ant = cab;
	act = ant->sig;
	if (act == cent)
		resul = true;
	return resul;
}

string Filmoteca::getPropietario() {
	return propietario;
}

void Filmoteca::setPropietario(string p) {
	propietario = p;
}
//
bool Filmoteca::insertarPelicula(Pelicula peli) {
	bool resul = false;
	NodoF *ant, *act;
	ant = cab;
	act = ant->sig;
	cent->info = peli;
	while (act->info.getTitulo().compare(peli.getTitulo()) < 0) {
		ant = ant->sig;
		act = ant->sig;
	}
	if (((act->info.getTitulo().compare(peli.getTitulo()) < 0) == 0)
			&& (act == cent)) {
		NodoF *nueva;
		nueva = new NodoF(peli, act);
		ant->sig = nueva;
		resul = true;
	} else if (act->info.getTitulo().compare(peli.getTitulo()) > 0) {
		NodoF *nueva;
		nueva = new NodoF(peli, act);
		ant->sig = nueva;
		resul = true;
	}
	return resul;
}
//
bool Filmoteca::eliminarPelicula(string titulo) {
	bool resul = false;
	NodoF *ant, *act;
	ant = cab;
	act = ant->sig;
	cent->info.setTitulo(titulo);
	while (act->info.getTitulo().compare(titulo) != 0) {
		ant = ant->sig;
		act = act->sig;
	}
	if (act != cent) {
		ant->sig = act->sig;
		delete (act);
		resul = true;
	}
	return resul;
}
//
Pelicula Filmoteca::buscarPelicula(string t) {
	Pelicula resul;
	NodoF *ant, *act;
	ant = cab;
	act = ant->sig;
	cent->info.setTitulo(t);
	while (act->info.getTitulo().compare(t) != 0) {
		ant = ant->sig;
		act = ant->sig;
	}
	if (act == cent)
		resul = Pelicula();
	else
		resul = act->info;
	return resul;
}
//
void Filmoteca::mostrarFilmoteca() {
	NodoF *ant, *act;
	int conta = 1;
	ant = cab;
	act = ant->sig;
	while (act != cent) {
		cout << endl;
		cout << "PELICULA " << conta << ":\n" << act->info.aCadena();
		conta++;
		ant = ant->sig;
		act = ant->sig;
	}
}
//
bool Filmoteca::guardarEnFichero(string f) {
	bool resul = false;
	string nomFich = propietario + f + ".txt";
	ofstream fichero(nomFich.c_str());
	NodoF *ant, *act;
	ant = cab;
	act = ant->sig;
	while (act != cent) {
		fichero << act->info.formatoFichero()<<endl;
		ant = ant->sig;
		act = ant->sig;
	}
	fichero.close();
	return resul;
}
//
void Filmoteca::recuperarDeFichero(string f) {
	ifstream fichero(f.c_str());
	string peli;
	Pelicula nueva;
	while (getline(fichero, peli)) {
		nueva = Pelicula(peli);
		insertarPelicula(nueva);
	}
	fichero.close();
}


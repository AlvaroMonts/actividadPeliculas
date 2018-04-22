/*
 * Pelicula.cpp
 */

#include "Pelicula.h"
#include <string>
#include <stdlib.h>

Pelicula::~Pelicula() {
	// TODO Auto-generated destructor stub
}

Pelicula::Pelicula() {
	//completar
	titulo = "";
	director = "";
	genero = "";
	fecha = 1900;
	numInters = 0;
	interpretes = NULL;
}

Pelicula::Pelicula(string t, string d, string gen, int f) {
	titulo = t;
	director = d;
	genero = gen;
	fecha = f;
	numInters = 0;
	interpretes = NULL;
}

Pelicula::Pelicula(string linea) {
	numInters = 0;
	interpretes = NULL;
	string delimiter = ";";
	size_t pos = 0;
	string token;
	string datos[4];
	int i = 0;
	while ((pos = linea.find(delimiter)) != string::npos && i < 4) {
		token = linea.substr(0, pos);
		datos[i] = token;
		i++;
		linea.erase(0, pos + delimiter.length());
	}
	int n = atoi(datos[3].c_str());
	titulo = datos[0];
	director = datos[1];
	genero = datos[2];
	fecha = n;
	// y ahora los interpretes
	if (linea != "")
		while ((pos = linea.find(delimiter)) != string::npos) {
			token = linea.substr(0, pos);
			insertarInterprete(token);
			linea.erase(0, pos + delimiter.length());
		}
}

string Pelicula::getDirector() {
	return this->director;
}

void Pelicula::setDirector(string d) {
	this->director = d;
}

string Pelicula::getGenero() {
	return genero;
}

void Pelicula::setGenero(string genero) {
	this->genero = genero;
}

string Pelicula::getTitulo() {
	return titulo;
}

void Pelicula::setTitulo(string titulo) {
	this->titulo = titulo;
}

void Pelicula::setFecha(int aaaa) {
	this->fecha = aaaa;
}

string Pelicula::aCadena() {
	stringstream convertirFecha, convertirInters;
	convertirFecha << fecha;
	string f = convertirFecha.str();
	convertirInters << numInters;
	string i = convertirInters.str();

	string aux = titulo + ". " + director + ". (" + genero + "). " + f
			+ ". \n \t" + " Interpretes (" + i + "): "
			+ this->getListaInterpretes();
	return aux;
}

string Pelicula::formatoFichero() {
	stringstream convertir;
	string fec;
	convertir << this->fecha;
	fec = convertir.str();
	string aux;
	aux = this->getTitulo() + ";" + this->getDirector() + ";"
			+ this->getGenero() + ";" + fec + ";";
	aux += getListaInterpretes();
	return aux;
}

bool Pelicula::tieneDatos() {
	bool resul = false;
	//completar
	if (getDirector() != "" || getTitulo() != "")
		resul = true;
	return resul;
}

string Pelicula::getListaInterpretes() {
	string aux = "";
	//completar
	pInter auxNod = interpretes;
	while (auxNod != NULL) {
		aux += auxNod->interprete + ";";
		auxNod = auxNod->sig;
	}
	return aux;
}

bool Pelicula::insertarInterprete(string actor) {
	bool resul = false;
	//completar

	/*
	 pInter auxTercero = new NodoInterprete("david", NULL);
	 pInter auxSegundo = new NodoInterprete("jorge", auxTercero);
	 pInter auxPrimero = new NodoInterprete("juan", auxSegundo);
	 interpretes = auxPrimero;
	 resul = true;
	 cout << "----LISTA INTERPRETES----\n"<< getListaInterpretes();
	 */

	pInter aux = interpretes;
	bool ultimo = false;
	if (aux != NULL) {
		while (aux != NULL) {
			if (aux->interprete == actor)
				// caso interprete ya esta en la lista
				break;
			if (aux->sig == NULL)
				ultimo = true;
			if (!ultimo)
				aux = aux->sig;
			else {
				resul = true;
				aux->sig = new NodoInterprete(actor, NULL);
				numInters++;
				break;
			}
		}
	} else {
		resul = true;
		interpretes = new NodoInterprete(actor, NULL);
		numInters++;
	}
	return resul;
}

bool Pelicula::eliminarInterprete(string actor) {
	bool resul = false;
	//completar
	pInter aux, auxdetras;
	auxdetras = interpretes;
	aux = interpretes;
	while (aux != NULL && !resul) {
		if (aux->interprete == actor) {
			if (aux == interpretes)
				interpretes = aux->sig;
			else
				auxdetras->sig = aux->sig;
			delete (aux);
			resul = true;
			numInters--;
		} else {
			auxdetras = aux;
			aux = aux->sig;
		}
	}
	return resul;
}

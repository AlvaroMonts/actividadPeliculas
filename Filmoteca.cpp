/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"

Filmoteca::Filmoteca(string prop) {
	propietario=prop;
	//	pNodo cab, cent;
}

Filmoteca::~Filmoteca() {
}

bool Filmoteca::estaVacia() {
	return false;
}

string Filmoteca::getPropietario() {
	return propietario;
}

void Filmoteca::setPropietario(string p) {
	propietario = p;
}

bool Filmoteca::insertarPelicula(Pelicula peli) {
	return false;
}

bool Filmoteca::eliminarPelicula(string titulo) {
	return false;
}

Pelicula Filmoteca::buscarPelicula(string t) {
	Pelicula p;
	return p;
}

void Filmoteca::mostrarFilmoteca() {
}

bool Filmoteca::guardarEnFichero(string f) {
	return false;
}

void Filmoteca::recuperarDeFichero(string f) {
}

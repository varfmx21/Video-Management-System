#include "Pelicula.h"

Pelicula::Pelicula(string id, string nombre, string genero, int duracion) : Video(id, nombre, genero, duracion) {}

void Pelicula::toString(ostream& os) {
    Video::toString(os);
}
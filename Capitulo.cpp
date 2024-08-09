#include "Capitulo.h"

Capitulo::Capitulo(string id, string nombre, string genero, int duracion, string serie, int episodio) : Video(id, nombre, genero, duracion), serie{serie}, episodio{episodio} {}

string Capitulo::getSerie() { return serie; }

int Capitulo::getEpisodio() { return episodio; }

void Capitulo::toString(ostream& os) {
    os << id << ", " << nombre << ", " << duracion << ", " << genero<<", "<<serie<<", "<<episodio;
    if (calificaciones.empty()) {
        os<<", SC";
    } else {
        os<<", "<<getCalificaciones();
    }
}
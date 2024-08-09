#include "Video.h"
#include <numeric>

Video::Video() : id{"n/a"}, nombre{"n/a"}, genero{"n/a"}, duracion{0} {}

Video::Video(string id, string name, string genre, int duration) : id{id}, nombre{name}, genero{genre}, duracion{duration} {}

string Video::getId() { return id; }

string Video::getNombre() { return nombre; }

string Video::getGenero() { return genero; }

void Video::calificar(int cal) {
    if(cal >= 1 && cal <=5) {
        this->calificaciones.push_back(cal);
    } else {
        cout<<"Ingresa un valor valor valido."<<'\n';
    }
}

double Video::getCalificaciones() {
    if (calificaciones.empty()) {
        return 0;
    }
    double sum = accumulate(calificaciones.begin(), calificaciones.end(), 0.0);
    double average = sum / calificaciones.size();
    return average;
}

void Video::toString(ostream& os) {
    os << id << ", " << nombre << ", " << duracion << ", " << genero;
    if (calificaciones.empty()) {
        os << ", SC";
    } else {
        os << ", " <<getCalificaciones();
    }
}

#include "Catalogo.h"
#include <fstream>
#include <sstream>

void Catalogo::videosInfo(string nombreArchivo) {
    ifstream archivo;
    string linea;

    archivo.open(nombreArchivo, ios::in);

    if (archivo.fail()) {
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string tipo,
               id,
               nombre,
               genero,
               serie;
        int duracion,
            episodio;
        char delim;

        
        getline(iss, tipo, ',');
        getline(iss, id, ',');
        getline(iss, nombre, ',');
        iss >> duracion;
        iss.ignore(1, ',');
        getline(iss, genero, ',');
        
        if (tipo == "p") {
            videos.push_back(new Pelicula(id, nombre, genero, duracion));
        } else if (tipo == "c") {
            getline(iss, serie, ',');
            iss>>episodio;
            videos.push_back(new Capitulo(id, nombre, genero, duracion, serie, episodio));
        }
    }
}

void Catalogo::mostrarCatalogo() {
    for (Video* video : videos) {
        cout<<*video<<'\n';
    }
}

void Catalogo::calificarVideo(string id, int cal) {
    bool x = true;
    for (Video* video : videos) {
        x = true;
        if (video->getId() == id) {
            video->calificar(cal);
            break;
        } else if (video->getId() != id){
            x = false;
        }
    }
    if (x == false) {
        cout<<"Ningun ID coincide."<<'\n';
    }
}

void Catalogo::mostrarVideosCalificacion(double cal, int tipo) {
    if (tipo < 1 || tipo > 3) {
    cout << "Opción no válida, intente de nuevo" << endl;
    }
    for (Video* video : videos) {
        double promedio = video->getCalificaciones();
        if (promedio >= cal) {
            if (promedio >= cal && (tipo == 3 || (tipo == 1 && dynamic_cast<const Pelicula*>(video)) || (tipo == 2 && dynamic_cast<const Capitulo*>(video)))) {
                cout<<'\n'<<video->getId()<<", "<<video->getNombre()<<", "<<video->getCalificaciones()<<'\n';
            }
        }
    }
}

void Catalogo::mostrarVideosGenero(string genero, int tipo) {
    if (tipo < 1 || tipo > 3) {
        cout << "Opción no válida, intente de nuevo" << endl;
    }
    for (Video* video : videos) {
        if (video->getGenero() == genero) {
            if (tipo == 3 || (tipo == 1 && dynamic_cast<const Pelicula*>(video)) || (tipo == 2 && dynamic_cast<const Capitulo*>(video))) {
                cout<<'\n'<<video->getId()<<", "<<video->getNombre()<<", "<<video->getGenero()<<", "<<video->getCalificaciones()<<'\n';
            }
        }
    }
}
#pragma once

#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"
#include <vector>

class Catalogo {
    
    private:
        // Atributos
        vector<Video*> videos; 
    
    public:
        // Métodos
        void videosInfo(string nombreArchivo);
        void mostrarCatalogo();
        void calificarVideo(string id, int cal);
        void mostrarVideosCalificacion(double cal, int tipo);
        void mostrarVideosGenero(string genero, int tipo);

};
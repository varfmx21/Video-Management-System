#pragma once

#include "Video.h"

class Pelicula:public Video {
    using Video::Video;
    
    public:
        // Métodos
        Pelicula(string id, string nombre, string genero, int duracion);
        void toString(ostream& os) override;

};
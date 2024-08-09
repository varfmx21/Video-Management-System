#pragma once

#include "Video.h"

class Capitulo:public Video {

    private:
        // Atributos
        string serie;
        int episodio;

    public:
        // Métodos
        Capitulo(string id, string nombre, string genero, int duracion, string serie, int episodio);
        string getSerie();
        int getEpisodio();
        void toString(ostream& os) override;

};

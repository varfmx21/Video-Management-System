#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;    

class Video {

    protected:
        // Atributos
        string id;
        string nombre;
        string genero;
        int duracion;
        vector<int> calificaciones;
    
    public:
        // Constructores
        Video();
        Video(string id, string nombre, string genero, int duracion);

        // Métodos
        string getId();
        string getNombre();
        string getGenero();
        void calificar(int cal);
        double getCalificaciones();
        virtual void toString(ostream& os);
        
        // Sobrecarga del operador << para desplegar información de los videos
        friend ostream& operator<<(ostream& os, Video& video1) {
            video1.toString(os);
            return os;
        };

};
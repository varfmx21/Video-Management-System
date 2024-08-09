#include "Catalogo.h"
#include <iomanip>

int main() {

    Catalogo catalogo;
    catalogo.videosInfo("videos.txt"); // Agregue aquí el nombre del archivo

    int opcion;
    do {
        cout<<'\n';
        cout<<"------Bienvenido a METFLIX------"<<'\n';
        cout<<"1. Mostrar todo el catalogo con calificaciones."<<'\n';
        cout<<"2. Calificar un video."<<'\n';
        cout<<"3. Mostrar pelculas o capitulos con una calificacion minima determinada."<<'\n';
        cout<<"4. Mostrar peliculas o capitulos de un cierto genero."<<'\n';
        cout<<"9. Salir del programa."<<'\n';
        cout<< "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout<<'\n';
                catalogo.mostrarCatalogo();
                break;
            case 2: {
                cout<<'\n';
                string id;
                int calificacion;
                cout<<"ID del video a calificar: ";
                cin>>id;
                cout<<"Calificacion: ";
                cin>>calificacion;
                catalogo.calificarVideo(id, calificacion);
                break;
            }
            case 3: {
                cout<<'\n';
                int tipo;
                double calificacion;
                do {
                    cout<<"1. Pelicula"<<'\n';
                    cout<<"2. Capitulo"<<'\n';
                    cout<<"3. Ambos"<<'\n';
                    cout<<"Selecciona una opcion: "<<'\n';
                    cin>>tipo;
                } while (tipo < 1 || tipo > 3);
                cout<<"Calificacion minima: ";
                cin>>calificacion;
                catalogo.mostrarVideosCalificacion(calificacion, tipo);
                break;
            }
            case 4: {
                cout<<'\n';
                int tipo;
                string genero;
                do {
                    cout<<"1. Pelicula"<<'\n';
                    cout<<"2. Capitulo"<<'\n';
                    cout<<"3. Ambos"<<'\n';
                    cout<<"Selecciona una opcion: "<<'\n';
                    cin>>tipo;
                } while (tipo < 1 || tipo > 3);
                cout<<"Genero a mostrar: ";
                cin>>genero;
                catalogo.mostrarVideosGenero(genero, tipo);
                break;
            }
            default: {
                cout<<"Opcion invalida. Intenta denuevo.";
                return 0;
            }
        }
    } while (opcion != 9);

    return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
    /*
        Agrega propiedades para guardar la vida(número entero), ataque(número entero) y nombre del jugador.
        Agrega una propiedad para guardar el jugador que lo atacó por última vez.
    */
public:
    Jugador *ptrJugador;
   int vida;
   int ataque;
   string nombre;
   string atacadoPor;
   
    
    Jugador(); 
    Jugador(int vida, int ataque, string nombre /* agrega parámetros para asignar hp, ataque y nombre */); 
    
    void atacar(Jugador *j/* agregar parámetros para atacar a otro jugador*/); 
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios
    
    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque. 
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina. 
        No importa quien ataca primero.
    */
   Jugador j1, j2;
   j1.vida = 100;
   j1.ataque = 10;
   j1.nombre = "Papu";
   j2.vida = 150;
   j2.ataque = 10;
   j2.nombre = "Tilin";

   Jugador *ptrj1 = &j1;
   Jugador *ptrj2 = &j2;

   j1.atacar(&j2);

    return 0;
}

Jugador::Jugador(){
    /*
        Asignar 100 a hp y 5 a attack como valores default.
        Asignar 'No definido' al nombre como default.
    */
   vida = 100;
   ataque = 5;
   nombre = "No definido";
}

Jugador::Jugador(int vida, int ataque, string nombre/* Agrega parámetros para asignar hp, ataque y nombre*/){
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
   if (vida>0 && vida<201)
    {
         this->vida = vida; 
    }
   if (ataque>0 && ataque<21)
    {
        this->ataque = ataque;
    }
    this-> nombre = nombre;

}

void Jugador::atacar(Jugador *j/* Agregar parámetros para atacar a otro Jugador */){
    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */

   this-> ptrJugador = j;

   j.ataque = ataque;
   int x = rand () % 100;
   if (x>19)
   {
    vida = vida;
       cout<<j.nombre<< "ataco a "<<nombre<< " pero fallo, vida restante de "<<nombre<< " = "<<vida;

   }
   else 
   {
    vida = vida-ataque;
    cout<<nombre<< "ataco a "<<j.nombre<< " e hizo "<<ataque<<" de danio, vida restante de "<<j.nombre<< " = "<<j.vida;

   }


    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}
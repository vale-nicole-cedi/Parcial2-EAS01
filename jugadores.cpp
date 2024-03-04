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
   int vida, attack;
   string nombre;
   Jugador* atacadoPor;
    
    Jugador(); 
    Jugador(int vida, int attack, string nombre); 
    
    void atacar(Jugador &j2); 
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

   Jugador j1(100,10,"Mario");
   Jugador j2(100,10,"Carlos");

   while(j1.vida > 0 && j2.vida > 0){
    j1.atacar(j2);
    if(j2.vida <= 0){
        cout << j1.nombre << " es el ganador" << endl;
        break;
    }

    j2.atacar(j1);
    if(j1.vida <= 0){
        cout << j2.nombre << " es el ganador" << endl;
        break;
    }
   }

    return 0;
}

Jugador::Jugador(){
    /*
        Asignar 100 a hp y 5 a attack como valores default.
        Asignar 'No definido' al nombre como default.
    */
   this->vida = 100;
   this->attack = 5;
   this->nombre = "No definido";
}

Jugador::Jugador(int vida, int attack, string nombre){
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
   this->vida = vida;
   this->attack = attack;
   this->nombre = nombre;
}

void Jugador::atacar(Jugador &j2){
    int ran = rand() % 5;
    if(ran == 0){
        cout << this->nombre << " ataco a " << j2.nombre << " pero fallo, vida restante de " << j2.nombre <<  " = " << j2.vida << endl; 
    }else{
        j2.vida -= this-> attack;
        cout << this->nombre << " ataco a " << j2.nombre << " e hizo " << this->attack << " de danio, vida restante de " << j2.nombre <<  " = " << j2.vida << endl; 
    }

    j2.atacadoPor = this;
    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}
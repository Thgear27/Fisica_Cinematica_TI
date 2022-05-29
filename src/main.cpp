#include "Simulation.hpp"

int main() {
    // Crea un objeto de tipo Simulation
    Simulation simulation {};

    // Bucle infinito hasta que se detecte que la ventana se ha cerrrado
    while (!simulation.GetWindow()->IsDone()) {
        simulation.HandleInput(); // Maneja de entrada
        simulation.Update();      // Realiza una actualizacion de lo que esta pasando
        simulation.Render();      // Dibuja en la ventana

        // Reinicia el reloj que guarda en tiempo entre cada iteracion
        simulation.RestartClock();
    }
    return 0;
}
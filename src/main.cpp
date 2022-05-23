#include "Simulation.hpp"

int main()
{
    Simulation simulation{};
    while (!simulation.GetWindow()->IsDone())
    {
        simulation.HandleInput();
        simulation.Update();
        simulation.Render();
        simulation.RestartClock();
    }
    return 0;
}
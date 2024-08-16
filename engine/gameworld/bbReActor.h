/**
 * @brief ReActor controls everything that happens in the game world
 * (inherits bbDeque)
 * 1. get input to game world from UI and feed into reactor
 * 2. React()
 * 2.1 global actor adds call to update each Actor from within ReActor
 * 2.1.1 each actor adds calls to update interactables in gameworld
 * 2.1.1.1 update interactables
 */
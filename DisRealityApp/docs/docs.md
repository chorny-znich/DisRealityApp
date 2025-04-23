# Work with the DisRealityGF
- Add a class that derived dr::Engine class from DisRealityGF which contain the game cycle.
```
#include <DisRealityGF.h>
class GameEngine : public dr::Engine
{
};
```
- Run a derived run() method to start a game cycle.
```
GameEngine gameEngine;
gameEngine.run();
```
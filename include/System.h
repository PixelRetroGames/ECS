#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "Component_mask.h"
#include "Entity.h"

namespace ECS
{
    class Engine;

    class System
    {
     protected:
     std::vector<Entity> entities;
     Component_mask mask;
     Engine *engine;

     public:
     System()=default;
     virtual ~System()=default;

     ///Called before starting the app, but after the engine initialized
     virtual void Init(){}

     ///Called every update
     virtual void Update(int dt){}

     ///Called every frame
     virtual void Render(){}

     ///Non-overloadable
     void Register_entity(Entity entity);
     void Unregister_entity(Entity entity);
     void Register_engine(Engine *_engine);
     Component_mask Get_mask();
    };
}

#endif // ECS_SYSTEM_H

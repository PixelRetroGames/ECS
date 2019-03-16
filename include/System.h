#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "Component_mask.h"
#include "Entity.h"

namespace ECS
{
    class System
    {
     private:
     std::vector<Entity> entities;
     Component_mask mask;

     public:
     System()=default;
     virtual ~System()=default;

     ///Called before starting the app, but after the engine initialized
     virtual void Init()=0;

     ///Called every update
     virtual void Update(int dt)=0;

     ///Called every frame
     virtual void Render();

     ///Non-overloadable
     void Register_entity(Entity entity);
     void Unregister_entity(Entity entity);
     Component_mask Get_mask();
    };
}

#endif // ECS_SYSTEM_H

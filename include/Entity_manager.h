#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H

#include "Entity.h"

namespace ECS
{
    class Entity_manager
    {
     private:
     int last_entity_id=0;

     public:
     Entity Add_entity();
     void Remove_entity(Entity entity);
    };
}

#endif // ECS_ENTITY_MANAGER_H

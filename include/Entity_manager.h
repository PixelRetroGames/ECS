#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H

#include "Entity.h"

namespace ECS
{
    class Entity_manager
    {
     public:
     int last_entity_id;

     public:
     Entity Add_entity();
     void Remove_entity();
    };
}

#endif // ECS_ENTITY_MANAGER_H

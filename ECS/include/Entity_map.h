#ifndef ECS_ENTITY_MAP_H
#define ECS_ENTITY_MAP_H

#include "Entity.h"
#include <map>

namespace ECS
{
    using Component_id=unsigned int;

    class Entity_map
    {
     public:
     std::map<Entity,Component_id> entity_to_component;
     std::map<Component_id,Entity> component_to_entity;

     public:
     Entity Get_entity(Component_id component_id);
     Component_id Get_component(Entity entity);

     void Add(Entity entity,Component_id component_id);
     void Remove(Entity entity);
    };
}


#endif // ECS_ENTITY_MAP_H

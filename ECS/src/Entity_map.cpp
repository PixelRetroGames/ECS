#include "../include/Entity_map.h"

namespace ECS
{
    Entity Entity_map::Get_entity(Component_id component_id)
    {
     return component_to_entity[component_id];
    }

    Component_id Entity_map::Get_component(Entity entity)
    {
     return entity_to_component[entity];
    }

    void Entity_map::Add(Entity entity,Component_id component_id)
    {
     entity_to_component[entity]=component_id;
     component_to_entity[component_id]=entity;
    }

    void Entity_map::Remove(Entity entity)
    {
     if(entity_to_component.count(entity)==0)
        return;

     component_to_entity.erase(entity_to_component[entity]);
     entity_to_component.erase(entity);
    }
}

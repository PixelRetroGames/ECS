#include "../include/Entity_manager.h"

namespace ECS
{
    Entity Entity_manager::Add_entity()
    {
     last_entity_id++;
     return Entity(last_entity_id);
    }

    void Entity_manager::Remove_entity(Entity entity)
    {
     entity.id=0;
    }
}

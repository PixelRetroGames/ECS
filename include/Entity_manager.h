#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H

#include "Entity.h"
#include <set>

namespace ECS
{
    class Entity_manager
    {
     private:
     int last_entity_id=0;
     std::set<int> free_ids;
     int number_of_chunks;
     static const int CHUNK_SIZE=1024;

     public:
     Entity_manager();
     ~Entity_manager();
     Entity Add_entity();
     void Remove_entity(Entity entity);

     private:
     void Create_free_ids();
    };
}

#endif // ECS_ENTITY_MANAGER_H

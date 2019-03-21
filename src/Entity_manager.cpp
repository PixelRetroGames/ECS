#include "../include/Entity_manager.h"

namespace ECS
{
    Entity_manager::Entity_manager()
    {
     number_of_chunks=0;
     Create_free_ids();
    }

    Entity_manager::~Entity_manager()
    {
     free_ids.clear();
    }

    Entity Entity_manager::Add_entity()
    {
     if(free_ids.empty())
        Create_free_ids();

     int id=*free_ids.begin();
     free_ids.erase(free_ids.begin());

     return Entity(id);
    }

    void Entity_manager::Remove_entity(Entity entity)
    {
     free_ids.insert(entity.id);
     entity.id=-1;
    }

    void Entity_manager::Create_free_ids()
    {
     for(int i=number_of_chunks*CHUNK_SIZE;i<(number_of_chunks+1)*CHUNK_SIZE;i++)
         free_ids.insert(i);
     number_of_chunks++;
    }
}

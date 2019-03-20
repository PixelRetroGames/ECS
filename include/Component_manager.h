#ifndef ECS_COMPONENT_MANAGER_H
#define ECS_COMPONENT_MANAGER_H

#include "Entity.h"
#include "Entity_map.h"
#include <vector>

namespace ECS
{
    class Base_component_manager
    {
    };

    template <typename Component_type>
    class Component_manager : public Base_component_manager
    {
     private:
     int number_of_chunks;
     static const int CHUNK_SIZE=1024;
     std::vector<Component_type> components;
     Entity_map entity_map;

     public:
     Component_manager()
     {
      components.reserve(CHUNK_SIZE);
      number_of_chunks=1;
     }

     void Add_component(Entity entity,Component_type &component)
     {
      if(components.size()==components.capacity())
         components.reserve((++number_of_chunks)*CHUNK_SIZE);

      Component_id new_id=components.size();
      components.push_back(component);

      entity_map.Add(entity,new_id);
     }

     void Remove_component(Entity entity)
     {
      if(components.empty())
         return;

      Component_id id=entity_map.Get_component(entity),last_id=components.size()-1;
      Entity last_entity=entity_map.Get_entity(last_id);

      std::swap(components[id],components.back());
      components.pop_back();

      if(components.size()<number_of_chunks*CHUNK_SIZE)
         components.resize((--number_of_chunks)*CHUNK_SIZE);

      entity_map.Remove(entity);
      entity_map.Add(last_entity,id);
     }

     Component_type *Find(Entity entity)
     {
      Component_id id=entity_map.Get_component(entity);
      return &components[id];
     }
    };
}

#endif // ECSCOMPONENT_MANAGER_H

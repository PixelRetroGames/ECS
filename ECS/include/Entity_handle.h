#ifndef ECS_ENTITY_HANDLE_H
#define ECS_ENTITY_HANDLE_H

#include "Component_handle.h"
#include "Entity.h"
#include "Engine.h"

namespace ECS
{
    class Entity_handle
    {
     private:
     Entity entity;
     Engine *engine;

     public:
     Entity_handle(Entity _entity,Engine *_engine) : entity(_entity),engine(_engine) {};
     Entity_handle() {}

     void Clear()
     {
      engine->Remove_entity(entity);
     }

     template <typename Component_type>
     void Add_component(Component_type &&component)
     {
      engine->Add_component<Component_type>(entity,std::forward<Component_type>(component));
     }

     template <typename Component_type>
     void Remove_component()
     {
      engine->Remove_component<Component_type>(entity);
     }

     template <typename Component_type>
     Component_handle<Component_type> *Get_component()
     {
      Component_handle<Component_type> handle;
      engine->Translate(entity,handle);
      return handle;
     }

    };
}

#endif // ECS_ENTITY_HANDLE_H

#ifndef ECS_COMPONENT_HANDLE_H
#define ECS_COMPONENT_HANDLE_H

#include "Component_manager.h"
#include "Entity.h"

namespace ECS
{
    template <typename Component_type>
    class Component_handle
    {
     public:
     Entity owner;
     Component_type *component;
     Component_manager<Component_type> *manager;

     public:
     Component_handle(){}

     Component_handle(Entity _owner,Component_type *_component,Component_manager<Component_type> *_manager):
         owner(_owner),component(_component),manager(_manager) {};

     Component_type *operator->() const
     {
      return component;
     }

     void Clear()
     {
      manager->Remove_component(owner);
     }
    };
}

#endif // ECS_COMPONENT_HANDLE_H

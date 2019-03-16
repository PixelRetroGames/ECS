#ifndef ECS_ENGINE_H
#define ECS_ENGINE_H

#include "Entity.h"
#include "Entity_map.h"
#include <memory>

namespace ECS
{
    class Engine
    {
     private:
     std::vector<std::unique_ptr<Base_component_manager>> component_managers;
     std::vector<std::unique_ptr<System>> systems;
     std::unique_ptr<Entity_manager> entity_manager;
     std::map<Entity,Component_mask> entity_masks;

     public:
     template <typename Component_type>
     Component_manager<Component_type> *Get_component_manager()
     {
      int type_id=Get_component_type_id<Component_type>();
      component_managers.push_back(std::make_unique<Component_manager<Component_type>>());
      return static_cast<Component_manager<Component_type>*>(component_managers.back().get());
     }


     template <typename Component_type>
     void Add_component_manager(std::unique_ptr<Component_manager<Component_type>> manager)
     {
      int type_id=Get_component_type_id<Component_type>();
      component_managers.push_back(manager);
     }

     template <typename Component_type>
     void Add_component(Entity &entity,Component_type &&component)
     {
      Component_manager<Component_type> *manager=Get_component_manager<Component_type>();
      manager->Add_component(entity,component);

      Component_mask old_mask=entity_masks[entity];
      entity_masks[entity].Add_component<Component_type>();

      Update_entity_mask(entity,old_mask);
     }

     template <typename Component_type>
     void Remove_component(Entity const &entity)
     {

     }
    };
}

#endif // ECS_ENGINE_H

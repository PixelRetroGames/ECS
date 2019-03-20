#include "../include/Engine.h"
#include "../include/Entity_handle.h"

namespace ECS
{
    void Engine::Init()
    {
     for(int i=0;i<systems.size();i++)
         systems[i]->Init();
    }

    void Engine::Update(int dt)
    {
      for(int i=0;i<systems.size();i++)
         systems[i]->Update(dt);
    }

    void Engine::Render()
    {
     for(int i=0;i<systems.size();i++)
         systems[i]->Render();
    }

    Entity_handle Engine::Add_entity()
    {
     Entity_handle handle(entity_manager->Add_entity(),this);
    }

    void Engine::Remove_entity(Entity entity)
    {
     for(int i=0;i<systems.size();i++)
         systems[i]->Unregister_entity(entity);

     entity_manager->Remove_entity(entity);
    }

    void Engine::Update_entity_mask(Entity const &entity,Component_mask old_mask)
    {
     Component_mask new_mask=entity_masks[entity];

     for(int i=0;i<systems.size();i++)
         {
          Component_mask system_mask=systems[i]->Get_mask();
          if(new_mask.Is_new_match(old_mask,system_mask))
             {
              systems[i]->Register_entity(entity);
             }
          else
             {
              systems[i]->Unregister_entity(entity);
             }
         }
    }
}

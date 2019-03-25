#include "../include/System.h"
#include <algorithm>

namespace ECS
{
    void System::Register_entity(Entity entity)
    {
     entities.push_back(entity);
    }

    void System::Unregister_entity(Entity entity)
    {
     std::vector<Entity>::iterator it=std::find(entities.begin(),entities.end(),entity);
     entities.erase(it);
    }

    void System::Register_engine(Engine *_engine)
    {
     engine=_engine;
    }

    Component_mask System::Get_mask()
    {
     return mask;
    }
}

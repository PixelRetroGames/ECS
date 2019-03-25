#ifndef ECS_COMPONENT_MASK_H
#define ECS_COMPONENT_MASK_H

#include "Component.h"

namespace ECS
{
    class Component_mask
    {
     private:
     int mask=0;

     public:

     template <typename Component_type>
     void Add_component()
     {
      mask|=(1<<Get_component_type_id<Component_type>());
     }

     template <typename Component_type>
     void Remove_component()
     {
      mask&=~(1<<Get_component_type_id<Component_type>());
     }

     bool Is_matching(Component_mask system_mask);
     bool Is_new_match(Component_mask old_mask,Component_mask system_mask);
     bool Is_no_longer_matching(Component_mask old_mask,Component_mask system_mask);
    };
}

#endif // ECS_COMPONENT_MASK_H

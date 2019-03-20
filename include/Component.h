#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include <vector>
#include "Component_manager.h"
#include "Entity.h"

namespace ECS
{
    class Component_type_counter
    {
     public:
     static int type_counter;
    };

    template <typename Component_type>
    class Component
    {
     public:
     static inline int Get_type_id()
     {
      static int type_id=Component_type_counter::type_counter++;
      return type_id;
     }
    };

    template <typename Component_type>
    static int Get_component_type_id()
    {
     return Component_type::Get_type_id();
    }

    class Transform: public Component<Transform>
    {
     public:
     int x,y;
    };

    class Image: public Component<Image>
    {
     public:
     int image_id;
    };
}

#endif // ECS_COMPONENT_H

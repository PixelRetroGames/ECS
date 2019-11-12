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
     private:
     static int type_id;

     public:
     Component()
     {
      if(type_id==-1)
         Create_type_id();
     }

     static void Create_type_id()
     {
      static int _type_id=Component_type_counter::type_counter++;
      if(type_id==-1)
         {
          type_id=_type_id;
         }
     }

     static inline int Get_type_id()
     {
      if(type_id==-1)
         Create_type_id();
      return type_id;
     }
    };

    template<typename Component_type>
    int Component<Component_type>::type_id=-1;

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

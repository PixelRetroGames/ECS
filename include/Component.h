#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>

namespace ECS
{
    class Component
    {

    };

    class Transform: public Component
    {
     public:
     int x,y;
    };
}

#endif // COMPONENT_H

#ifndef ENTITY_H
#define ENTITY_H

namespace ECS
{
    struct Entity
    {
     public:
     int id;

     Entity(int _id=0): id(_id) {};

     friend bool operator < (const Entity &a, const Entity &b)
     {
      return a.id<b.id;
     }
    };
}

#endif // ENTITY_H

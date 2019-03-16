#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

namespace ECS
{
    struct Entity
    {
     public:
     int id;

     Entity(int _id=0): id(_id) {};

     bool operator < (const Entity &other) const
     {
      return id<other.id;
     }
     bool operator == (const Entity &other) const
     {
      return id==other.id;
     }
    };
}

#endif // ECS_ENTITY_H

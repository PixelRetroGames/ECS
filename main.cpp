#include "ECS/ECS.h"

#include <cstdio>

class Testable : public ECS::Component<Testable>
{
 public:
 int sq;

 public:
 Testable(int _sq) : sq(_sq) {};
};

class Imagine : public ECS::Component<Testable>
{
 public:
 int id;

 public:
 Imagine(int _id) : id(_id) {};
};

class Testttt : public ECS::Component<Testttt>
{
 public:
 int x,y;

 public:
 Testttt(int _x,int _y) : x(_x),y(_y) {};
};

class Test : public ECS::System
{
 public:
 Test()
 {
  mask.Add_component<Testable>();
  mask.Add_component<Testttt>();
 }

 void Update(int dt)
 {
  for(auto &entity:entities)
      {
       ECS::Component_handle<Testable> sq;
       engine->Translate(entity,sq);
       sq->sq+=dt;

       printf("id=%d,sq=%d\n",entity.id,sq->sq);
      }
 }
};

int main()
{
 auto entity_manager=make_unique<ECS::Entity_manager>();
 auto engine=make_unique<ECS::Engine>(std::move(entity_manager));

 std::unique_ptr<ECS::System> test=make_unique<Test>();
 engine->Add_system(std::move(test));
 printf("Working!\n");

 ECS::Entity_handle sqq=engine->Add_entity(),skr=engine->Add_entity();
 sqq.Add_component(Testable(45));
 sqq.Add_component(Testttt(4,5));
 skr.Add_component(Testable(69));
 skr.Add_component(Testttt(4,8));
 skr.Add_component(Imagine(69));

 for(int i=0;i<7;i++)
     engine->Update(i);

 return 0;
}

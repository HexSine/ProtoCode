#ifndef MENUITEM_H
#define MENUITEM_H

#include "ProtoEngine/ProtoEngine.h"

class MenuItem : public Entity
{
    public:
        MenuItem();
        virtual ~MenuItem();

        virtual void Init();
        virtual void Update(const double deltaTime);
        virtual void Terminate();

    protected:
    private:
};

#endif // MENUITEM_H

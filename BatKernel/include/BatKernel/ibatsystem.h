#ifndef IBATSYSTEM_H
#define IBATSYSTEM_H

#include "BatKernel/ibatcomponent.h"
class IBatGraphicsSystem
{
    public:
        IBatGraphicsSystem();
        virtual ~IBatGraphicsSystem();

        virtual bool Initialize(ResourceManager* resSystem) = 0;
        virtual void DrawRenderObject(const IBatComponent& target,glm::mat4 matrix) = 0;
    protected:
    private:
};

#endif // IBATSYSTEM_H

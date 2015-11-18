#ifndef IGRAPHICSSYSTEM_H
#define IGRAPHICSSYSTEM_H


#include "BatKernel/ibatcomponent.h"
class IBatGraphicsSystem
{
    public:
        IBatGraphicsSystem();
        virtual ~IBatGraphicsSystem();

        virtual bool Initialize() = 0;
        virtual void DrawRenderObject(const IBatComponent& target,glm::mat4 matrix) = 0;
    protected:
    private:
};

#endif // IGRAPHICSSYSTEM_H

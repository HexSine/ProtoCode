#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H


// File: graphicssystem.h
// Description: The main Graphics system, handles rendering crap, and general initialization/destruction of the graphics system
// Copywrite: Nathan Boyes - 07/03/2015

#include "renderobject.h"
#include "ProtoGraphicsLib/shader.h"
#include "ProtoGraphicsLib/mesh.h"
#include "BatKernel/batcore.h"
class GraphicsSystem : public IBatGraphicsSystem
{
    public:
        GraphicsSystem();
        virtual ~GraphicsSystem();

        virtual void DrawRenderObject(const IBatComponent& target,glm::mat4 matrix);
        virtual bool Initialize();
        //virtual void DrawRenderObject(const RenderObject& target,glm::mat4 matrix);

    protected:
    private:
};

#endif // GRAPHICSSYSTEM_H

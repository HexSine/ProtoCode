#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

// File: graphicssystem.h
// Description: The main Graphics system, handles rendering crap, and general initialization/destruction of the

class GraphicsSystem
{
    public:
        GraphicsSystem();
        virtual ~GraphicsSystem();

        void Initialize();
    protected:
        u32 VertexArrayID;
    private:
};

#endif // GRAPHICSSYSTEM_H

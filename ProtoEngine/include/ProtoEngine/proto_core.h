#ifndef PROTO_CORE_H_INCLUDED
#define PROTO_CORE_H_INCLUDED

class IGraphicsSystem;
class ProtoEngine
{
public:
    void Render();
protected:
    IGraphicsSystem* graphicsSystem;
};

#endif // PROTO_CORE_H_INCLUDED

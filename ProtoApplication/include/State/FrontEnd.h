#ifndef INCLUDED_FRONT_END
#define INCLUDED_FRONT_END

#include "BaseState.h"

#include "ProtoEngine/ProtoEngine.h"
#include "Entities/FrontEnd/menuitem.h"
#include "Entities/Map/background.h"
class FrontEnd : public BaseState
{
public:
	FrontEnd(GameContext& gc);
	virtual ~FrontEnd();

	virtual void Load();
	virtual void Unload();
	virtual int Update(float deltaTime);
	virtual void Render();

private:
    Camera cam;
	Scene m_Scene;
    MatrixStack m_MatStack; // MAD STACKS BROSEPH // <- HOLY SHIT DID I ACTUALLY WRITE THAT?

	GraphicsSystem m_GraphicsSys;
    //Materials
    Material StartMaterial;
    Material BackGroundMaterial;
    Quad quad;

    Background background;

    MenuItem start;
};

#endif

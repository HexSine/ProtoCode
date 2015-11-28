#include "BatInputLib/precompiled.h"
#include "BatKernel/batcore.h"
#include "BatInputLib/inputcontext.h"

InputContext::InputContext(std::string path)
{
    FILE* p_File = fopen(path.c_str(),"r");
    if( p_File == NULL ){
        printf("The lack of InputContext displeases me at the path %s\n", path.c_str());
        return;
    }

    char lineHeader[128];

    while( fscanf(p_File,"%s127",lineHeader) != EOF)
    {
        if(strcmp(lineHeader,"k"))
        {
            u32 key;
            fscanf(p_File,"%u",&key);
            keyState state;
            m_KeyMap.insert(std::pair<u32,keyState>(key,state));
        }
    }
    //ctor
}

InputContext::~InputContext()
{
    //dtor
}

void InputContext::Poll(GLFWwindow* _win)
{

}

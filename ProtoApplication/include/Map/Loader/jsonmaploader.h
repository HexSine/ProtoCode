#ifndef JSONMAPLOADER_H
#define JSONMAPLOADER_H

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <ProtoEngine.h>
#include "map.h"

using namespace rapidjson;
class JSONMapLoader
{
    public:
        JSONMapLoader();
        ~JSONMapLoader();
        bool Parse(const char* path);
        u32* p_id;
        u32 m_w, m_h, m_tw, m_th;
        glm::ivec2 m_ImageDimensions;
        std::string m_ImagePath;
        Document m_Doc;
};

#endif // JSONMAPLOADER_H

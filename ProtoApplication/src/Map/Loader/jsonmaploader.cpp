#include "jsonmaploader.h"

JSONMapLoader::JSONMapLoader() : p_id(NULL)
{
}
JSONMapLoader::~JSONMapLoader()
{
    SafeDeleteArray(p_id);
}
bool JSONMapLoader::Parse(const char* path)
{
    std::string line;
    std::string json;
    std::ifstream stageFile(path);
    if(stageFile.is_open())
    {
        while(std::getline(stageFile,line))
        {
            json += line;
        }
        stageFile.close();
    }
    m_Doc.Parse(json.c_str());

    //Set Map and tile dimensions
    m_w = m_Doc["width"].GetInt();
    m_h = m_Doc["height"].GetInt();
    m_tw = m_Doc["tilewidth"].GetInt();
    m_th = m_Doc["tileheight"].GetInt();

    //Set all the id's
    p_id = new u32[m_w * m_h];
    Value& data = m_Doc["layers"][0]["data"];

    for(u32 i = 0; i < m_w * m_h;++i)
    {
        p_id[i] = data[i].GetUint();
    }
    //Get Texture paths
    Value& tileSheet = m_Doc["tilesets"][0];
    m_ImagePath = tileSheet["image"].GetString();
    m_ImageDimensions.x = tileSheet["imagewidth"].GetInt();
    m_ImageDimensions.y = tileSheet["imageheight"].GetInt();



}

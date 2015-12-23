#include "BatApplication/precompiled.h"
#include "BatApplication/Map/jsonmaploader.h"


JSONMapLoader::JSONMapLoader()
{
}
JSONMapLoader::~JSONMapLoader()
{
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
    //p_id = new u32[m_w * m_h];
    Value& layers = m_Doc["layers"];
    ReadLayers(layers);

    //Get Texture paths
    Value& tileSheet = m_Doc["tilesets"][0];
    m_ImagePath = tileSheet["image"].GetString();
    m_ImageDimensions.x = tileSheet["imagewidth"].GetInt();
    m_ImageDimensions.y = tileSheet["imageheight"].GetInt();
    return true;

}
void JSONMapLoader::ReadLayers(Value& inValue)
{
    u32 c = inValue.Size();
    for(u32 i = 0; i < c; ++i)
    {
        Value& vLayer = inValue[i];
        Value& vData = vLayer["data"];

        Layer layer;
        layer.m_Type = atoi(vLayer["properties"]["layerType"].GetString());
        u32 dSize = vData.Size();
        layer.m_Tiles.resize(dSize);

        for(u32 iter = 0; iter < dSize; ++iter)
        {
            layer.m_Tiles[iter] = vData[iter].GetUint();
        }
        m_Layers.push_back(layer);
    }
}

return {
  version = "1.1",
  luaversion = "5.1",
  tiledversion = "0.12.3",
  orientation = "orthogonal",
  width = 15,
  height = 9,
  tilewidth = 32,
  tileheight = 32,
  nextobjectid = 16,
  properties = {},
  tilesets = {
    {
      name = "tileset_brick",
      firstgid = 1,
      tilewidth = 32,
      tileheight = 32,
      spacing = 0,
      margin = 0,
      image = "../Textures/Map/tileset_brick.png",
      imagewidth = 256,
      imageheight = 256,
      tileoffset = {
        x = 0,
        y = 0
      },
      properties = {},
      terrains = {},
      tiles = {}
    },
    {
      name = "Entity",
      firstgid = 65,
      tilewidth = 32,
      tileheight = 32,
      spacing = 0,
      margin = 0,
      tileoffset = {
        x = 0,
        y = 0
      },
      properties = {},
      terrains = {},
      tiles = {
        {
          id = 0,
          properties = {
            ["id"] = "1"
          },
          image = "../Textures/Characters/Batte.png",
          width = 32,
          height = 32
        },
        {
          id = 1,
          properties = {
            ["id"] = "2"
          },
          image = "../Textures/Characters/knight.png",
          width = 32,
          height = 32
        }
      }
    }
  },
  layers = {
    {
      type = "tilelayer",
      name = "GamePlay",
      x = 0,
      y = 0,
      width = 15,
      height = 9,
      visible = true,
      opacity = 1,
      properties = {
        ["type"] = "Tile"
      },
      encoding = "lua",
      data = {
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2,
        2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2,
        2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,
        2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
      }
    },
    {
      type = "objectgroup",
      name = "Object Layer 1",
      visible = true,
      opacity = 1,
      properties = {},
      objects = {
        {
          id = 13,
          name = "",
          type = "",
          shape = "rectangle",
          x = 64,
          y = 128,
          width = 32,
          height = 32,
          rotation = 0,
          gid = 65,
          visible = true,
          properties = {}
        },
        {
          id = 15,
          name = "",
          type = "",
          shape = "rectangle",
          x = 389,
          y = 129,
          width = 32,
          height = 32,
          rotation = 0,
          gid = 66,
          visible = true,
          properties = {}
        }
      }
    }
  }
}

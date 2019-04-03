package ext;
import host.*;

struct Ext
{
  //Map<ext.Type,ext.ValueChoice> map;
  MapList<ext.Type, ext.ValueChoice> mapList;

  uint8 number;
  MapListParams(number)<ext.Type, ext.ValueChoice> mapList2;

  MapContainer<ext.Type, ext.ValueChoice> mapcontainer;

  Map3(number)<ext.Type, ext.ValueChoice> mapListOffsets;

  Map4(5)<ext.Type2> map4;
};

struct Type2(uint8 num)
{
  uint8 bla;
};

enum uint8 Type
{
  FOO,
  BAR,
};

choice ValueChoice(Type t) on t
{
  case FOO:
    uint8 foo;
  case BAR:
    uint16 bar;
};

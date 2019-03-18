package ext;
import host.*;

struct Ext
{
  //Map<ext.Type,ext.ValueChoice> map;
  MapList<ext.Type, ext.ValueChoice> mapList;

  uint8 number;
  MapListParams(number)<ext.Type, ext.ValueChoice> mapList2;
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

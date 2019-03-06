package ext;
import host.*;

struct Ext
{
  Map<ext.Type,ext.ValueChoice> map;
};

struct Ext2
{
    ext.Type type;
    ext.ValueChoice(type) value;
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

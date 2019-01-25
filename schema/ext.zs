package ext;

import host.*;

//instance Map<Pair> RoutingMap;

/*
struct Pair
{
  Type t;
  Value v;
};
*/

struct Ext
{
  /*template://  Map<T,V>(Type, Value) map1 */ Map map;

};
/*
struct Ext2
{
  Map<Type,Value> map3;
};*/

enum uint8 Type
{
  FOO,
  BAR,
};

struct Value
{
  string someString;
  uint8 someNumber;
};

choice ValueChoice(Type t) on t
{
  case FOO:
    uint8 foo;
  case BAR:
    uint16 bar;
};

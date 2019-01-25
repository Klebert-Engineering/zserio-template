package ext;

import host.*;

//instance Map<Type, ValueChoice> RoutingMap;


struct Ext
{
  /*RoutingMap */ Map map;

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

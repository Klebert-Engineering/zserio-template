package host;

struct Map<T, V>
{
  Header(1) header;
  <T> type;
  <V>(type) value;
};

struct Header(uint8 num)
{
  uint16 moreNumbers = 8;
  string someStuff = "Blabla";
  uint32 evenMoreNumbers = 0;
  uint32 offset[num];
};

struct MapList<T, V>
{
  Map<T,V>  maps[];
};

struct MapListParams<T, V>(uint8 num)
{
  Map<T,V> maps[num];
};

struct MapContainer<T,V>
{
  <T> type;
  Map2(type)<T,V> secondMap;
};

struct Map2<T, V>(<T> type)
{
  <V>(type) value;
};

struct Map3<T,V>(uint8 num)
{
  uint32 count;
  Header(num) header;
header.offset[@index]:
  MapListParams(count)<T,V> maps[num];
};

struct Map4<T>(uint8 num)
{
  uint8 count;
  <T>(num) list[count];
};

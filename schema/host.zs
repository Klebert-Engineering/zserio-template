package host;

struct Map<T, V>
{
  Header header;
  <T> type;
  <V>(type) value;
};

struct Header
{
  uint16 moreNumbers = 8;
  string someStuff = "Blabla";
  uint32 evenMoreNumbers = 0;
};

struct MapList<T, V>
{
  Map<T,V>  maps[];
};

struct MapListParams<T, V>(uint8 num)
{
  Map<T,V> maps[num];
};

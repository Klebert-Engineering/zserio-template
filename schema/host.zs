package host;


struct Map
{
  Header header;

  uint8 type;
  Value(type) val;
};

/*
template Map<T, V>
{
  Header header;
  T type;
  V(T) value;
};
*/

struct Header
{
  uint16 moreNumbers = 8;
  string someStuff = "Blabla";
  uint32 evenMoreNumbers = 0;
};

choice Value(uint8 type) on type
{
  case 0:
    uint16 value;
  case 1:
    uint8 small;
};

/*
template Map<T, V>
{
  int8 num;

  T type;
  V value;
};
*/

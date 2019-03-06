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

choice Value(uint8 type) on type
{
  case 0:
    uint16 value;
  case 1:
    uint8 small;
};


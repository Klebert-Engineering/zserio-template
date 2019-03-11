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

#include <host/Map.h>
#include <ext/Ext.h>

#include <iostream>


int main()
{
	// writer:
	ext::Ext obj;
	host::Header header;
	host::Map<ext::Type, ext::ValueChoice> map;

	ext::Type type = ext::Type::FOO;
	ext::ValueChoice value;
	value.initialize(type);
	value.setFoo(5);

	map.setHeader(header);
	map.setType(type);
	map.setValue(value);

	obj.setMap(map);

	zserio::BitStreamWriter writer;
	obj.write(writer);

	size_t size;
	const uint8_t *buffer = writer.getWriteBuffer(size);

	// read it in:
	zserio::BitStreamReader reader(buffer, size);
	ext::Ext obj2;
	obj2.read(reader);
	uint8_t foo = obj2.getMap().getValue().getFoo();
	std::cout << "Read number: " << std::to_string(foo) << std::endl;

	return 0;
}

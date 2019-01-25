/**
 * Automatically generated by Zserio C++ extension version 1.1.0.
 */

#ifndef HOST_MAP_H
#define HOST_MAP_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/StringConvertUtil.h>
#include <zserio/PreWriteAction.h>
#include <zserio/Types.h>

namespace host
{

template <class T, class V> class Map
{
public:
	Map() {};

	T getType() { return m_type; };
	void setType(T type) { m_type = type; };

	V getValue() { return m_value; };
	void setValue(V value) { m_value = value;  };

	size_t bitSizeOf(size_t _bitPosition = 0)
	{
		size_t _endBitPosition = _bitPosition;
	
		_endBitPosition += m_type.bitSizeOf(_endBitPosition);
		_endBitPosition += m_value.bitSizeOf(_endBitPosition);

		return _endBitPosition - _bitPosition;
	};

	size_t initializeOffsets(size_t _bitPosition)
	{
		size_t _endBitPosition = _bitPosition;

		_endBitPosition += m_type.initializeOffsets(_endBitPosition);
		_endBitPosition += m_value.initializeOffsets(_endBitPosition);

		return _endBitPosition;
	};

    //bool operator==(const Map& other) const;
    //int hashCode() const;

	void read(zserio::BitStreamReader& _in)
	{
		m_type.read(_in);
		m_value.read(_in);
	};

	void write(zserio::BitStreamWriter& _out,
		zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS)
	{
		m_type.write(_out, _preWriteAction);
		m_value.write(_out, _preWriteAction);
	};

private:

    T m_type;

    V m_value;
};

} // namespace host

#endif // HOST_MAP_H

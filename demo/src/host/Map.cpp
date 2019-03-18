
/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>


namespace host
{

template <class T,class V>
Map<T,V>::Map() :
        m_areChildrenInitialized(false)
{
    m_header.reset(new (m_header.getResetStorage())
            host::Header());
    m_type.reset(new (m_type.getResetStorage())
            T());
    m_value.reset(new (m_value.getResetStorage())
            V());
}

template <class T,class V>
Map<T,V>::Map(zserio::BitStreamReader& _in) :
        m_areChildrenInitialized(true)
{
    read(_in);
}

template <class T,class V>
Map<T,V>::Map(const Map& _other) :
        m_header(_other.m_header),
        m_type(_other.m_type),
        m_value(_other.m_value)
{
    if (_other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;
}

template <class T,class V>
Map<T,V>& Map<T,V>::operator=(const Map<T,V>& _other)
{
    m_header = _other.m_header;
    m_type = _other.m_type;
    m_value = _other.m_value;
    if (_other.m_areChildrenInitialized)
        initializeChildren();
    else
        m_areChildrenInitialized = false;

    return *this;
}

template <class T,class V>
void Map<T,V>::initializeChildren()
{
    m_value.get().initialize(getType());

    m_areChildrenInitialized = true;
}

template <class T,class V>
host::Header& Map<T,V>::getHeader()
{
    return m_header.get();
}

template <class T,class V>
const host::Header& Map<T,V>::getHeader() const
{
    return m_header.get();
}

template <class T,class V>
void Map<T,V>::setHeader(const host::Header& header)
{
    m_header.set(header);
}

template <class T,class V>
T& Map<T,V>::getType()
{
    return m_type.get();
}

template <class T,class V>
const T& Map<T,V>::getType() const
{
    return m_type.get();
}

template <class T,class V>
void Map<T,V>::setType(const T& type)
{
    m_type.set(type);
}

template <class T,class V>
V& Map<T,V>::getValue()
{
    return m_value.get();
}

template <class T,class V>
const V& Map<T,V>::getValue() const
{
    return m_value.get();
}

template <class T,class V>
void Map<T,V>::setValue(const V& value)
{
    m_value.set(value);
}

template <class T,class V>
size_t Map<T,V>::bitSizeOf(size_t _bitPosition) const
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition += m_header.get().bitSizeOf(_endBitPosition);
    _endBitPosition += m_type.get().bitSizeOf(_endBitPosition);
    _endBitPosition += m_value.get().bitSizeOf(_endBitPosition);

    return _endBitPosition - _bitPosition;
}

template <class T,class V>
size_t Map<T,V>::initializeOffsets(size_t _bitPosition)
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition = m_header.get().initializeOffsets(_endBitPosition);
    _endBitPosition = m_type.get().initializeOffsets(_endBitPosition);
    _endBitPosition = m_value.get().initializeOffsets(_endBitPosition);

    return _endBitPosition;
}

template <class T,class V>
bool Map<T,V>::operator==(const Map& _other) const
{
    if (this != &_other)
    {
        return
                (m_header == _other.m_header) &&
                (m_type == _other.m_type) &&
                (m_value == _other.m_value);
    }

    return true;
}

template <class T,class V>
int Map<T,V>::hashCode() const
{
    int _result = zserio::HASH_SEED;

        _result = zserio::calcHashCode(_result, m_header);
        _result = zserio::calcHashCode(_result, m_type);
        _result = zserio::calcHashCode(_result, m_value);

    return _result;
}

template <class T,class V>
void Map<T,V>::read(zserio::BitStreamReader& _in)
{
    m_header.reset(new (m_header.getResetStorage())
            host::Header(_in));
    m_type.reset(new (m_type.getResetStorage())
            T(_in));
    m_value.reset(new (m_value.getResetStorage())
            V(_in, getType()));
}

template <class T,class V>
void Map<T,V>::write(zserio::BitStreamWriter& _out, zserio::PreWriteAction _preWriteAction)
{
    if ((_preWriteAction & zserio::PRE_WRITE_INITIALIZE_CHILDREN) != 0)
        initializeChildren();

    m_header.get().write(_out, zserio::NO_PRE_WRITE_ACTION);
    m_type.get().write(_out, zserio::NO_PRE_WRITE_ACTION);
    m_value.get().write(_out, zserio::NO_PRE_WRITE_ACTION);
}

} // namespace host

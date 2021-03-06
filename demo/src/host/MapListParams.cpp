
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

namespace
{


template <class T,class V>
class _elementFactory_MapListParams_maps
{
public:
    explicit _elementFactory_MapListParams_maps(MapListParams<T,V>& owner) : m_owner(owner) {}

    void create(void* storage, zserio::BitStreamReader& _in, size_t _index)
    {
        (void)_index;
        new (storage) host::Map<T,V>(_in);
    }

private:
    MapListParams<T,V>& m_owner;
};

template <class T,class V>
class _elementChildrenInitializer_MapListParams_maps
{
public:
    _elementChildrenInitializer_MapListParams_maps() {}

    void initialize(host::Map<T,V>& element, size_t)
    {
        element.initializeChildren();
    }
};

} // namespace

template <class T,class V>
MapListParams<T,V>::MapListParams() :
        m_isInitialized(false)
{
}

template <class T,class V>
MapListParams<T,V>::MapListParams(zserio::BitStreamReader& _in,
        uint8_t num) :
        m_num(num),
        m_isInitialized(true)
{
    read(_in);
}

template <class T,class V>
MapListParams<T,V>::MapListParams(const MapListParams& _other) :
        m_maps(_other.m_maps)
{
    if (_other.m_isInitialized)
        initialize(_other.m_num);
    else
        m_isInitialized = false;
}

template <class T,class V>
MapListParams<T,V>& MapListParams<T,V>::operator=(const MapListParams<T,V>& _other)
{
    m_maps = _other.m_maps;
    if (_other.m_isInitialized)
        initialize(_other.m_num);
    else
        m_isInitialized = false;

    return *this;
}

template <class T,class V>
void MapListParams<T,V>::initialize(
        uint8_t num)
{
    m_num = num;
    m_isInitialized = true;

    initializeChildren();
}

template <class T,class V>
void MapListParams<T,V>::initializeChildren()
{
    m_maps.initializeElements(_elementChildrenInitializer_MapListParams_maps<T,V>());
}

template <class T,class V>
uint8_t MapListParams<T,V>::getNum() const
{
    if (!m_isInitialized)
        throw zserio::CppRuntimeException("Parameter num of compound MapListParams "
                "is not initialized!");

    return m_num;
}

template <class T,class V>
zserio::ObjectArray<host::Map<T,V> >& MapListParams<T,V>::getMaps()
{
    return m_maps;
}

template <class T,class V>
const zserio::ObjectArray<host::Map<T,V> >& MapListParams<T,V>::getMaps() const
{
    return m_maps;
}

template <class T,class V>
void MapListParams<T,V>::setMaps(const zserio::ObjectArray<host::Map<T,V> >& maps)
{
    m_maps = maps;
}

template <class T,class V>
size_t MapListParams<T,V>::bitSizeOf(size_t _bitPosition) const
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition += m_maps.bitSizeOf(_endBitPosition);

    return _endBitPosition - _bitPosition;
}

template <class T,class V>
size_t MapListParams<T,V>::initializeOffsets(size_t _bitPosition)
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition = m_maps.initializeOffsets(_endBitPosition);

    return _endBitPosition;
}

template <class T,class V>
bool MapListParams<T,V>::operator==(const MapListParams& _other) const
{
    if (this != &_other)
    {
        return
                (getNum() == _other.getNum()) &&
                (m_maps == _other.m_maps);
    }

    return true;
}

template <class T,class V>
int MapListParams<T,V>::hashCode() const
{
    int _result = zserio::HASH_SEED;

    _result = zserio::calcHashCode(_result, getNum());
        _result = zserio::calcHashCode(_result, m_maps);

    return _result;
}

template <class T,class V>
void MapListParams<T,V>::read(zserio::BitStreamReader& _in)
{
    m_maps.read(_in, static_cast<size_t>(getNum()), _elementFactory_MapListParams_maps<T,V>(*this));
}

template <class T,class V>
void MapListParams<T,V>::write(zserio::BitStreamWriter& _out, zserio::PreWriteAction _preWriteAction)
{
    if ((_preWriteAction & zserio::PRE_WRITE_INITIALIZE_CHILDREN) != 0)
        initializeChildren();

    if (m_maps.size() != static_cast<size_t>(getNum()))
    {
        throw zserio::CppRuntimeException("Write: Wrong array length for field MapListParams.maps: " +
                zserio::convertToString(m_maps.size()) + " != " +
                zserio::convertToString(static_cast<size_t>(getNum())) + "!");
    }
    m_maps.write(_out);
}

} // namespace host

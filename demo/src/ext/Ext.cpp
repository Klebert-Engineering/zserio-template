
/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>

#include "ext/Ext.h"

namespace ext
{


Ext::Ext()
{
    m_mapList.reset(new (m_mapList.getResetStorage())
            host::MapList<ext::Type, ext::ValueChoice>());
}


Ext::Ext(zserio::BitStreamReader& _in)
{
    read(_in);
}


void Ext::initializeChildren()
{
    m_mapList.get().initializeChildren();
}


host::MapList<ext::Type, ext::ValueChoice>& Ext::getMapList()
{
    return m_mapList.get();
}


const host::MapList<ext::Type, ext::ValueChoice>& Ext::getMapList() const
{
    return m_mapList.get();
}


void Ext::setMapList(const host::MapList<ext::Type, ext::ValueChoice>& mapList)
{
    m_mapList.set(mapList);
}


size_t Ext::bitSizeOf(size_t _bitPosition) const
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition += m_mapList.get().bitSizeOf(_endBitPosition);

    return _endBitPosition - _bitPosition;
}


size_t Ext::initializeOffsets(size_t _bitPosition)
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition = m_mapList.get().initializeOffsets(_endBitPosition);

    return _endBitPosition;
}


bool Ext::operator==(const Ext& _other) const
{
    if (this != &_other)
    {
        return
                (m_mapList == _other.m_mapList);
    }

    return true;
}


int Ext::hashCode() const
{
    int _result = zserio::HASH_SEED;

        _result = zserio::calcHashCode(_result, m_mapList);

    return _result;
}


void Ext::read(zserio::BitStreamReader& _in)
{
    m_mapList.reset(new (m_mapList.getResetStorage())
            host::MapList<ext::Type, ext::ValueChoice>(_in));
}


void Ext::write(zserio::BitStreamWriter& _out, zserio::PreWriteAction _preWriteAction)
{
    if ((_preWriteAction & zserio::PRE_WRITE_INITIALIZE_CHILDREN) != 0)
        initializeChildren();

    m_mapList.get().write(_out, zserio::NO_PRE_WRITE_ACTION);
}

} // namespace ext

/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>

#include "ext/ValueChoice.h"

namespace ext
{

ValueChoice::ValueChoice() :
        m_isInitialized(false)
{
}


ValueChoice::ValueChoice(zserio::BitStreamReader& _in,
        ext::Type t) :
        m_t(t),
        m_isInitialized(true)
{
    read(_in);
}


ValueChoice::ValueChoice(const ValueChoice& _other) :
        m_objectChoice(_other.m_objectChoice)
{
    if (_other.m_isInitialized)
        initialize(_other.m_t);
    else
        m_isInitialized = false;
}


ValueChoice& ValueChoice::operator=(const ValueChoice& _other)
{
    m_objectChoice = _other.m_objectChoice;
    if (_other.m_isInitialized)
        initialize(_other.m_t);
    else
        m_isInitialized = false;

    return *this;
}


void ValueChoice::initialize(
        ext::Type t)
{
    m_t = t;
    m_isInitialized = true;
}

ext::Type ValueChoice::getT() const
{
    if (!m_isInitialized)
        throw zserio::CppRuntimeException("Parameter t of compound ValueChoice "
                "is not initialized!");

    return m_t;
}


uint8_t ValueChoice::getFoo() const
{
    return m_objectChoice.get<uint8_t>();
}


void ValueChoice::setFoo(uint8_t foo)
{
    m_objectChoice.set(foo);
}


uint16_t ValueChoice::getBar() const
{
    return m_objectChoice.get<uint16_t>();
}


void ValueChoice::setBar(uint16_t bar)
{
    m_objectChoice.set(bar);
}

size_t ValueChoice::bitSizeOf(size_t _bitPosition) const
{
    size_t _endBitPosition = _bitPosition;

    switch (getT())
    {
    case ext::Type::FOO:
        _endBitPosition += UINT8_C(8);
        break;
    case ext::Type::BAR:
        _endBitPosition += UINT8_C(16);
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice ValueChoice!");
    }

    return _endBitPosition - _bitPosition;
}

size_t ValueChoice::initializeOffsets(size_t _bitPosition)
{
    size_t _endBitPosition = _bitPosition;

    switch (getT())
    {
    case ext::Type::FOO:
        _endBitPosition += UINT8_C(8);
        break;
    case ext::Type::BAR:
        _endBitPosition += UINT8_C(16);
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice ValueChoice!");
    }

    return _endBitPosition;
}

bool ValueChoice::operator==(const ValueChoice& _other) const
{
    if (this != &_other)
    {
        return
                (getT() == _other.getT()) &&
                (m_objectChoice == _other.m_objectChoice);
    }

    return true;
}

int ValueChoice::hashCode() const
{
    int _result = zserio::HASH_SEED;

    _result = zserio::calcHashCode(_result, getT());
    _result = zserio::calcHashCode(_result, m_objectChoice);

    return _result;
}

void ValueChoice::read(zserio::BitStreamReader& _in)
{
    switch (getT())
    {
    case ext::Type::FOO:
        m_objectChoice.reset(new (m_objectChoice.getResetStorage<uint8_t>())
                uint8_t(_in.readBits(UINT8_C(8))));
        break;
    case ext::Type::BAR:
        m_objectChoice.reset(new (m_objectChoice.getResetStorage<uint16_t>())
                uint16_t(_in.readBits(UINT8_C(16))));
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice ValueChoice!");
    }
}

void ValueChoice::write(zserio::BitStreamWriter& _out, zserio::PreWriteAction)
{
    switch (getT())
    {
    case ext::Type::FOO:
        _out.writeBits(m_objectChoice.get<uint8_t>(), UINT8_C(8));
        break;
    case ext::Type::BAR:
        _out.writeBits(m_objectChoice.get<uint16_t>(), UINT8_C(16));
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice ValueChoice!");
    }
}

} // namespace ext
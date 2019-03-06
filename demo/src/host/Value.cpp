
/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>

#include "host/Value.h"

namespace host
{

Value::Value() :
        m_isInitialized(false)
{
}


Value::Value(zserio::BitStreamReader& _in,
        uint8_t type) :
        m_type(type),
        m_isInitialized(true)
{
    read(_in);
}


Value::Value(const Value& _other) :
        m_objectChoice(_other.m_objectChoice)
{
    if (_other.m_isInitialized)
        initialize(_other.m_type);
    else
        m_isInitialized = false;
}


Value& Value::operator=(const Value& _other)
{
    m_objectChoice = _other.m_objectChoice;
    if (_other.m_isInitialized)
        initialize(_other.m_type);
    else
        m_isInitialized = false;

    return *this;
}


void Value::initialize(
        uint8_t type)
{
    m_type = type;
    m_isInitialized = true;
}

uint8_t Value::getType() const
{
    if (!m_isInitialized)
        throw zserio::CppRuntimeException("Parameter type of compound Value "
                "is not initialized!");

    return m_type;
}


uint16_t Value::getValue() const
{
    return m_objectChoice.get<uint16_t>();
}


void Value::setValue(uint16_t value)
{
    m_objectChoice.set(value);
}


uint8_t Value::getSmall() const
{
    return m_objectChoice.get<uint8_t>();
}


void Value::setSmall(uint8_t small)
{
    m_objectChoice.set(small);
}

size_t Value::bitSizeOf(size_t _bitPosition) const
{
    size_t _endBitPosition = _bitPosition;

    switch (getType())
    {
    case 0:
        _endBitPosition += UINT8_C(16);
        break;
    case 1:
        _endBitPosition += UINT8_C(8);
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice Value!");
    }

    return _endBitPosition - _bitPosition;
}

size_t Value::initializeOffsets(size_t _bitPosition)
{
    size_t _endBitPosition = _bitPosition;

    switch (getType())
    {
    case 0:
        _endBitPosition += UINT8_C(16);
        break;
    case 1:
        _endBitPosition += UINT8_C(8);
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice Value!");
    }

    return _endBitPosition;
}

bool Value::operator==(const Value& _other) const
{
    if (this != &_other)
    {
        return
                (getType() == _other.getType()) &&
                (m_objectChoice == _other.m_objectChoice);
    }

    return true;
}

int Value::hashCode() const
{
    int _result = zserio::HASH_SEED;

    _result = zserio::calcHashCode(_result, getType());
    _result = zserio::calcHashCode(_result, m_objectChoice);

    return _result;
}

void Value::read(zserio::BitStreamReader& _in)
{
    switch (getType())
    {
    case 0:
        m_objectChoice.reset(new (m_objectChoice.getResetStorage<uint16_t>())
                uint16_t(_in.readBits(UINT8_C(16))));
        break;
    case 1:
        m_objectChoice.reset(new (m_objectChoice.getResetStorage<uint8_t>())
                uint8_t(_in.readBits(UINT8_C(8))));
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice Value!");
    }
}

void Value::write(zserio::BitStreamWriter& _out, zserio::PreWriteAction)
{
    switch (getType())
    {
    case 0:
        _out.writeBits(m_objectChoice.get<uint16_t>(), UINT8_C(16));
        break;
    case 1:
        _out.writeBits(m_objectChoice.get<uint8_t>(), UINT8_C(8));
        break;
    default:
        throw zserio::CppRuntimeException("No match in choice Value!");
    }
}

} // namespace host


/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#include <zserio/StringConvertUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/BitPositionUtil.h>
#include <zserio/BitSizeOfCalculator.h>
#include <zserio/BitFieldUtil.h>

#include "host/Header.h"

namespace host
{


Header::Header()
{
    m_moreNumbers = 8;
    m_someStuff = "Blabla";
    m_evenMoreNumbers = 0;
}


Header::Header(zserio::BitStreamReader& _in)
{
    read(_in);
}


uint16_t Header::getMoreNumbers() const
{
    return m_moreNumbers;
}


void Header::setMoreNumbers(uint16_t moreNumbers)
{
    m_moreNumbers = moreNumbers;
}


std::string& Header::getSomeStuff()
{
    return m_someStuff;
}


const std::string& Header::getSomeStuff() const
{
    return m_someStuff;
}


void Header::setSomeStuff(const std::string& someStuff)
{
    m_someStuff = someStuff;
}


uint32_t Header::getEvenMoreNumbers() const
{
    return m_evenMoreNumbers;
}


void Header::setEvenMoreNumbers(uint32_t evenMoreNumbers)
{
    m_evenMoreNumbers = evenMoreNumbers;
}


size_t Header::bitSizeOf(size_t _bitPosition) const
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition += UINT8_C(16);
    _endBitPosition += zserio::getBitSizeOfString(m_someStuff);
    _endBitPosition += UINT8_C(32);

    return _endBitPosition - _bitPosition;
}


size_t Header::initializeOffsets(size_t _bitPosition)
{
    size_t _endBitPosition = _bitPosition;

    _endBitPosition += UINT8_C(16);
    _endBitPosition += zserio::getBitSizeOfString(m_someStuff);
    _endBitPosition += UINT8_C(32);

    return _endBitPosition;
}


bool Header::operator==(const Header& _other) const
{
    if (this != &_other)
    {
        return
                (m_moreNumbers == _other.m_moreNumbers) &&
                (m_someStuff == _other.m_someStuff) &&
                (m_evenMoreNumbers == _other.m_evenMoreNumbers);
    }

    return true;
}


int Header::hashCode() const
{
    int _result = zserio::HASH_SEED;

        _result = zserio::calcHashCode(_result, m_moreNumbers);
        _result = zserio::calcHashCode(_result, m_someStuff);
        _result = zserio::calcHashCode(_result, m_evenMoreNumbers);

    return _result;
}


void Header::read(zserio::BitStreamReader& _in)
{
    m_moreNumbers = (uint16_t)_in.readBits(UINT8_C(16));
    m_someStuff = (std::string)_in.readString();
    m_evenMoreNumbers = (uint32_t)_in.readBits(UINT8_C(32));
}


void Header::write(zserio::BitStreamWriter& _out, zserio::PreWriteAction)
{
    _out.writeBits(m_moreNumbers, UINT8_C(16));
    _out.writeString(m_someStuff);
    _out.writeBits(m_evenMoreNumbers, UINT8_C(32));
}

} // namespace host

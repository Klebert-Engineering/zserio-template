/**
 * Automatically generated by Zserio C++ extension version 1.1.0.
 */

#ifndef HOST_VALUE_H
#define HOST_VALUE_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AnyHolder.h>
#include <zserio/PreWriteAction.h>
#include <zserio/Types.h>

namespace host
{

class Value
{
public:
    Value();
    Value(zserio::BitStreamReader& _in,
            uint8_t type);

    Value(const Value& _other);
    Value& operator=(const Value& _other);

    void initialize(
            uint8_t type);

    uint8_t getType() const;

    uint16_t getValue() const;
    void setValue(uint16_t value);

    uint8_t getSmall() const;
    void setSmall(uint8_t small);

    size_t bitSizeOf(size_t _bitPosition = 0) const;
    size_t initializeOffsets(size_t _bitPosition);

    bool operator==(const Value& other) const;
    int hashCode() const;

    void read(zserio::BitStreamReader& _in);
    void write(zserio::BitStreamWriter& _out,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS);

private:
    uint8_t m_type;
    bool m_isInitialized;
    zserio::AnyHolder m_objectChoice;
};

} // namespace host

#endif // HOST_VALUE_H

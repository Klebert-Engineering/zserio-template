
/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#ifndef EXT_VALUE_CHOICE_H
#define EXT_VALUE_CHOICE_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/AnyHolder.h>
#include <zserio/PreWriteAction.h>
#include <zserio/Types.h>

#include "ext/Type.h"

namespace ext
{

class ValueChoice
{
public:
    ValueChoice();
    ValueChoice(zserio::BitStreamReader& _in,
            ext::Type t);

    ValueChoice(const ValueChoice& _other);
   ValueChoice& operator=(const ValueChoice& _other);

    void initialize(
            ext::Type t);

    ext::Type getT() const;

    uint8_t getFoo() const;
    void setFoo(uint8_t foo);

    uint16_t getBar() const;
    void setBar(uint16_t bar);

    size_t bitSizeOf(size_t _bitPosition = 0) const;
    size_t initializeOffsets(size_t _bitPosition);

    bool operator==(const ValueChoice& other) const;
    int hashCode() const;

    void read(zserio::BitStreamReader& _in);
    void write(zserio::BitStreamWriter& _out,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS);

private:
    ext::Type m_t;
    bool m_isInitialized;
    zserio::AnyHolder m_objectChoice;
};

} // namespace ext

#endif // EXT_VALUE_CHOICE_H
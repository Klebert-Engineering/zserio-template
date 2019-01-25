/**
 * Automatically generated by Zserio C++ extension version 1.1.0.
 */

#ifndef EXT_TYPE_H
#define EXT_TYPE_H

#include <string>
#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/HashCodeUtil.h>
#include <zserio/PreWriteAction.h>
#include <zserio/Types.h>

namespace ext
{

class Type
{
public:
    /**
     * The type this enum is based on.
     *
     * This is the C++ mapping of the original zserio type. It can be
     * wider than the original type. E.g. "enum bit:3" would have uint8_t
     * as its base type.
     */
    typedef uint8_t _base_type;

    enum e_Type
    {
        FOO = UINT8_C(0),
        BAR = UINT8_C(1)
    };

    Type();
    Type(e_Type value);
    Type(_base_type baseTypeValue);
    explicit Type(zserio::BitStreamReader& _in);

    operator e_Type() const;
    uint8_t getValue() const;

    size_t bitSizeOf(size_t _bitPosition = 0) const;
    size_t initializeOffsets(size_t _bitPosition = 0) const;

    bool operator==(const Type& other) const;
    bool operator==(e_Type other) const;
    int hashCode() const;

    void read(zserio::BitStreamReader& _in);
    void write(zserio::BitStreamWriter& _out,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS) const;

    const char* toString() const;

    static Type toEnum(uint8_t rawValue);

private:
    e_Type m_value;
};

} // namespace ext

#endif // EXT_TYPE_H

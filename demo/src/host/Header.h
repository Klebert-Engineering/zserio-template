
/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#ifndef HOST_HEADER_H
#define HOST_HEADER_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/StringConvertUtil.h>
#include <zserio/PreWriteAction.h>
#include <string>
#include <zserio/Types.h>

namespace host
{

class Header
{
public:
    Header();
    explicit Header(zserio::BitStreamReader& _in);

    uint16_t getMoreNumbers() const;
    void setMoreNumbers(uint16_t moreNumbers);

    std::string& getSomeStuff();
    const std::string& getSomeStuff() const;
    void setSomeStuff(const std::string& someStuff);

    uint32_t getEvenMoreNumbers() const;
    void setEvenMoreNumbers(uint32_t evenMoreNumbers);

    size_t bitSizeOf(size_t _bitPosition = 0) const;
    size_t initializeOffsets(size_t _bitPosition);

    bool operator==(const Header& other) const;
    int hashCode() const;

    void read(zserio::BitStreamReader& _in);
    void write(zserio::BitStreamWriter& _out,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS);

private:

    uint16_t m_moreNumbers;

    std::string m_someStuff;

    uint32_t m_evenMoreNumbers;
};

} // namespace host



#endif // HOST_HEADER_H

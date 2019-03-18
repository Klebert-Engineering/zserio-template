
/**
 * Automatically generated by Zserio C++ extension version 1.2.0.
 */

#ifndef EXT_EXT_H
#define EXT_EXT_H

#include <zserio/BitStreamReader.h>
#include <zserio/BitStreamWriter.h>
#include <zserio/BitFieldUtil.h>
#include <zserio/CppRuntimeException.h>
#include <zserio/StringConvertUtil.h>
#include <zserio/PreWriteAction.h>
#include <zserio/OptionalHolder.h>
#include <zserio/Types.h>

#include "ext/Type.h"
#include "ext/ValueChoice.h"
#include "host/MapContainer.h"
#include "host/MapList.h"
#include "host/MapListParams.h"

namespace ext
{

class Ext
{
public:
    Ext();
    explicit Ext(zserio::BitStreamReader& _in);

    Ext(const Ext& _other);
   Ext& operator=(const Ext& _other);

    void initializeChildren();

    host::MapList<ext::Type, ext::ValueChoice>& getMapList();
    const host::MapList<ext::Type, ext::ValueChoice>& getMapList() const;
    void setMapList(const host::MapList<ext::Type, ext::ValueChoice>& mapList);

    uint8_t getNumber() const;
    void setNumber(uint8_t number);

    host::MapListParams<ext::Type, ext::ValueChoice>& getMapList2();
    const host::MapListParams<ext::Type, ext::ValueChoice>& getMapList2() const;
    void setMapList2(const host::MapListParams<ext::Type, ext::ValueChoice>& mapList2);

    host::MapContainer<ext::Type, ext::ValueChoice>& getMapcontainer();
    const host::MapContainer<ext::Type, ext::ValueChoice>& getMapcontainer() const;
    void setMapcontainer(const host::MapContainer<ext::Type, ext::ValueChoice>& mapcontainer);

    size_t bitSizeOf(size_t _bitPosition = 0) const;
    size_t initializeOffsets(size_t _bitPosition);

    bool operator==(const Ext& other) const;
    int hashCode() const;

    void read(zserio::BitStreamReader& _in);
    void write(zserio::BitStreamWriter& _out,
            zserio::PreWriteAction _preWriteAction = zserio::ALL_PRE_WRITE_ACTIONS);

private:
    bool m_areChildrenInitialized;

    zserio::InPlaceOptionalHolder<host::MapList<ext::Type, ext::ValueChoice>> m_mapList;

    uint8_t m_number;

    zserio::InPlaceOptionalHolder<host::MapListParams<ext::Type, ext::ValueChoice>> m_mapList2;

    zserio::InPlaceOptionalHolder<host::MapContainer<ext::Type, ext::ValueChoice>> m_mapcontainer;
};

} // namespace ext



#endif // EXT_EXT_H

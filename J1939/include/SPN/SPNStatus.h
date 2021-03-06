/*
 * SPNStatus.h
 *
 *  Created on: Oct 24, 2017
 *      Author: root
 */

#ifndef SPN_SPNSTATUS_H_
#define SPN_SPNSTATUS_H_

#include <map>

#include <SPN/SPN.h>

namespace J1939 {

class SPNStatus: public SPN {

public:
    typedef std::map<u8, std::string> DescMap;
private:
	u8 mBitOffset;
	u8 mBitSize;
	u8 mValue;

    /*
     * Convertion from the status number to its description
     */
    DescMap mValueToDesc;

public:
    SPNStatus(u32 number, const std::string& name = "", size_t offset = 0, u8 bitOffset = 0, u8 bitSize = 0);
	virtual ~SPNStatus();


    void decode(const u8* buffer, size_t length);
    void encode(u8* buffer, size_t length) const;

	EType getType() const { return SPN_STATUS; }

	u8 getBitOffset() const { return mBitOffset; }
    void setBitOffset(u8 off) { mBitOffset = off; }

	u8 getBitSize() const { return mBitSize; }
    void setBitSize(u8 size) { mBitSize = size; }

	u8 getValue() const { return mValue; }
	bool setValue(u8 value);

	u8 getBitMask() const { return (0xFF >> (8 - mBitSize)) << mBitOffset; }


    /*
     * Methods to add/get descriptions over the different status numbers
     */
    void setValueDescription(u8 value, const std::string& desc);
    std::string getValueDescription(u8 value) const;
    void clearValueDescriptions();
    DescMap getValueDescriptionsMap() const;

    std::string toString() override;

    u8 getByteSize() const override { return 1; }		//Spn status has always size of 1

	IMPLEMENT_CLONEABLE(SPN, SPNStatus);

};

} /* namespace J1939 */

#endif /* SPN_SPNSTATUS_H_ */

/*
 * CanHelper.h
 *
 *  Created on: Sep 28, 2017
 *      Author: famez
 */

#ifndef SOCKETCANHELPER_H_
#define SOCKETCANHELPER_H_

#include <set>
#include <string>

#include "../../ICanHelper.h"

namespace Can {
namespace Sockets {

class SocketCanHelper : public Can::ICanHelper {
private:
	bool isUp(std::string interface) const;
	bool bringUp(std::string interface) const;
	bool bringDown(std::string interface) const;
	bool setBitrate(std::string interface, u32 bitrate) const;	
	bool isVirtual(std::string interface) const;

public:
	SocketCanHelper();
	virtual ~SocketCanHelper();

	std::set<std::string> getCanIfaces() override;

	bool isCompatible() override;

	std::string getBackend() override { return "SocketCan"; }

	ICanSender* allocateCanSender() override;
	CommonCanReceiver* allocateCanReceiver() override;

	bool initialize(std::string interface, u32 bitrate) override;

	void finalize(std::string interface) override;

	bool initialized(std::string interface) override;

};

} /* namespace Can */
}

#endif /* CANHELPER_H_ */

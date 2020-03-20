#pragma once
#include<api\serviceLocate.h>
#include<api\Loader.h>
struct MCRESULT {
	unsigned char filler[4];
	operator bool() {
		return filler[0];
	}
	bool isSuccess() {
		return operator bool();
	}
};
class MinecraftCommands;
class MinecraftCommands {
public:
	static MCRESULT _runcmd(void* origin, string const& cmd, int unk1, bool unk2) {
		MCRESULT rv;
		Call("?requestCommandExecution@MinecraftCommands@@QEBA?AUMCRESULT@@V?$unique_ptr@VCommandOrigin@@U?$default_delete@VCommandOrigin@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@4@H_N@Z", void, MinecraftCommands*, MCRESULT*, void**, string const&, int, bool)(LocateS<MinecraftCommands>()._srv, &rv, &origin, cmd, unk1, unk2);
		return rv;
	}
};
class RakNetServerLocator {
public:
	MCINLINE void accounce(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& b, int c_type, int d, int e, bool f) {
		Call("?announceServer@RakNetServerLocator@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4GameType@@HH_N@Z", void, void*, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, int, int, int, bool)(this, a, b, c_type, d, e, f);
	}
};

namespace mce {
	class UUID;
};
class NetworkIdentifier {
	char filler[144];
};
namespace Util {
	class HashString;
};
namespace Json {
	class Value;
}
struct RakAddr_t {
	char filler[0x90];
	string toString() {
		char buf[256];
		Call("?ToString_New@SystemAddress@RakNet@@AEBAX_NPEADD@Z", void, void*, bool, char*, char)(this, true, buf, ':');
		return buf;
	}
};
struct RakPeer_t {
	RakPeer_t(RakPeer_t const&) = delete;
	RakPeer_t(RakPeer_t&&) = delete;
	RakAddr_t getAdr(NetworkIdentifier const& ni) {
		RakAddr_t rv;
		Call("?GetSystemAddressFromGuid@RakPeer@RakNet@@UEBA?AUSystemAddress@2@URakNetGUID@2@@Z", void, void*, RakAddr_t*, NetworkIdentifier const*)(this, &rv, &ni);
		return rv;
	}
};
class ServerPlayer;
class ServerNetworkHandler {
public:
	//class ServerPlayer * __ptr64 __cdecl ServerNetworkHandler::_getServerPlayer(class NetworkIdentifier const & __ptr64,unsigned char)
	ServerPlayer* _getServerPlayer(NetworkIdentifier const& a0, unsigned char a1) {
		return Call("?_getServerPlayer@ServerNetworkHandler@@AEAAPEAVServerPlayer@@AEBVNetworkIdentifier@@E@Z", ServerPlayer*, decltype(this), decltype(a0), decltype(a1))(this, a0, a1);
	}
	MCINLINE void disconnectClient(class NetworkIdentifier const& a, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& b, bool c) {
		return Call("?disconnectClient@ServerNetworkHandler@@QEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z", void, void*, class NetworkIdentifier const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, bool)(this, a, b, c);
	}
	MCINLINE void onDisconnect(class NetworkIdentifier const& a0) { Call("?onDisconnect@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N1@Z", void, ServerNetworkHandler const*, class NetworkIdentifier const&)(this, a0); }
};
class Minecraft {
public:
	MCINLINE class Level* getLevel() {
		class Level* (Minecraft::*rv)();
		*((void**)&rv) = dlsym("?getLevel@Minecraft@@QEBAPEAVLevel@@XZ");
		return (this->*rv)();
	}
	MCINLINE class ServerNetworkHandler* getServerNetworkHandler() {
		class ServerNetworkHandler* (Minecraft::*rv)();
		*((void**)&rv) = dlsym("?getServerNetworkHandler@Minecraft@@QEAAPEAVServerNetworkHandler@@XZ");
		return (this->*rv)();
	}
};
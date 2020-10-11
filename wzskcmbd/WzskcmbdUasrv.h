/**
	* \file WzskcmbdUasrv.h
	* OPC UA server based on Matrikon FLEX OPC UA SDK for Wzsk combined daemon (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef WZSKCMBDUASRV_H
#define WZSKCMBDUASRV_H

#include "RootWzsk.h"

#include <iostream>
#include <stdlib.h>

#include <iuser_permissions_provider_t.h>
#include <iuser_permissions_t.h>

#include <time.h>

#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

#include "intrusive_ptr_t.h"
#include "allocatable_t.h"
#include "safe_ref_count_t.h"
#include "itransaction_listener_t.h"
#include "iserver_state_listener_t.h"
#include "iaddress_space_t.h"
#include "opcua_build_info_t.h"
#include "iserver_configuration_t.h"
#include "opcua_user_identity_token_type_t.h"
#include "std_file_t.h"
#include "access_level_t.h"
#include "write_mask_t.h"
#include "ilog_listener_t.h"
#include "certificate_generation_parameters_t.h"
#include "icertificate_private_key_password_provider_t.h"
#include "certificate_validation_options_t.h"
#include "opcua_node_id_numeric_t.h"
#include "uasdk_default_build_config.h"
#include "opcua_qualified_name_t.h"
#include "opcua_bytestring_t.h"
#include "utilities.h"
#include "opcua_guid_t.h"
#include "opcua_boolean_t.h"
#include "opcua_sbyte_t.h"
#include "opcua_byte_t.h"
#include "opcua_int16_t.h"
#include "opcua_uint16_t.h"
#include "opcua_int32_t.h"
#include "opcua_uint32_t.h"
#include "opcua_int64_t.h"
#include "opcua_uint64_t.h"
#include "opcua_float_t.h"
#include "opcua_double_t.h"
#include "uaserver_t.h"
#include "inode_value_attribute_reader_writer_t.h"
#include "localizable_text_stored_t.h"
#include "logger_t.h"
#include "folder_t.h"
#include "base_data_variable_t.h"
#include "inode_attribute_changed_listener_t.h"
#include "inode_attribute_about_to_be_read_listener_t.h"
#include "opcua_localized_text_t.h"
#include "localizable_text_stored_t.h"

#include "method_t.h"
#include "opcua_call_method_request_t.h"
#include "opcua_call_method_result_t.h"
#include "opcua_iruntime_type_t.h"

/**
	* WzskcmbdUasrv
	*/
namespace WzskcmbdUasrv {
	/**
		* VecVVartype
		*/
	namespace VecVVartype {
		const Sbecore::uint VOID = 1;
		const Sbecore::uint BOOLEAN = 2;
		const Sbecore::uint TINYINT = 3;
		const Sbecore::uint UTINYINT = 4;
		const Sbecore::uint SMALLINT = 5;
		const Sbecore::uint USMALLINT = 6;
		const Sbecore::uint INT = 7;
		const Sbecore::uint UINT = 8;
		const Sbecore::uint BIGINT = 9;
		const Sbecore::uint UBIGINT = 10;
		const Sbecore::uint FLOAT = 11;
		const Sbecore::uint DOUBLE = 12;
		const Sbecore::uint STRING = 13;
		const Sbecore::uint BOOLEANVEC = 14;
		const Sbecore::uint UTINYINTVEC = 15;
		const Sbecore::uint USMALLINTVEC = 16;
		const Sbecore::uint INTVEC = 17;
		const Sbecore::uint UINTVEC = 18;
		const Sbecore::uint UBIGINTVEC = 19;
		const Sbecore::uint FLOATVEC = 20;
		const Sbecore::uint DOUBLEVEC = 21;
		//const Sbecore::uint FLOATMAT = 22;
		//const Sbecore::uint DOUBLEMAT = 23;
		const Sbecore::uint STRINGVEC = 24;
		const Sbecore::uint VECSREF = 25;
	};

	/**
		* Session
		*/
	class Session : public uasdk::IUserPermissions_t {

	public:
		Sbecore::ubigint jrefM2msess;
		M2msessWzsk::StatShr statshr;

		std::set<Sbecore::uint> jobaccs;
		std::map<Sbecore::featix_t,Sbecore::uint> accs;

	public:
		Session();
		~Session() {};

		bool operator==(const uasdk::IUserPermissions_t& obj) const {UASDK_UNUSED(obj); return true;};

		bool operator!=(const uasdk::IUserPermissions_t& obj) const {UASDK_UNUSED(obj); return false;};

		void Initialise(const std::string& sref, const std::string& Password);

		uasdk::Status_t GetVariableNodeUserAccessLevel(const uasdk::IVariableNode_t& node, uasdk::AccessLevel_t& userAccessLevel) const;

		uasdk::Status_t SetVariableNodeUserAccessLevel(uasdk::IVariableNode_t& node, uasdk::AccessLevel_t userAccessLevel) {return OpcUa_BadNotSupported;};

		uasdk::Status_t GetNodeUserWriteMask(const uasdk::INode_t& node, uasdk::WriteMask_t& userWriteMask) const;

		uasdk::Status_t SetNodeUserWriteMask(const uasdk::INode_t& node, uasdk::WriteMask_t userWriteMask) {return OpcUa_BadNotSupported;};

		uasdk::Status_t GetNodeUserVisibility(const uasdk::INode_t& node, bool& visible) const;

		uasdk::Status_t SetNodeUserVisibility(uasdk::INode_t& node, bool visible) {return OpcUa_BadNotSupported;};

		uasdk::Status_t GetMethodNodeUserExecutable(const uasdk::IMethodNode_t& method, bool& userExecutable) const;

		uasdk::Status_t SetMethodNodeUserExecutable(uasdk::IMethodNode_t& method, bool userExecutable) {return OpcUa_BadNotSupported;};
	};

	/**
		* UserPermissionsProvider
		*/
	class UserPermissionsProvider : public uasdk::IUserPermissionsProvider_t {

	public:
		~UserPermissionsProvider() {};

		uasdk::Status_t GetUserPermissions(const uasdk::NodeId_t& sessionId, const uasdk::String_t& userName, const uasdk::String_t& password, uasdk::IntrusivePtr_t<uasdk::IUserPermissions_t>& userPermissions) const;

		uasdk::Status_t GetUserPermissions(const uasdk::NodeId_t& sessionId, const uasdk::X509IdentityToken_t& userIdentityToken, uasdk::IntrusivePtr_t<uasdk::IUserPermissions_t>& userPermissions) const;

		uasdk::Status_t GetUserPermissions(const uasdk::NodeId_t& sessionId, const uasdk::AnonymousIdentityToken_t& userIdentityToken, uasdk::IntrusivePtr_t<uasdk::IUserPermissions_t>& userPermissions) const;
	};

	/**
		* ServerStateListener
		*/
	class ServerStateListener : public uasdk::IServerStateListener_t {

	public:
		void StateHasChanged(uasdk::ServerState_t::Enum_t state) const;

		void UnhandledError(uasdk::Status_t errorCode) const;
	};

	/**
		* MethodHandler
		*/
	class MethodHandler : public uasdk::INodeMethodHandler_t {

	public:
		~MethodHandler() {};

		uasdk::Status_t CallMethodBegin(uasdk::IntrusivePtr_t<const uasdk::NodeId_t> sessionId, uint32_t transactionId, const uasdk::IUserPermissions_t& userPermissions, uint32_t timeoutHint, uasdk::IntrusivePtr_t<uasdk::INode_t>& componentOf, uasdk::IntrusivePtr_t<uasdk::IMethodNode_t>& method, uasdk::IntrusivePtr_t<const uasdk::CallMethodRequest_t>& requestParameters, uasdk::IntrusivePtr_t<uasdk::CallMethodResult_t>& result, uasdk::IntrusivePtr_t<uasdk::ICallbackCallMethodCompleted_t>& completedCallback);
	};

	/**
		* ValueAttributeReaderWriter
		*/
	class ValueAttributeReaderWriter : public uasdk::INodeValueAttributeReaderWriter_t {

	public:
		ValueAttributeReaderWriter() {};

		bool CanReadValueSynchronously(const uasdk::IVariableNode_t& node) {return true;};

		uasdk::Status_t ReadValueAttributeBegin(uasdk::IntrusivePtr_t<const uasdk::IVariableNode_t>& node, uint32_t maxAge, bool setSourceTimestamp, uasdk::IntrusivePtr_t<const uasdk::ArrayUA_t<uasdk::String_t> >& locales, uasdk::IntrusivePtr_t<const uasdk::ArrayRef_t<uasdk::IndexRange_t> >& indexRange, uint32_t transactionId, uint32_t timeoutHint, uasdk::IntrusivePtr_t<uasdk::ICallbackNodeValueAttributeAccessCompleted_t>& completedCallback) {return OpcUa_BadNotSupported;};

		uasdk::Status_t ReadValueAttribute(const uasdk::IVariableNode_t& node, uint32_t maxAge, bool setSourceTimestamp, const uasdk::ArrayUA_t<uasdk::String_t>& locales, const uasdk::Array_t<uasdk::IndexRange_t>& indexRange, uint32_t transactionId, uint32_t timeoutHint, uasdk::IntrusivePtr_t<uasdk::DataValue_t>& dataValue, uasdk::IntrusivePtr_t<uasdk::DiagnosticInfo_t>& diagnosticInfo);

		bool CanWriteValueSynchronously(const uasdk::IVariableNode_t& node) {return false;};

		uasdk::Status_t WriteValueAttributeBegin(uasdk::IntrusivePtr_t<uasdk::IVariableNode_t>& node, uasdk::IntrusivePtr_t<const uasdk::ArrayRef_t<uasdk::IndexRange_t> > indexRange, uasdk::IntrusivePtr_t<const uasdk::DataValue_t> dataValue, uint32_t transactionId, uint32_t timeoutHint, uasdk::IntrusivePtr_t<uasdk::ICallbackNodeValueAttributeAccessCompleted_t>& completedCallback) {return OpcUa_BadNotSupported;};

		uasdk::Status_t WriteValueAttribute(uasdk::IVariableNode_t& node, const uasdk::Array_t<uasdk::IndexRange_t>& indexRange, uasdk::IntrusivePtr_t<const uasdk::DataValue_t> dataValue, uint32_t transactionId, uint32_t timeoutHint, uasdk::IntrusivePtr_t<uasdk::DiagnosticInfo_t>& diagnosticInfo) {return OpcUa_BadNotSupported;};
	};

	void* run(void* arg);
	void cleanup(void* arg);

	uasdk::IntrusivePtr_t<uasdk::UAServer_t> setupServer(uasdk::Status_t& result);

	uasdk::Status_t fillAddressSpace(uasdk::IntrusivePtr_t<uasdk::INodeMethodHandler_t>& methodHandler, uasdk::IntrusivePtr_t<uasdk::INodeValueAttributeReaderWriter_t>& readerWriter, uasdk::IntrusivePtr_t<uasdk::IAddressSpace_t> addressSpace);
	uasdk::Status_t fAS_addJobFolder(const Sbecore::uint ixWzskVJob, uasdk::IntrusivePtr_t<uasdk::IAddressSpace_t>& addressSpace, uasdk::IntrusivePtr_t<uasdk::IObjectNode_t>& objectsFolder, uasdk::IntrusivePtr_t<uasdk::IObjectNode_t>& jobFolder);

	uasdk::Status_t fAS_addVar(const Sbecore::uint ixWzskVJob, const Sbecore::uint ixWzskVFeatgroup, const std::string& srefIxVVar, uasdk::IntrusivePtr_t<uasdk::INodeValueAttributeReaderWriter_t>& readerWriter, uasdk::IntrusivePtr_t<uasdk::IAddressSpace_t>& addressSpace, uasdk::IntrusivePtr_t<uasdk::IObjectNode_t>& jobFolder, std::vector<std::string>& srefsSubvars, std::vector<Sbecore::uint>& icsVVartypeSubvars);
	uasdk::Status_t fAS_addSubvar(const Sbecore::uint ixVVartype, const uint32_t nref, uasdk::IntrusivePtr_t<uasdk::IAddressSpace_t>& addressSpace, uasdk::IntrusivePtr_t<uasdk::String_t>& browseNameString, uasdk::IntrusivePtr_t<uasdk::BaseDataVariable_t>& subvarObject);

	uasdk::Status_t fAS_addMethod(const Sbecore::uint ixWzskVJob, const Sbecore::uint ixWzskVFeatgroup, const std::string& srefIxVMethod, uasdk::IntrusivePtr_t<uasdk::INodeMethodHandler_t>& methodHandler, uasdk::IntrusivePtr_t<uasdk::IAddressSpace_t>& addressSpace, uasdk::IntrusivePtr_t<uasdk::IObjectNode_t>& jobFolder, std::vector<std::string>& srefsParsInv, std::vector<uint32_t>& opcUaIdsParsInv, std::vector<std::string>& srefsParsRet, std::vector<uint32_t>& opcUaIdsParsRet);

	void runMethod(const Sbecore::ubigint jref, const Sbecore::uint ixWzskVFeatgroup, const std::string& srefIxVMethod, const std::vector<const void*>& parsInv, const std::vector<void*>& parsRet);

	extern XchgWzskcmbd* xchg;
	extern uasdk::IntrusivePtr_t<uasdk::UAServer_t> uaserver;
	extern bool serverHasFailed;
	extern Sbecore::Refseq nrefseq;
	extern std::map<uint32_t,uasdk::IntrusivePtr_t<Session> > sessions;
	extern std::map<Sbecore::ubigint,Sbecore::uint> ixVFeatgroups;
	extern std::map<Sbecore::featix_t,uasdk::DateTime_t> timestamps;
	extern std::map<uint32_t,Sbecore::uint> jobs;
	extern std::map<uint32_t,Sbecore::featix_t> methods;
	extern std::map<uint32_t,Sbecore::featix_t> iasMethods;
	extern std::map<uint32_t,Sbecore::featix_t> oasMethods;
	extern std::map<uint32_t,Sbecore::featix_t> vars;
	extern std::map<uint32_t,Sbecore::featix_t> subvarsVars;
	extern std::map<uint32_t,std::string> subvars;
};

#endif


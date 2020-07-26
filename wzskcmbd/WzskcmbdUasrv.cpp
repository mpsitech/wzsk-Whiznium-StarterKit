/**
	* \file WzskcmbdUasrv.cpp
	* OPC UA server based on Matrikon FLEX OPC UA SDK for Wzsk combined daemon (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "Wzskcmbd.h"

#include "WzskcmbdUasrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace uasdk;

/******************************************************************************
 class WzskcmbdUasrv::Session
 ******************************************************************************/

WzskcmbdUasrv::Session::Session() :
			IUserPermissions_t()
		{
	jrefM2msess = 0;
};

void WzskcmbdUasrv::Session::Initialise(
			const string& sref
			, const string& Password
		) {
	if ((sref == "") || (Password == "")) return;

	ReqWzsk* req = NULL;

	RootWzsk::DpchAppLogin* dpchapplogin = NULL;

	uint ixAcc;

	// - start M2M session
	req = new ReqWzsk(ReqWzsk::VecVBasetype::DPCHAPP, ReqWzsk::VecVState::RECEIVE, "127.0.0.1");

	req->jref = xchg->jrefRoot;

	dpchapplogin = new RootWzsk::DpchAppLogin();
	dpchapplogin->jref = xchg->jrefRoot;
	dpchapplogin->username = sref;
	dpchapplogin->password = Password;
	dpchapplogin->m2mNotReg = true;

	req->dpchapp = dpchapplogin;

	xchg->addReq(req);

	req->cReady.lockMutex("WzskcmbdUasrv::Session", "Initialise[1]");
	if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdUasrv::Session", "Initialise[1]");
	req->cReady.unlockMutex("WzskcmbdUasrv::Session", "Initialise[1]");

	if (req->dpcheng) if (req->dpcheng->ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKCONFIRM) if (((DpchEngWzskConfirm*) (req->dpcheng))->accepted) jrefM2msess = req->dpcheng->jref;

	delete req;

	if (jrefM2msess != 0) {
		// - determine available jobs
		req = new ReqWzsk(ReqWzsk::VecVBasetype::DPCHAPP, ReqWzsk::VecVState::RECEIVE, "127.0.0.1");

		req->jref = jrefM2msess;

		req->dpchapp = new DpchAppWzskInit();
		req->dpchapp->jref = jrefM2msess;

		xchg->addReq(req);

		req->cReady.lockMutex("WzskcmbdUasrv::Session", "Initialise[2]");
		if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdUasrv::Session", "Initialise[2]");
		req->cReady.unlockMutex("WzskcmbdUasrv::Session", "Initialise[2]");

		if (req->dpcheng) if (req->dpcheng->ixWzskVDpch == VecWzskVDpch::DPCHENGM2MSESSWZSKDATA) if (req->dpcheng->has(M2msessWzsk::DpchEngData::STATSHR)) statshr = ((M2msessWzsk::DpchEngData*) (req->dpcheng))->statshr;

		delete req;

		// - probe access rights and add call listeners
		if (statshr.jrefIprtrace != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKIPRTRACE);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setLevel", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setLevel")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setPOn", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setPOn")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoi", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoi")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoiNotFull", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoiNotFull")] = ixAcc;

			ixVFeatgroups[statshr.jrefIprtrace] = VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "pOnLeftPOnRight", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "pOnLeftPOnRight")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprtrace, "pOnLeftPOnRight", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "levelOnLevelOff", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "levelOnLevelOff")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprtrace, "levelOnLevelOff", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprtrace, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "leftRight", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "leftRight")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprtrace, "leftRight", true);
			};
		};
		if (statshr.jrefIprcorner != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKIPRCORNER);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setNTarget", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setNTarget")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoi", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoi")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoiNotFull", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoiNotFull")] = ixAcc;

			ixVFeatgroups[statshr.jrefIprcorner] = VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "NTarget", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "NTarget")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprcorner, "NTarget", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprcorner, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "flg", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "flg")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefIprcorner, "flg", true);
			};
		};
		if (statshr.jrefActservo != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACTSERVO);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "moveto", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "moveto")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "zero", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "zero")] = ixAcc;

			ixVFeatgroups[statshr.jrefActservo] = VecWzskVFeatgroup::VECVJOBWZSKACTSERVOVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOVAR, "angleTarget", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTSERVOVAR, "angleTarget")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefActservo, "angleTarget", true);
			};
		};
		if (statshr.jrefActlaser != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACTLASER);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setLeft", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setLeft")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setRight", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setRight")] = ixAcc;

			ixVFeatgroups[statshr.jrefActlaser] = VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR, "leftRight", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR, "leftRight")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefActlaser, "leftRight", true);
			};
		};
		if (statshr.jrefAcqptcloud != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACQPTCLOUD);

			ixVFeatgroups[statshr.jrefAcqptcloud] = VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqptcloud, VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR, "xYZ", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR, "xYZ")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqptcloud, "xYZ", true);
			};
		};
		if (statshr.jrefAcqpreview != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACQPREVIEW);

			ixVFeatgroups[statshr.jrefAcqpreview] = VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqpreview, VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR, "gray", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR, "gray")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqpreview, "gray", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqpreview, VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR, "redGreenBlue", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR, "redGreenBlue")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqpreview, "redGreenBlue", true);
			};
		};
	};
};

Status_t WzskcmbdUasrv::Session::GetVariableNodeUserAccessLevel(
			const IVariableNode_t& node
			, AccessLevel_t& userAccessLevel
		) const {
	auto it = subvarsVars.find(node.NodeId()->Hash());

	if (it != subvarsVars.end()) {
		auto it2 = accs.find(it->second);

		if (it2 != accs.end()) {
			userAccessLevel = AccessLevel_t();
			userAccessLevel.CurrentRead(true);

			return OpcUa_Good;
		};
	};

	return OpcUa_BadNodeNotInView;
};

Status_t WzskcmbdUasrv::Session::GetNodeUserWriteMask(
			const INode_t& node
			, WriteMask_t& userWriteMask
		) const {
	userWriteMask = WriteMask_t();

	return OpcUa_Good;
};

Status_t WzskcmbdUasrv::Session::GetNodeUserVisibility(
			const INode_t& node
			, bool& visible
		) const {
	if (node.NodeId()->NamespaceIndex() == 0) {
		visible = true;

	} else {
		visible = false;

		auto it = jobs.find(node.NodeId()->Hash());
		if (it != jobs.end()) {
			auto it2 = jobaccs.find(it->second);
			visible = (it2 != jobaccs.end());
		} else {
			auto it2 = methods.find(node.NodeId()->Hash());
			if (it2 != methods.end()) {
				auto it3 = accs.find(it2->second);
				visible = (it3 != accs.end());
			} else {
				auto it3 = iasMethods.find(node.NodeId()->Hash());
				if (it3 != iasMethods.end()) {
					auto it4 = accs.find(it3->second);
					visible = (it4 != accs.end());
				} else {
					auto it4 = oasMethods.find(node.NodeId()->Hash());
					if (it4 != oasMethods.end()) {
						auto it5 = accs.find(it4->second);
						visible = (it5 != accs.end());
					} else {
						auto it5 = vars.find(node.NodeId()->Hash());
						if (it5 != vars.end()) {
							auto it6 = accs.find(it5->second);
							visible = (it6 != accs.end());
						} else {
							auto it6 = subvarsVars.find(node.NodeId()->Hash());
							if (it6 != subvarsVars.end()) {
								auto it7 = accs.find(it6->second);
								visible = (it7 != accs.end());
							};
						};
					};
				};
			};
		};
	};

	return OpcUa_Good;
};

Status_t WzskcmbdUasrv::Session::GetMethodNodeUserExecutable(
			const IMethodNode_t& method
			, bool& userExecutable
		) const {
	userExecutable = false;

	auto it = methods.find(method.NodeId()->Hash());

	if (it != methods.end()) {
		auto it2 = accs.find(it->second);
		if (it2 != accs.end()) userExecutable = ((it2->second & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC);
	};

	return OpcUa_Good;
};

/******************************************************************************
 class WzskcmbdUasrv::UserPermissionsProvider
 ******************************************************************************/

Status_t WzskcmbdUasrv::UserPermissionsProvider::GetUserPermissions(
			const NodeId_t& sessionId
			, const String_t& userName
			, const String_t& password
			, IntrusivePtr_t<IUserPermissions_t>& userPermissions
		) const {
	auto it = sessions.find(sessionId.Hash());

	if (it != sessions.end()) {
		userPermissions = it->second;
	} else {
		IntrusivePtr_t<Session> sess = new SafeRefCount_t<Session>();
		sess->Initialise(string((char*) userName.Payload().Data(), userName.Length()), string((char*) password.Payload().Data(), password.Length()));

		userPermissions = sess;

		if (sess->jrefM2msess != 0) sessions[sessionId.Hash()] = sess.get();
	};

	return OpcUa_Good;
};

Status_t WzskcmbdUasrv::UserPermissionsProvider::GetUserPermissions(
			const NodeId_t& sessionId
			, const X509IdentityToken_t& userIdentityToken
			, IntrusivePtr_t<IUserPermissions_t>& userPermissions
		) const {
	userPermissions = new SafeRefCount_t<Session>();
	return OpcUa_Good;
};

Status_t WzskcmbdUasrv::UserPermissionsProvider::GetUserPermissions(
			const NodeId_t& sessionId
			, const AnonymousIdentityToken_t& userIdentityToken
			, IntrusivePtr_t<IUserPermissions_t>& userPermissions
		) const {
	userPermissions = new SafeRefCount_t<Session>();
	return OpcUa_Good;
};

/******************************************************************************
 class WzskcmbdUasrv::ServerStateListener
 ******************************************************************************/

void WzskcmbdUasrv::ServerStateListener::StateHasChanged(
			ServerState_t::Enum_t state
		) const {
	if (state == ServerState_t::OPCUA_SERVER_STATE_FAILED) serverHasFailed = true;
};

void WzskcmbdUasrv::ServerStateListener::UnhandledError(
			Status_t errorCode
		) const {
	if (errorCode != OpcUa_Good) cout << "bad status code " << std::hex << errorCode.Value() << " not handled by OPC UA server" << endl;
};

/******************************************************************************
 class WzskcmbdUasrv::MethodHandler
 ******************************************************************************/

Status_t WzskcmbdUasrv::MethodHandler::CallMethodBegin(
			IntrusivePtr_t<const NodeId_t> sessionId
			, uint32_t transactionId
			, const IUserPermissions_t& userPermissions
			, uint32_t timeoutHint
			, IntrusivePtr_t<INode_t>& componentOf
			, IntrusivePtr_t<IMethodNode_t>& method
			, IntrusivePtr_t<const CallMethodRequest_t>& requestParameters
			, IntrusivePtr_t<CallMethodResult_t>& result
			, IntrusivePtr_t<ICallbackCallMethodCompleted_t>& completedCallback
		) {
	UASDK_RETURN_INVALID_ARGUMENT_IF_NULL(method)

	if (!requestParameters.is_set()) UASDK_RETURN_BAD_STATUS(OpcUa_BadArgumentsMissing);

	uint ixWzskVFeatgroup = 0;
	string srefIxVMethod;

	IntrusivePtr_t<Session> session;
	ubigint jref = 0;

	// identify method
	auto it = methods.find(method->NodeId()->Hash());
	if (it != methods.end()) {
		ixWzskVFeatgroup = it->second.ixVFeatgroup;
		srefIxVMethod = it->second.srefIxVFeature;
	} else {
		return OpcUa_BadMethodInvalid;
	};

	// find session
	auto it2 = sessions.find(sessionId->Hash());
	if (it2 != sessions.end()) {
		session = it2->second;

		if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD) jref = session->statshr.jrefIprtrace;
		else if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD) jref = session->statshr.jrefIprcorner;
		else if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD) jref = session->statshr.jrefActservo;
		else if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD) jref = session->statshr.jrefActlaser;
	} else {
		return OpcUa_BadSessionIdInvalid;
	};

	if (jref != 0) {
		if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD) && (srefIxVMethod == "setLevel")) {
			if (requestParameters->InputArguments().Size() == 2) {
				IntrusivePtr_t<const Byte_t> levelOn_inv_UA;
				utinyint levelOn_inv;
				IntrusivePtr_t<const Byte_t> levelOff_inv_UA;
				utinyint levelOff_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), levelOn_inv_UA);
				levelOn_inv = levelOn_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[1]), levelOff_inv_UA);
				levelOff_inv = levelOff_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setLevel",
							{&levelOn_inv,&levelOff_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD) && (srefIxVMethod == "setPOn")) {
			if (requestParameters->InputArguments().Size() == 2) {
				IntrusivePtr_t<const Float_t> pOnLeft_inv_UA;
				float pOnLeft_inv;
				IntrusivePtr_t<const Float_t> pOnRight_inv_UA;
				float pOnRight_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), pOnLeft_inv_UA);
				pOnLeft_inv = pOnLeft_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[1]), pOnRight_inv_UA);
				pOnRight_inv = pOnRight_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setPOn",
							{&pOnLeft_inv,&pOnRight_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD) && (srefIxVMethod == "setRoi")) {
			if (requestParameters->InputArguments().Size() == 8) {
				IntrusivePtr_t<const Int32_t> roiAx_inv_UA;
				int roiAx_inv;
				IntrusivePtr_t<const Int32_t> roiAy_inv_UA;
				int roiAy_inv;
				IntrusivePtr_t<const Int32_t> roiBx_inv_UA;
				int roiBx_inv;
				IntrusivePtr_t<const Int32_t> roiBy_inv_UA;
				int roiBy_inv;
				IntrusivePtr_t<const Int32_t> roiCx_inv_UA;
				int roiCx_inv;
				IntrusivePtr_t<const Int32_t> roiCy_inv_UA;
				int roiCy_inv;
				IntrusivePtr_t<const Int32_t> roiDx_inv_UA;
				int roiDx_inv;
				IntrusivePtr_t<const Int32_t> roiDy_inv_UA;
				int roiDy_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), roiAx_inv_UA);
				roiAx_inv = roiAx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[1]), roiAy_inv_UA);
				roiAy_inv = roiAy_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[2]), roiBx_inv_UA);
				roiBx_inv = roiBx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[3]), roiBy_inv_UA);
				roiBy_inv = roiBy_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[4]), roiCx_inv_UA);
				roiCx_inv = roiCx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[5]), roiCy_inv_UA);
				roiCy_inv = roiCy_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[6]), roiDx_inv_UA);
				roiDx_inv = roiDx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[7]), roiDy_inv_UA);
				roiDy_inv = roiDy_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoi",
							{&roiAx_inv,&roiAy_inv,&roiBx_inv,&roiBy_inv,&roiCx_inv,&roiCy_inv,&roiDx_inv,&roiDy_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD) && (srefIxVMethod == "setRoiNotFull")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Boolean_t> roiNotFull_inv_UA;
				bool roiNotFull_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), roiNotFull_inv_UA);
				roiNotFull_inv = roiNotFull_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoiNotFull",
							{&roiNotFull_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD) && (srefIxVMethod == "setNTarget")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const UInt32_t> NTarget_inv_UA;
				uint NTarget_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), NTarget_inv_UA);
				NTarget_inv = NTarget_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setNTarget",
							{&NTarget_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD) && (srefIxVMethod == "setRoi")) {
			if (requestParameters->InputArguments().Size() == 8) {
				IntrusivePtr_t<const Int32_t> roiAx_inv_UA;
				int roiAx_inv;
				IntrusivePtr_t<const Int32_t> roiAy_inv_UA;
				int roiAy_inv;
				IntrusivePtr_t<const Int32_t> roiBx_inv_UA;
				int roiBx_inv;
				IntrusivePtr_t<const Int32_t> roiBy_inv_UA;
				int roiBy_inv;
				IntrusivePtr_t<const Int32_t> roiCx_inv_UA;
				int roiCx_inv;
				IntrusivePtr_t<const Int32_t> roiCy_inv_UA;
				int roiCy_inv;
				IntrusivePtr_t<const Int32_t> roiDx_inv_UA;
				int roiDx_inv;
				IntrusivePtr_t<const Int32_t> roiDy_inv_UA;
				int roiDy_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), roiAx_inv_UA);
				roiAx_inv = roiAx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[1]), roiAy_inv_UA);
				roiAy_inv = roiAy_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[2]), roiBx_inv_UA);
				roiBx_inv = roiBx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[3]), roiBy_inv_UA);
				roiBy_inv = roiBy_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[4]), roiCx_inv_UA);
				roiCx_inv = roiCx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[5]), roiCy_inv_UA);
				roiCy_inv = roiCy_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[6]), roiDx_inv_UA);
				roiDx_inv = roiDx_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[7]), roiDy_inv_UA);
				roiDy_inv = roiDy_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoi",
							{&roiAx_inv,&roiAy_inv,&roiBx_inv,&roiBy_inv,&roiCx_inv,&roiCy_inv,&roiDx_inv,&roiDy_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD) && (srefIxVMethod == "setRoiNotFull")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Boolean_t> roiNotFull_inv_UA;
				bool roiNotFull_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), roiNotFull_inv_UA);
				roiNotFull_inv = roiNotFull_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoiNotFull",
							{&roiNotFull_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD) && (srefIxVMethod == "moveto")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Float_t> target_inv_UA;
				float target_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), target_inv_UA);
				target_inv = target_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "moveto",
							{&target_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD) && (srefIxVMethod == "zero")) {
			if (requestParameters->InputArguments().Size() == 0) {
				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "zero",
							{},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD) && (srefIxVMethod == "setLeft")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Float_t> left_inv_UA;
				float left_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), left_inv_UA);
				left_inv = left_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setLeft",
							{&left_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD) && (srefIxVMethod == "setRight")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Float_t> right_inv_UA;
				float right_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), right_inv_UA);
				right_inv = right_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setRight",
							{&right_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};
		};

	} else {
		return OpcUa_BadInternalError;
	};

	return completedCallback->CallMethodCompleted(result);
};

/******************************************************************************
 class WzskcmbdUasrv::ValueAttributeReaderWriter
 ******************************************************************************/

Status_t WzskcmbdUasrv::ValueAttributeReaderWriter::ReadValueAttribute(
			const IVariableNode_t& node
			, uint32_t maxAge
			, bool setSourceTimestamp
			, const ArrayUA_t<String_t>& locales
			, const Array_t<IndexRange_t>& indexRange
			, uint32_t transactionId
			, uint32_t timeoutHint
			, IntrusivePtr_t<DataValue_t>& dataValue
			, IntrusivePtr_t<DiagnosticInfo_t>& diagnosticInfo
		) {
	uint ixWzskVFeatgroup = 0;
	string srefIxVVar;
	string subvar;

	// identify variable
	auto it = subvarsVars.find(node.NodeId()->Hash());
	if (it != subvarsVars.end()) {
		ixWzskVFeatgroup = it->second.ixVFeatgroup;
		srefIxVVar = it->second.srefIxVFeature;
	};

	auto it2 = subvars.find(node.NodeId()->Hash());
	if (it2 != subvars.end()) subvar = it2->second;

	if ((ixWzskVFeatgroup != 0) && (srefIxVVar != "") && (subvar != "")) {
		dataValue = new SafeRefCount_t<DataValue_t>();
		dataValue->StatusCode() = new SafeRefCount_t<StatusCode_t>();
		*dataValue->StatusCode() = OpcUa_Good;

		if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR) && (srefIxVVar == "pOnLeftPOnRight")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "pOnLeft") {
				IntrusivePtr_t<Float_t> pOnLeft = new SafeRefCount_t<Float_t>();
				*pOnLeft = JobWzskIprTrace::shrdat.pOnLeft;
				dataValue->Value() = pOnLeft;
			} else if (subvar == "pOnRight") {
				IntrusivePtr_t<Float_t> pOnRight = new SafeRefCount_t<Float_t>();
				*pOnRight = JobWzskIprTrace::shrdat.pOnRight;
				dataValue->Value() = pOnRight;
			};

			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR) && (srefIxVVar == "levelOnLevelOff")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "levelOn") {
				IntrusivePtr_t<Byte_t> levelOn = new SafeRefCount_t<Byte_t>();
				*levelOn = JobWzskIprTrace::shrdat.levelOn;
				dataValue->Value() = levelOn;
			} else if (subvar == "levelOff") {
				IntrusivePtr_t<Byte_t> levelOff = new SafeRefCount_t<Byte_t>();
				*levelOff = JobWzskIprTrace::shrdat.levelOff;
				dataValue->Value() = levelOff;
			};

			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR) && (srefIxVVar == "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "roiAx") {
				IntrusivePtr_t<Int32_t> roiAx = new SafeRefCount_t<Int32_t>();
				*roiAx = JobWzskIprTrace::shrdat.roiAx;
				dataValue->Value() = roiAx;
			} else if (subvar == "roiAy") {
				IntrusivePtr_t<Int32_t> roiAy = new SafeRefCount_t<Int32_t>();
				*roiAy = JobWzskIprTrace::shrdat.roiAy;
				dataValue->Value() = roiAy;
			} else if (subvar == "roiBx") {
				IntrusivePtr_t<Int32_t> roiBx = new SafeRefCount_t<Int32_t>();
				*roiBx = JobWzskIprTrace::shrdat.roiBx;
				dataValue->Value() = roiBx;
			} else if (subvar == "roiBy") {
				IntrusivePtr_t<Int32_t> roiBy = new SafeRefCount_t<Int32_t>();
				*roiBy = JobWzskIprTrace::shrdat.roiBy;
				dataValue->Value() = roiBy;
			} else if (subvar == "roiCx") {
				IntrusivePtr_t<Int32_t> roiCx = new SafeRefCount_t<Int32_t>();
				*roiCx = JobWzskIprTrace::shrdat.roiCx;
				dataValue->Value() = roiCx;
			} else if (subvar == "roiCy") {
				IntrusivePtr_t<Int32_t> roiCy = new SafeRefCount_t<Int32_t>();
				*roiCy = JobWzskIprTrace::shrdat.roiCy;
				dataValue->Value() = roiCy;
			} else if (subvar == "roiDx") {
				IntrusivePtr_t<Int32_t> roiDx = new SafeRefCount_t<Int32_t>();
				*roiDx = JobWzskIprTrace::shrdat.roiDx;
				dataValue->Value() = roiDx;
			} else if (subvar == "roiDy") {
				IntrusivePtr_t<Int32_t> roiDy = new SafeRefCount_t<Int32_t>();
				*roiDy = JobWzskIprTrace::shrdat.roiDy;
				dataValue->Value() = roiDy;
			};

			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR) && (srefIxVVar == "leftRight")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "left") {
				unsigned int len = JobWzskIprTrace::shrdat.left.size();
				IntrusivePtr_t<ArrayUA_t<Boolean_t> > left = new SafeRefCount_t<ArrayUA_t<Boolean_t> >();
				left->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Boolean_t> item = new SafeRefCount_t<Boolean_t>();
					item->Value(JobWzskIprTrace::shrdat.left[i]);
					(*left)[i] = item;
				};
				dataValue->Value() = left;
			} else if (subvar == "right") {
				unsigned int len = JobWzskIprTrace::shrdat.right.size();
				IntrusivePtr_t<ArrayUA_t<Boolean_t> > right = new SafeRefCount_t<ArrayUA_t<Boolean_t> >();
				right->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Boolean_t> item = new SafeRefCount_t<Boolean_t>();
					item->Value(JobWzskIprTrace::shrdat.right[i]);
					(*right)[i] = item;
				};
				dataValue->Value() = right;
			};

			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR) && (srefIxVVar == "NTarget")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "NTarget") {
				IntrusivePtr_t<UInt32_t> NTarget = new SafeRefCount_t<UInt32_t>();
				*NTarget = JobWzskIprCorner::shrdat.NTarget;
				dataValue->Value() = NTarget;
			};

			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR) && (srefIxVVar == "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "roiAx") {
				IntrusivePtr_t<Int32_t> roiAx = new SafeRefCount_t<Int32_t>();
				*roiAx = JobWzskIprCorner::shrdat.roiAx;
				dataValue->Value() = roiAx;
			} else if (subvar == "roiAy") {
				IntrusivePtr_t<Int32_t> roiAy = new SafeRefCount_t<Int32_t>();
				*roiAy = JobWzskIprCorner::shrdat.roiAy;
				dataValue->Value() = roiAy;
			} else if (subvar == "roiBx") {
				IntrusivePtr_t<Int32_t> roiBx = new SafeRefCount_t<Int32_t>();
				*roiBx = JobWzskIprCorner::shrdat.roiBx;
				dataValue->Value() = roiBx;
			} else if (subvar == "roiBy") {
				IntrusivePtr_t<Int32_t> roiBy = new SafeRefCount_t<Int32_t>();
				*roiBy = JobWzskIprCorner::shrdat.roiBy;
				dataValue->Value() = roiBy;
			} else if (subvar == "roiCx") {
				IntrusivePtr_t<Int32_t> roiCx = new SafeRefCount_t<Int32_t>();
				*roiCx = JobWzskIprCorner::shrdat.roiCx;
				dataValue->Value() = roiCx;
			} else if (subvar == "roiCy") {
				IntrusivePtr_t<Int32_t> roiCy = new SafeRefCount_t<Int32_t>();
				*roiCy = JobWzskIprCorner::shrdat.roiCy;
				dataValue->Value() = roiCy;
			} else if (subvar == "roiDx") {
				IntrusivePtr_t<Int32_t> roiDx = new SafeRefCount_t<Int32_t>();
				*roiDx = JobWzskIprCorner::shrdat.roiDx;
				dataValue->Value() = roiDx;
			} else if (subvar == "roiDy") {
				IntrusivePtr_t<Int32_t> roiDy = new SafeRefCount_t<Int32_t>();
				*roiDy = JobWzskIprCorner::shrdat.roiDy;
				dataValue->Value() = roiDy;
			};

			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR) && (srefIxVVar == "flg")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "flg") {
				unsigned int len = JobWzskIprCorner::shrdat.flg.size();
				IntrusivePtr_t<ArrayUA_t<Boolean_t> > flg = new SafeRefCount_t<ArrayUA_t<Boolean_t> >();
				flg->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Boolean_t> item = new SafeRefCount_t<Boolean_t>();
					item->Value(JobWzskIprCorner::shrdat.flg[i]);
					(*flg)[i] = item;
				};
				dataValue->Value() = flg;
			};

			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTSERVOVAR) && (srefIxVVar == "angleTarget")) {
			JobWzskActServo::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "angle") {
				IntrusivePtr_t<Float_t> angle = new SafeRefCount_t<Float_t>();
				*angle = JobWzskActServo::shrdat.angle;
				dataValue->Value() = angle;
			} else if (subvar == "target") {
				IntrusivePtr_t<Float_t> target = new SafeRefCount_t<Float_t>();
				*target = JobWzskActServo::shrdat.target;
				dataValue->Value() = target;
			};

			JobWzskActServo::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR) && (srefIxVVar == "leftRight")) {
			JobWzskActLaser::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "left") {
				IntrusivePtr_t<Float_t> left = new SafeRefCount_t<Float_t>();
				*left = JobWzskActLaser::shrdat.left;
				dataValue->Value() = left;
			} else if (subvar == "right") {
				IntrusivePtr_t<Float_t> right = new SafeRefCount_t<Float_t>();
				*right = JobWzskActLaser::shrdat.right;
				dataValue->Value() = right;
			};

			JobWzskActLaser::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR) && (srefIxVVar == "xYZ")) {
			JobWzskAcqPtcloud::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "x") {
				unsigned int len = JobWzskAcqPtcloud::shrdat.x.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > x = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				x->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskAcqPtcloud::shrdat.x[i]);
					(*x)[i] = item;
				};
				dataValue->Value() = x;
			} else if (subvar == "y") {
				unsigned int len = JobWzskAcqPtcloud::shrdat.y.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > y = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				y->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskAcqPtcloud::shrdat.y[i]);
					(*y)[i] = item;
				};
				dataValue->Value() = y;
			} else if (subvar == "z") {
				unsigned int len = JobWzskAcqPtcloud::shrdat.z.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > z = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				z->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskAcqPtcloud::shrdat.z[i]);
					(*z)[i] = item;
				};
				dataValue->Value() = z;
			};

			JobWzskAcqPtcloud::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR) && (srefIxVVar == "gray")) {
			JobWzskAcqPreview::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "gray") {
				unsigned int len = JobWzskAcqPreview::shrdat.gray.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > gray = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				gray->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Byte_t> item = new SafeRefCount_t<Byte_t>();
					item->Value(JobWzskAcqPreview::shrdat.gray[i]);
					(*gray)[i] = item;
				};
				dataValue->Value() = gray;
			};

			JobWzskAcqPreview::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR) && (srefIxVVar == "redGreenBlue")) {
			JobWzskAcqPreview::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "red") {
				unsigned int len = JobWzskAcqPreview::shrdat.red.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > red = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				red->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Byte_t> item = new SafeRefCount_t<Byte_t>();
					item->Value(JobWzskAcqPreview::shrdat.red[i]);
					(*red)[i] = item;
				};
				dataValue->Value() = red;
			} else if (subvar == "green") {
				unsigned int len = JobWzskAcqPreview::shrdat.green.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > green = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				green->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Byte_t> item = new SafeRefCount_t<Byte_t>();
					item->Value(JobWzskAcqPreview::shrdat.green[i]);
					(*green)[i] = item;
				};
				dataValue->Value() = green;
			} else if (subvar == "blue") {
				unsigned int len = JobWzskAcqPreview::shrdat.blue.size();
				IntrusivePtr_t<ArrayUA_t<Byte_t> > blue = new SafeRefCount_t<ArrayUA_t<Byte_t> >();
				blue->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Byte_t> item = new SafeRefCount_t<Byte_t>();
					item->Value(JobWzskAcqPreview::shrdat.blue[i]);
					(*blue)[i] = item;
				};
				dataValue->Value() = blue;
			};

			JobWzskAcqPreview::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");
		};
	};

	return OpcUa_Good;
};

/******************************************************************************
 namespace WzskcmbdUasrv
 ******************************************************************************/

void* WzskcmbdUasrv::run(
			void* arg
		) {
	xchg = (XchgWzskcmbd*) arg;

	Status_t status;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	uaserver = setupServer(status);
	if (status.IsBad()) return NULL;

	IntrusivePtr_t<IServerConfiguration_t> config = uaserver->GetConfiguration(status);
	if (status.IsBad()) return NULL;

	IntrusivePtr_t<INodeMethodHandler_t> methodHandler = new SafeRefCount_t<MethodHandler>();
	IntrusivePtr_t<INodeValueAttributeReaderWriter_t> readerWriter = new SafeRefCount_t<ValueAttributeReaderWriter>();

	status = fillAddressSpace(methodHandler, readerWriter, config->AddressSpace());
	if (status.IsBad()) return NULL;

	String_t dummy;
	uaserver->Start(dummy);

	xchg->cStable.signal("WzskcmbdUasrv", "run");

	while (true) {
		uaserver->Poll();

		xchg->cUasrv.lockMutex("WzskcmbdUasrv", "run");
		if (xchg->uasrvcall) {
			auto it = ixVFeatgroups.find(xchg->uasrvcall->jref);
			if (it != ixVFeatgroups.end()) timestamps[featix_t(it->second, xchg->uasrvcall->argInv.sref)] = UASDK_datetime();

			xchg->uasrvcall = NULL;

			xchg->cUasrv.unlockMutex("WzskcmbdUasrv", "run[1]");

			xchg->cUasrv.signal("WzskcmbdUasrv", "run");

		} else xchg->cUasrv.unlockMutex("WzskcmbdUasrv", "run[2]");
	};

	pthread_cleanup_pop(0);

	return NULL;
};

void WzskcmbdUasrv::cleanup(
			void* arg
		) {
	XchgWzskcmbd* xchg = (XchgWzskcmbd*) arg;

	xchg->cUasrv.unlockMutex("WzskcmbdUasrv", "cleanup");

	if (uaserver.is_set()) {
		uaserver->Stop();
		uaserver->Terminate();
	};
};

IntrusivePtr_t<UAServer_t> WzskcmbdUasrv::setupServer(
			Status_t& result
		) {
	IntrusivePtr_t<UAServer_t> uaserver;

	// populate the address space with the help of nodeset file
	IntrusivePtr_t<IAddressSpace_t> addressSpace;

	if (!addressSpace.is_set()) {
		addressSpace = UAServer_t::CreateAddressSpace(9973, result);

		if (!addressSpace.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		IntrusivePtr_t<IXmlNodesetIO_t> xmlParser = UAServer_t::CreateXmlNodesetIO(true, result);
		if (!xmlParser.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		IntrusivePtr_t<StdFile_t> nodesetFile = new SafeRefCount_t<StdFile_t>();
		if (!nodesetFile.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		IntrusivePtr_t<String_t> filename = new SafeRefCount_t<String_t>();
		if (!filename.is_set()) {
			result = OpcUa_BadOutOfMemory;
			return uaserver;
		};

		result = filename->CopyFrom(xchg->stgwzskuasrv.profile.c_str());
		if (result.IsBad()) return uaserver;

		result = nodesetFile->Initialise(false, filename);
		if (result.IsBad()) return uaserver;

		result = xmlParser->Import(*nodesetFile, *addressSpace);
		if (result.IsBad()) return uaserver;
	};

	// create and configure server

	// get the unique application URI from the Server Array in the address space (was imported from the nodeset file)
	NodeIdNumeric_t serverArrayNodeId;
	serverArrayNodeId.NamespaceIndex() = 0;
	serverArrayNodeId.Identifer() = OpcUaId_Server_ServerArray;
	IntrusivePtr_t<IVariableNode_t> serverArrayNode = addressSpace->FindVariableNode(serverArrayNodeId, result);

	if (!serverArrayNode.is_set()) {
		result = OpcUa_BadConfigurationError;
		return uaserver;
	};

	IntrusivePtr_t<const DataValue_t> serverArrayValue = serverArrayNode->Value();
	if (!serverArrayValue.is_set() || !serverArrayValue->Value().is_set()) {
		result = OpcUa_BadConfigurationError;
		return uaserver;
	};

	IntrusivePtr_t<const ArrayUA_t<String_t> > serverArray = RuntimeCast<const ArrayUA_t<String_t>*>(*serverArrayValue->Value());
	if (!serverArray.is_set() || (serverArray->Count() < 1) || !(*serverArray)[0].is_set()) {
		result = OpcUa_BadConfigurationError;
		return uaserver;
	};

	IntrusivePtr_t<String_t> applicationURI = new SafeRefCount_t<String_t>();
	if (!applicationURI.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = applicationURI->CopyFrom(*(*serverArray)[0]);
	if (result.IsBad()) return uaserver;

	IntrusivePtr_t<BuildInfo_t> buildInfo = new SafeRefCount_t<BuildInfo_t>();
	if (!buildInfo.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = buildInfo->ProductName().CopyFrom("Whiznium StarterKit");
	if (result.IsBad()) return uaserver;

	result = buildInfo->ProductUri().CopyFrom("http://www.mpsitech.com/wzsk");
	if (result.IsBad()) return uaserver;

	IntrusivePtr_t<IServerConfiguration_t> configuration = UAServer_t::CreateConfiguration(result);
	if (!configuration.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = configuration->AddEndpointUserTokenPolicy(SECURITY_POLICY_NONE, MessageSecurityMode_t::OPCUA_MESSAGE_SECURITY_MODE_NONE, UserIdentityTokenType_t::OPCUA_USER_IDENTITY_TOKEN_TYPE_USERNAME, SECURITY_POLICY_NONE);
	if (result.IsBad()) return uaserver;

	IntrusivePtr_t<const IUserPermissionsProvider_t> userPermissionsProvider = new SafeRefCount_t<UserPermissionsProvider>();
	if (!userPermissionsProvider.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	IntrusivePtr_t<IServerStateListener_t> serverStateListener = new SafeRefCount_t<ServerStateListener>();
	if (!serverStateListener.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	configuration->ServerStateListener(serverStateListener);
	configuration->UserPermissionsProvider(userPermissionsProvider);
	configuration->ApplicationURI(applicationURI);
	configuration->BuildInfo(buildInfo);
	configuration->ServerEndpointTCPPort(xchg->stgwzskuasrv.port);
	configuration->ServerCyclicRateInMs(xchg->stgwzskuasrv.cycle);
	configuration->MaxBrowseRefsPerNode(xchg->stgwzskuasrv.maxbrowse);
	configuration->MaxMonitoredItems(xchg->stgwzskuasrv.maxmon);
	configuration->AddressSpace(addressSpace);

	// create the server instance
	uaserver = new SafeRefCount_t<UAServer_t>();
	if (!uaserver.is_set()) {
		result = OpcUa_BadOutOfMemory;
		return uaserver;
	};

	result = uaserver->Initialise(configuration);
	return uaserver;
};

Status_t WzskcmbdUasrv::fillAddressSpace(
			IntrusivePtr_t<INodeMethodHandler_t>& methodHandler
			, IntrusivePtr_t<INodeValueAttributeReaderWriter_t>& readerWriter
			, IntrusivePtr_t<IAddressSpace_t> addressSpace
		) {
	Status_t status;

	NodeIdNumeric_t targetId(0, OpcUaId_ObjectsFolder);
	IntrusivePtr_t<IObjectNode_t> objectsFolder = addressSpace->FindObjectNode(targetId, status);

	IntrusivePtr_t<IObjectNode_t> jobFolder;

	vector<string> srefsParsInv;
	vector<uint32_t> opcUaIdsParsInv;
	vector<string> srefsParsRet;
	vector<uint32_t> opcUaIdsParsRet;

	vector<string> srefsSubvars;
	vector<uint> icsVVartypeSubvars;

	fAS_addJobFolder(VecWzskVJob::JOBWZSKIPRTRACE, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(2); opcUaIdsParsInv.resize(2);
	srefsParsInv[0] = "levelOn"; opcUaIdsParsInv[0] = OpcUaId_Byte;
	srefsParsInv[1] = "levelOff"; opcUaIdsParsInv[1] = OpcUaId_Byte;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD , "setLevel", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(2); opcUaIdsParsInv.resize(2);
	srefsParsInv[0] = "pOnLeft"; opcUaIdsParsInv[0] = OpcUaId_Float;
	srefsParsInv[1] = "pOnRight"; opcUaIdsParsInv[1] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD , "setPOn", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(8); opcUaIdsParsInv.resize(8);
	srefsParsInv[0] = "roiAx"; opcUaIdsParsInv[0] = OpcUaId_Int32;
	srefsParsInv[1] = "roiAy"; opcUaIdsParsInv[1] = OpcUaId_Int32;
	srefsParsInv[2] = "roiBx"; opcUaIdsParsInv[2] = OpcUaId_Int32;
	srefsParsInv[3] = "roiBy"; opcUaIdsParsInv[3] = OpcUaId_Int32;
	srefsParsInv[4] = "roiCx"; opcUaIdsParsInv[4] = OpcUaId_Int32;
	srefsParsInv[5] = "roiCy"; opcUaIdsParsInv[5] = OpcUaId_Int32;
	srefsParsInv[6] = "roiDx"; opcUaIdsParsInv[6] = OpcUaId_Int32;
	srefsParsInv[7] = "roiDy"; opcUaIdsParsInv[7] = OpcUaId_Int32;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD , "setRoi", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "roiNotFull"; opcUaIdsParsInv[0] = OpcUaId_Boolean;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD , "setRoiNotFull", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "pOnLeft"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "pOnRight"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR , "pOnLeftPOnRight", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "levelOn"; icsVVartypeSubvars[0] = VecVVartype::UTINYINT;
	srefsSubvars[1] = "levelOff"; icsVVartypeSubvars[1] = VecVVartype::UTINYINT;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR , "levelOnLevelOff", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(8); icsVVartypeSubvars.resize(8);
	srefsSubvars[0] = "roiAx"; icsVVartypeSubvars[0] = VecVVartype::INT;
	srefsSubvars[1] = "roiAy"; icsVVartypeSubvars[1] = VecVVartype::INT;
	srefsSubvars[2] = "roiBx"; icsVVartypeSubvars[2] = VecVVartype::INT;
	srefsSubvars[3] = "roiBy"; icsVVartypeSubvars[3] = VecVVartype::INT;
	srefsSubvars[4] = "roiCx"; icsVVartypeSubvars[4] = VecVVartype::INT;
	srefsSubvars[5] = "roiCy"; icsVVartypeSubvars[5] = VecVVartype::INT;
	srefsSubvars[6] = "roiDx"; icsVVartypeSubvars[6] = VecVVartype::INT;
	srefsSubvars[7] = "roiDy"; icsVVartypeSubvars[7] = VecVVartype::INT;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR , "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "left"; icsVVartypeSubvars[0] = VecVVartype::BOOLEANVEC;
	srefsSubvars[1] = "right"; icsVVartypeSubvars[1] = VecVVartype::BOOLEANVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRTRACE, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR , "leftRight", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKIPRCORNER, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "NTarget"; opcUaIdsParsInv[0] = OpcUaId_UInt32;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRCORNER, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD , "setNTarget", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(8); opcUaIdsParsInv.resize(8);
	srefsParsInv[0] = "roiAx"; opcUaIdsParsInv[0] = OpcUaId_Int32;
	srefsParsInv[1] = "roiAy"; opcUaIdsParsInv[1] = OpcUaId_Int32;
	srefsParsInv[2] = "roiBx"; opcUaIdsParsInv[2] = OpcUaId_Int32;
	srefsParsInv[3] = "roiBy"; opcUaIdsParsInv[3] = OpcUaId_Int32;
	srefsParsInv[4] = "roiCx"; opcUaIdsParsInv[4] = OpcUaId_Int32;
	srefsParsInv[5] = "roiCy"; opcUaIdsParsInv[5] = OpcUaId_Int32;
	srefsParsInv[6] = "roiDx"; opcUaIdsParsInv[6] = OpcUaId_Int32;
	srefsParsInv[7] = "roiDy"; opcUaIdsParsInv[7] = OpcUaId_Int32;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRCORNER, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD , "setRoi", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "roiNotFull"; opcUaIdsParsInv[0] = OpcUaId_Boolean;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKIPRCORNER, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD , "setRoiNotFull", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(1); icsVVartypeSubvars.resize(1);
	srefsSubvars[0] = "NTarget"; icsVVartypeSubvars[0] = VecVVartype::UINT;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRCORNER, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR , "NTarget", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(8); icsVVartypeSubvars.resize(8);
	srefsSubvars[0] = "roiAx"; icsVVartypeSubvars[0] = VecVVartype::INT;
	srefsSubvars[1] = "roiAy"; icsVVartypeSubvars[1] = VecVVartype::INT;
	srefsSubvars[2] = "roiBx"; icsVVartypeSubvars[2] = VecVVartype::INT;
	srefsSubvars[3] = "roiBy"; icsVVartypeSubvars[3] = VecVVartype::INT;
	srefsSubvars[4] = "roiCx"; icsVVartypeSubvars[4] = VecVVartype::INT;
	srefsSubvars[5] = "roiCy"; icsVVartypeSubvars[5] = VecVVartype::INT;
	srefsSubvars[6] = "roiDx"; icsVVartypeSubvars[6] = VecVVartype::INT;
	srefsSubvars[7] = "roiDy"; icsVVartypeSubvars[7] = VecVVartype::INT;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRCORNER, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR , "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(1); icsVVartypeSubvars.resize(1);
	srefsSubvars[0] = "flg"; icsVVartypeSubvars[0] = VecVVartype::BOOLEANVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKIPRCORNER, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR , "flg", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACTSERVO, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "target"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTSERVO, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD , "moveto", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTSERVO, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD , "zero", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "angle"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "target"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecWzskVJob::JOBWZSKACTSERVO, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOVAR , "angleTarget", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACTLASER, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "left"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTLASER, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD , "setLeft", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "right"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTLASER, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD , "setRight", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "left"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "right"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecWzskVJob::JOBWZSKACTLASER, VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR , "leftRight", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACQPTCLOUD, addressSpace, objectsFolder, jobFolder);

	srefsSubvars.resize(3); icsVVartypeSubvars.resize(3);
	srefsSubvars[0] = "x"; icsVVartypeSubvars[0] = VecVVartype::FLOATVEC;
	srefsSubvars[1] = "y"; icsVVartypeSubvars[1] = VecVVartype::FLOATVEC;
	srefsSubvars[2] = "z"; icsVVartypeSubvars[2] = VecVVartype::FLOATVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKACQPTCLOUD, VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR , "xYZ", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACQPREVIEW, addressSpace, objectsFolder, jobFolder);

	srefsSubvars.resize(1); icsVVartypeSubvars.resize(1);
	srefsSubvars[0] = "gray"; icsVVartypeSubvars[0] = VecVVartype::UTINYINTVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKACQPREVIEW, VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR , "gray", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(3); icsVVartypeSubvars.resize(3);
	srefsSubvars[0] = "red"; icsVVartypeSubvars[0] = VecVVartype::UTINYINTVEC;
	srefsSubvars[1] = "green"; icsVVartypeSubvars[1] = VecVVartype::UTINYINTVEC;
	srefsSubvars[2] = "blue"; icsVVartypeSubvars[2] = VecVVartype::UTINYINTVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKACQPREVIEW, VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR , "redGreenBlue", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	return status;
};

Status_t WzskcmbdUasrv::fAS_addJobFolder(
			const uint ixWzskVJob
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<IObjectNode_t>& objectsFolder
			, IntrusivePtr_t<IObjectNode_t>& jobFolder
		) {
	Status_t status;

	uint32_t nref = nrefseq.getNewRef();

	IntrusivePtr_t<String_t> browseNameString = new SafeRefCount_t<String_t>();
	browseNameString->CopyFrom(VecWzskVJob::getSref(ixWzskVJob).c_str());

	IntrusivePtr_t<Folder_t> folderObject = Folder_t::CreateWithNumericId(1, nref, addressSpace, *browseNameString, status);
	folderObject->Hide(false);

	jobFolder = folderObject->GetObjectNode();

	jobs[nref] = ixWzskVJob;

	return AddressSpaceUtilities_t::CreateReference(*addressSpace, objectsFolder, jobFolder, OpcUaId_Organizes);
};

Status_t WzskcmbdUasrv::fAS_addVar(
			const uint ixWzskVJob
			, const uint ixWzskVFeatgroup
			, const string& srefIxVVar
			, IntrusivePtr_t<INodeValueAttributeReaderWriter_t>& readerWriter
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<IObjectNode_t>& jobFolder
			, vector<string>& srefsSubvars
			, vector<uint>& icsVVartypeSubvars
		) {
	Status_t status;

	IntrusivePtr_t<BaseDataVariable_t> subvarObject;
	IntrusivePtr_t<IVariableNode_t> subvarNode;

	// variable folder
	uint32_t nref = nrefseq.getNewRef();

	IntrusivePtr_t<String_t> browseNameString = new SafeRefCount_t<String_t>();
	browseNameString->CopyFrom(srefIxVVar.c_str());

	IntrusivePtr_t<Folder_t> folderObject = Folder_t::CreateWithNumericId(1, nref, addressSpace, *browseNameString, status);
	folderObject->Hide(false);

	IntrusivePtr_t<IObjectNode_t> varFolder = folderObject->GetObjectNode();

	vars[nref] = featix_t(ixWzskVFeatgroup, srefIxVVar);

	status = AddressSpaceUtilities_t::CreateReference(*addressSpace, jobFolder, varFolder, OpcUaId_Organizes);

	// sub-variables
	for (unsigned int i = 0; i < srefsSubvars.size(); i++) {
		nref = nrefseq.getNewRef();

		browseNameString = new SafeRefCount_t<String_t>();
		browseNameString->CopyFrom(srefsSubvars[i].c_str());

		status = fAS_addSubvar(icsVVartypeSubvars[i], nref, addressSpace, browseNameString, subvarObject);

		if (!subvarObject.is_set()) continue;

		subvarNode = subvarObject->GetVariableNode();

		status = subvarNode->ValueAttributeReaderWriter(readerWriter);

		subvarObject->Hide(false);

		subvarsVars[nref] = featix_t(ixWzskVFeatgroup, srefIxVVar);
		subvars[nref] = srefsSubvars[i];

		status = AddressSpaceUtilities_t::CreateReference(*addressSpace, varFolder, subvarNode, OpcUaId_HasComponent);
	};

	return OpcUa_Good;
};

Status_t WzskcmbdUasrv::fAS_addSubvar(
			const uint ixVVartype
			, const uint32_t nref
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<String_t>& browseNameString
			, IntrusivePtr_t<BaseDataVariable_t>& subvarObject
		) {
	Status_t status;

	subvarObject.reset();

	if (ixVVartype == VecVVartype::BOOLEAN) subvarObject = BaseDataVariable_t::CreateWithNumericId<Boolean_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::TINYINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<SByte_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UTINYINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Byte_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::SMALLINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Int16_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::USMALLINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<UInt16_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::INT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Int32_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<UInt32_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::BIGINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Int64_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UBIGINT) subvarObject = BaseDataVariable_t::CreateWithNumericId<UInt64_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::FLOAT) subvarObject = BaseDataVariable_t::CreateWithNumericId<Float_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::DOUBLE) subvarObject = BaseDataVariable_t::CreateWithNumericId<Double_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::STRING) subvarObject = BaseDataVariable_t::CreateWithNumericId<String_t>(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::BOOLEANVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Boolean_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UTINYINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Byte_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::USMALLINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<UInt16_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::INTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Int32_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<UInt32_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::UBIGINTVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<UInt64_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::FLOATVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Float_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::DOUBLEVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<Double_t> >(1, nref, addressSpace, *browseNameString, status);
	//else if (ixVVartype == VecVVartype::FLOATMAT);
	//else if (ixVVartype == VecVVartype::DOUBLEMAT):
	else if (ixVVartype == VecVVartype::STRINGVEC) subvarObject = BaseDataVariable_t::CreateWithNumericId<ArrayUA_t<String_t> >(1, nref, addressSpace, *browseNameString, status);
	else if (ixVVartype == VecVVartype::VECSREF) subvarObject = BaseDataVariable_t::CreateWithNumericId<String_t>(1, nref, addressSpace, *browseNameString, status);

	return status;
};

Status_t WzskcmbdUasrv::fAS_addMethod(
			const uint ixWzskVJob
			, const uint ixWzskVFeatgroup
			, const string& srefIxVMethod
			, IntrusivePtr_t<INodeMethodHandler_t>& methodHandler
			, IntrusivePtr_t<IAddressSpace_t>& addressSpace
			, IntrusivePtr_t<IObjectNode_t>& jobFolder
			, vector<string>& srefsParsInv
			, vector<uint32_t>& opcUaIdsParsInv
			, vector<string>& srefsParsRet
			, vector<uint32_t>& opcUaIdsParsRet
		) {
	Status_t status;

	ArrayUA_t<Argument_t> args;
	IntrusivePtr_t<Argument_t> arg;

	uint32_t nref = nrefseq.getNewRef();

	IntrusivePtr_t<String_t> browseNameString = new SafeRefCount_t<String_t>();
	browseNameString->CopyFrom(srefIxVMethod.c_str());

	IntrusivePtr_t<Method_t> methodObject = Method_t::CreateWithNumericId(1, nref, addressSpace, *browseNameString, true, status);

	methods[nref] = featix_t(ixWzskVFeatgroup, srefIxVMethod);

	// invocation parameters
	status = args.Initialise(srefsParsInv.size());
	for (unsigned int i = 0; i < srefsParsInv.size(); i++) {
		status = methodObject->CreateArgument(srefsParsInv[i].c_str(), opcUaIdsParsInv[i], -1, arg);
		args[i] = arg;
	};

	nref = nrefseq.getNewRef();
	status = methodObject->CreateInputArguments(nref, args);
	iasMethods[nref] = featix_t(ixWzskVFeatgroup, srefIxVMethod);

	// return parameters
	status = args.Initialise(srefsParsRet.size());
	for (unsigned int i = 0; i < srefsParsRet.size(); i++) {
		status = methodObject->CreateArgument(srefsParsRet[i].c_str(), opcUaIdsParsRet[i], -1, arg);
		args[i] = arg;
	};

	nref = nrefseq.getNewRef();
	status = methodObject->CreateOutputArguments(nref, args);
	oasMethods[nref] = featix_t(ixWzskVFeatgroup, srefIxVMethod);

	IntrusivePtr_t<IMethodNode_t> methodNode = methodObject->GetMethodNode();

	status = methodNode->SetMethodHandler(methodHandler);

	methodObject->Hide(false);

	return AddressSpaceUtilities_t::CreateReference(*addressSpace, jobFolder, methodNode, OpcUaId_HasComponent);
};

void WzskcmbdUasrv::runMethod(
			const ubigint jref
			, const uint ixWzskVFeatgroup
			, const string& srefIxVMethod
			, const vector<const void*>& parsInv
			, const vector<void*>& parsRet
		) {
	ReqWzsk* req = NULL;
	
	if (xchg->mUasrvcall.trylock("WzskcmbdUasrv", "runMethod", "srefIxVMethod=" + srefIxVMethod)) {
		req = new ReqWzsk(ReqWzsk::VecVBasetype::METHOD, ReqWzsk::VecVState::RECEIVE, "127.0.0.1");

		req->jref = jref;

		req->method = new Method(ixWzskVFeatgroup, srefIxVMethod);
		req->method->parsInv = parsInv;
		req->method->parsRet = parsRet;

		xchg->addReq(req);

		req->cReady.lockMutex("WzskcmbdUasrv", "runMethod", "srefIxVMethod=" + srefIxVMethod);
		if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdUasrv", "runMethod", "srefIxVMethod=" + srefIxVMethod);
		req->cReady.unlockMutex("WzskcmbdUasrv", "runMethod", "srefIxVMethod=" + srefIxVMethod);

		delete req;
		
		xchg->mUasrvcall.unlock("WzskcmbdUasrv", "runMethod", "srefIxVMethod=" + srefIxVMethod);
	};
};

XchgWzskcmbd* WzskcmbdUasrv::xchg;
IntrusivePtr_t<UAServer_t> WzskcmbdUasrv::uaserver;
bool WzskcmbdUasrv::serverHasFailed;
Refseq WzskcmbdUasrv::nrefseq;
map<uint32_t,IntrusivePtr_t<WzskcmbdUasrv::Session> > WzskcmbdUasrv::sessions;
map<ubigint,uint> WzskcmbdUasrv::ixVFeatgroups;
map<featix_t,DateTime_t> WzskcmbdUasrv::timestamps;
map<uint32_t,uint> WzskcmbdUasrv::jobs;
map<uint32_t,featix_t> WzskcmbdUasrv::methods;
map<uint32_t,featix_t> WzskcmbdUasrv::iasMethods;
map<uint32_t,featix_t> WzskcmbdUasrv::oasMethods;
map<uint32_t,featix_t> WzskcmbdUasrv::vars;
map<uint32_t,featix_t> WzskcmbdUasrv::subvarsVars;
map<uint32_t,string> WzskcmbdUasrv::subvars;


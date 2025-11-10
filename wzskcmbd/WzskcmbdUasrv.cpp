/**
	* \file WzskcmbdUasrv.cpp
	* OPC UA server based on Matrikon FLEX OPC UA SDK for Wzsk combined daemon (implementation)
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

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
		if (statshr.jrefAcqcorner != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACQCORNER);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "setRoi", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "setRoi")] = ixAcc;

			ixVFeatgroups[statshr.jrefAcqcorner] = VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "roiX0RoiY0RoiX1RoiY1", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "roiX0RoiY0RoiX1RoiY1")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqcorner, "roiX0RoiY0RoiX1RoiY1", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "shiftScoreMinScoreMax", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "shiftScoreMinScoreMax")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqcorner, "shiftScoreMinScoreMax", true);
			};
		};
		if (statshr.jrefAcqtrace != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACQTRACE);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqtrace, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "setRoi", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "setRoi")] = ixAcc;

			ixVFeatgroups[statshr.jrefAcqtrace] = VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqtrace, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR, "roiX0RoiY0RoiX1RoiY1", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR, "roiX0RoiY0RoiX1RoiY1")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefAcqtrace, "roiX0RoiY0RoiX1RoiY1", true);
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
		if (statshr.jrefActrotary != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKACTROTARY);

			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "moveto", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "moveto")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "stop", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "stop")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "turn", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "turn")] = ixAcc;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "zero", ixAcc);
			if (ixAcc != 0) accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "zero")] = ixAcc;

			ixVFeatgroups[statshr.jrefActrotary] = VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR, "angleTarget", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR, "angleTarget")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefActrotary, "angleTarget", true);
			};
		};
		if (statshr.jrefSrcfpgainfo != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKSRCFPGAINFO);

			ixVFeatgroups[statshr.jrefSrcfpgainfo] = VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcfpgainfo, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "hdrDRdHdrDWr", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "hdrDRdHdrDWr")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefSrcfpgainfo, "hdrDRdHdrDWr", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcfpgainfo, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "rndDRdRndDWr", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "rndDRdRndDWr")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefSrcfpgainfo, "rndDRdRndDWr", true);
			};
		};
		if (statshr.jrefSrcsysinfo != 0) {
			insert(jobaccs, VecWzskVJob::JOBWZSKSRCSYSINFO);

			ixVFeatgroups[statshr.jrefSrcsysinfo] = VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR;
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcsysinfo, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefSrcsysinfo, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3", true);
			};
			xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcsysinfo, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "temp", ixAcc);
			if (ixAcc != 0) {
				accs[featix_t(VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "temp")] = ixAcc;
				xchg->addClstnUasrv(statshr.jrefSrcsysinfo, "temp", true);
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

		if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD) jref = session->statshr.jrefAcqcorner;
		else if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD) jref = session->statshr.jrefAcqtrace;
		else if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD) jref = session->statshr.jrefActlaser;
		else if (ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD) jref = session->statshr.jrefActrotary;
	} else {
		return OpcUa_BadSessionIdInvalid;
	};

	if (jref != 0) {
		if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD) && (srefIxVMethod == "setRoi")) {
			if (requestParameters->InputArguments().Size() == 4) {
				IntrusivePtr_t<const Int32_t> roiX0_inv_UA;
				int roiX0_inv;
				IntrusivePtr_t<const Int32_t> roiY0_inv_UA;
				int roiY0_inv;
				IntrusivePtr_t<const Int32_t> roiX1_inv_UA;
				int roiX1_inv;
				IntrusivePtr_t<const Int32_t> roiY1_inv_UA;
				int roiY1_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), roiX0_inv_UA);
				roiX0_inv = roiX0_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[1]), roiY0_inv_UA);
				roiY0_inv = roiY0_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[2]), roiX1_inv_UA);
				roiX1_inv = roiX1_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[3]), roiY1_inv_UA);
				roiY1_inv = roiY1_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "setRoi",
							{&roiX0_inv,&roiY0_inv,&roiX1_inv,&roiY1_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD) && (srefIxVMethod == "setRoi")) {
			if (requestParameters->InputArguments().Size() == 4) {
				IntrusivePtr_t<const Int32_t> roiX0_inv_UA;
				int roiX0_inv;
				IntrusivePtr_t<const Int32_t> roiY0_inv_UA;
				int roiY0_inv;
				IntrusivePtr_t<const Int32_t> roiX1_inv_UA;
				int roiX1_inv;
				IntrusivePtr_t<const Int32_t> roiY1_inv_UA;
				int roiY1_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), roiX0_inv_UA);
				roiX0_inv = roiX0_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[1]), roiY0_inv_UA);
				roiY0_inv = roiY0_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[2]), roiX1_inv_UA);
				roiX1_inv = roiX1_inv_UA->Value();
				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[3]), roiY1_inv_UA);
				roiY1_inv = roiY1_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "setRoi",
							{&roiX0_inv,&roiY0_inv,&roiX1_inv,&roiY1_inv},
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

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD) && (srefIxVMethod == "moveto")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Float_t> target_inv_UA;
				float target_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), target_inv_UA);
				target_inv = target_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "moveto",
							{&target_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD) && (srefIxVMethod == "stop")) {
			if (requestParameters->InputArguments().Size() == 0) {
				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "stop",
							{},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD) && (srefIxVMethod == "turn")) {
			if (requestParameters->InputArguments().Size() == 1) {
				IntrusivePtr_t<const Boolean_t> ccwNotCw_inv_UA;
				bool ccwNotCw_inv;

				AddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[0]), ccwNotCw_inv_UA);
				ccwNotCw_inv = ccwNotCw_inv_UA->Value();

				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "turn",
							{&ccwNotCw_inv},
							{&success_ret});

				result.reset(new SafeRefCount_t<CallMethodResult_t>());
				result->OutputArguments().Initialise(1);

				success_ret_UA->Value(success_ret);
				success_ret_UA->CopyTo((result->OutputArguments())[0]);

				result->StatusCode() = OpcUa_Good;
			};

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD) && (srefIxVMethod == "zero")) {
			if (requestParameters->InputArguments().Size() == 0) {
				bool success_ret;
				IntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();

				runMethod(jref, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "zero",
							{},
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

		if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR) && (srefIxVVar == "roiX0RoiY0RoiX1RoiY1")) {
			JobWzskAcqCorner::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "roiX0") {
				IntrusivePtr_t<Int32_t> roiX0 = new SafeRefCount_t<Int32_t>();
				*roiX0 = JobWzskAcqCorner::shrdat.roiX0;
				dataValue->Value() = roiX0;
			} else if (subvar == "roiY0") {
				IntrusivePtr_t<Int32_t> roiY0 = new SafeRefCount_t<Int32_t>();
				*roiY0 = JobWzskAcqCorner::shrdat.roiY0;
				dataValue->Value() = roiY0;
			} else if (subvar == "roiX1") {
				IntrusivePtr_t<Int32_t> roiX1 = new SafeRefCount_t<Int32_t>();
				*roiX1 = JobWzskAcqCorner::shrdat.roiX1;
				dataValue->Value() = roiX1;
			} else if (subvar == "roiY1") {
				IntrusivePtr_t<Int32_t> roiY1 = new SafeRefCount_t<Int32_t>();
				*roiY1 = JobWzskAcqCorner::shrdat.roiY1;
				dataValue->Value() = roiY1;
			};

			JobWzskAcqCorner::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR) && (srefIxVVar == "shiftScoreMinScoreMax")) {
			JobWzskAcqCorner::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "shift") {
				IntrusivePtr_t<Byte_t> shift = new SafeRefCount_t<Byte_t>();
				*shift = JobWzskAcqCorner::shrdat.shift;
				dataValue->Value() = shift;
			} else if (subvar == "scoreMin") {
				IntrusivePtr_t<Byte_t> scoreMin = new SafeRefCount_t<Byte_t>();
				*scoreMin = JobWzskAcqCorner::shrdat.scoreMin;
				dataValue->Value() = scoreMin;
			} else if (subvar == "scoreMax") {
				IntrusivePtr_t<Byte_t> scoreMax = new SafeRefCount_t<Byte_t>();
				*scoreMax = JobWzskAcqCorner::shrdat.scoreMax;
				dataValue->Value() = scoreMax;
			};

			JobWzskAcqCorner::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR) && (srefIxVVar == "roiX0RoiY0RoiX1RoiY1")) {
			JobWzskAcqTrace::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "roiX0") {
				IntrusivePtr_t<Int32_t> roiX0 = new SafeRefCount_t<Int32_t>();
				*roiX0 = JobWzskAcqTrace::shrdat.roiX0;
				dataValue->Value() = roiX0;
			} else if (subvar == "roiY0") {
				IntrusivePtr_t<Int32_t> roiY0 = new SafeRefCount_t<Int32_t>();
				*roiY0 = JobWzskAcqTrace::shrdat.roiY0;
				dataValue->Value() = roiY0;
			} else if (subvar == "roiX1") {
				IntrusivePtr_t<Int32_t> roiX1 = new SafeRefCount_t<Int32_t>();
				*roiX1 = JobWzskAcqTrace::shrdat.roiX1;
				dataValue->Value() = roiX1;
			} else if (subvar == "roiY1") {
				IntrusivePtr_t<Int32_t> roiY1 = new SafeRefCount_t<Int32_t>();
				*roiY1 = JobWzskAcqTrace::shrdat.roiY1;
				dataValue->Value() = roiY1;
			};

			JobWzskAcqTrace::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

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

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR) && (srefIxVVar == "angleTarget")) {
			JobWzskActRotary::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "angle") {
				IntrusivePtr_t<Float_t> angle = new SafeRefCount_t<Float_t>();
				*angle = JobWzskActRotary::shrdat.angle;
				dataValue->Value() = angle;
			} else if (subvar == "target") {
				IntrusivePtr_t<Float_t> target = new SafeRefCount_t<Float_t>();
				*target = JobWzskActRotary::shrdat.target;
				dataValue->Value() = target;
			};

			JobWzskActRotary::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR) && (srefIxVVar == "hdrDRdHdrDWr")) {
			JobWzskSrcFpgainfo::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "hdrDRd") {
				IntrusivePtr_t<Float_t> hdrDRd = new SafeRefCount_t<Float_t>();
				*hdrDRd = JobWzskSrcFpgainfo::shrdat.hdrDRd;
				dataValue->Value() = hdrDRd;
			} else if (subvar == "hdrDWr") {
				IntrusivePtr_t<Float_t> hdrDWr = new SafeRefCount_t<Float_t>();
				*hdrDWr = JobWzskSrcFpgainfo::shrdat.hdrDWr;
				dataValue->Value() = hdrDWr;
			};

			JobWzskSrcFpgainfo::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR) && (srefIxVVar == "rndDRdRndDWr")) {
			JobWzskSrcFpgainfo::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "rndDRd") {
				IntrusivePtr_t<Float_t> rndDRd = new SafeRefCount_t<Float_t>();
				*rndDRd = JobWzskSrcFpgainfo::shrdat.rndDRd;
				dataValue->Value() = rndDRd;
			} else if (subvar == "rndDWr") {
				IntrusivePtr_t<Float_t> rndDWr = new SafeRefCount_t<Float_t>();
				*rndDWr = JobWzskSrcFpgainfo::shrdat.rndDWr;
				dataValue->Value() = rndDWr;
			};

			JobWzskSrcFpgainfo::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR) && (srefIxVVar == "loadAllLoadCore0LoadCore1LoadCore2LoadCore3")) {
			JobWzskSrcSysinfo::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "loadAll") {
				unsigned int len = JobWzskSrcSysinfo::shrdat.loadAll.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > loadAll = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				loadAll->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskSrcSysinfo::shrdat.loadAll[i]);
					(*loadAll)[i] = item;
				};
				dataValue->Value() = loadAll;
			} else if (subvar == "loadCore0") {
				unsigned int len = JobWzskSrcSysinfo::shrdat.loadCore0.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > loadCore0 = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				loadCore0->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskSrcSysinfo::shrdat.loadCore0[i]);
					(*loadCore0)[i] = item;
				};
				dataValue->Value() = loadCore0;
			} else if (subvar == "loadCore1") {
				unsigned int len = JobWzskSrcSysinfo::shrdat.loadCore1.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > loadCore1 = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				loadCore1->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskSrcSysinfo::shrdat.loadCore1[i]);
					(*loadCore1)[i] = item;
				};
				dataValue->Value() = loadCore1;
			} else if (subvar == "loadCore2") {
				unsigned int len = JobWzskSrcSysinfo::shrdat.loadCore2.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > loadCore2 = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				loadCore2->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskSrcSysinfo::shrdat.loadCore2[i]);
					(*loadCore2)[i] = item;
				};
				dataValue->Value() = loadCore2;
			} else if (subvar == "loadCore3") {
				unsigned int len = JobWzskSrcSysinfo::shrdat.loadCore3.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > loadCore3 = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				loadCore3->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskSrcSysinfo::shrdat.loadCore3[i]);
					(*loadCore3)[i] = item;
				};
				dataValue->Value() = loadCore3;
			};

			JobWzskSrcSysinfo::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

		 } else if ((ixWzskVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR) && (srefIxVVar == "temp")) {
			JobWzskSrcSysinfo::shrdat.rlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");

			if (setSourceTimestamp) {
				dataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();
				*(dataValue->SourceTimestamp()) = timestamps[it->second];
			};

			if (subvar == "temp") {
				unsigned int len = JobWzskSrcSysinfo::shrdat.temp.size();
				IntrusivePtr_t<ArrayUA_t<Float_t> > temp = new SafeRefCount_t<ArrayUA_t<Float_t> >();
				temp->Initialise(len);
				for (unsigned int i = 0; i < len; i++) {
					IntrusivePtr_t<Float_t> item = new SafeRefCount_t<Float_t>();
					item->Value(JobWzskSrcSysinfo::shrdat.temp[i]);
					(*temp)[i] = item;
				};
				dataValue->Value() = temp;
			};

			JobWzskSrcSysinfo::shrdat.runlockAccess("WzskcmbdUasrv::ValueAttributeReaderWriter", "ReadValueAttribute");
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

	pthread_cleanup_pop(1);

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

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACQCORNER, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(4); opcUaIdsParsInv.resize(4);
	srefsParsInv[0] = "roiX0"; opcUaIdsParsInv[0] = OpcUaId_Int32;
	srefsParsInv[1] = "roiY0"; opcUaIdsParsInv[1] = OpcUaId_Int32;
	srefsParsInv[2] = "roiX1"; opcUaIdsParsInv[2] = OpcUaId_Int32;
	srefsParsInv[3] = "roiY1"; opcUaIdsParsInv[3] = OpcUaId_Int32;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACQCORNER, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD , "setRoi", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(4); icsVVartypeSubvars.resize(4);
	srefsSubvars[0] = "roiX0"; icsVVartypeSubvars[0] = VecVVartype::INT;
	srefsSubvars[1] = "roiY0"; icsVVartypeSubvars[1] = VecVVartype::INT;
	srefsSubvars[2] = "roiX1"; icsVVartypeSubvars[2] = VecVVartype::INT;
	srefsSubvars[3] = "roiY1"; icsVVartypeSubvars[3] = VecVVartype::INT;

	fAS_addVar(VecWzskVJob::JOBWZSKACQCORNER, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR , "roiX0RoiY0RoiX1RoiY1", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(3); icsVVartypeSubvars.resize(3);
	srefsSubvars[0] = "shift"; icsVVartypeSubvars[0] = VecVVartype::UTINYINT;
	srefsSubvars[1] = "scoreMin"; icsVVartypeSubvars[1] = VecVVartype::UTINYINT;
	srefsSubvars[2] = "scoreMax"; icsVVartypeSubvars[2] = VecVVartype::UTINYINT;

	fAS_addVar(VecWzskVJob::JOBWZSKACQCORNER, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR , "shiftScoreMinScoreMax", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACQTRACE, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(4); opcUaIdsParsInv.resize(4);
	srefsParsInv[0] = "roiX0"; opcUaIdsParsInv[0] = OpcUaId_Int32;
	srefsParsInv[1] = "roiY0"; opcUaIdsParsInv[1] = OpcUaId_Int32;
	srefsParsInv[2] = "roiX1"; opcUaIdsParsInv[2] = OpcUaId_Int32;
	srefsParsInv[3] = "roiY1"; opcUaIdsParsInv[3] = OpcUaId_Int32;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACQTRACE, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD , "setRoi", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(4); icsVVartypeSubvars.resize(4);
	srefsSubvars[0] = "roiX0"; icsVVartypeSubvars[0] = VecVVartype::INT;
	srefsSubvars[1] = "roiY0"; icsVVartypeSubvars[1] = VecVVartype::INT;
	srefsSubvars[2] = "roiX1"; icsVVartypeSubvars[2] = VecVVartype::INT;
	srefsSubvars[3] = "roiY1"; icsVVartypeSubvars[3] = VecVVartype::INT;

	fAS_addVar(VecWzskVJob::JOBWZSKACQTRACE, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR , "roiX0RoiY0RoiX1RoiY1", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

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

	fAS_addJobFolder(VecWzskVJob::JOBWZSKACTROTARY, addressSpace, objectsFolder, jobFolder);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "target"; opcUaIdsParsInv[0] = OpcUaId_Float;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTROTARY, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD , "moveto", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTROTARY, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD , "stop", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(1); opcUaIdsParsInv.resize(1);
	srefsParsInv[0] = "ccwNotCw"; opcUaIdsParsInv[0] = OpcUaId_Boolean;

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTROTARY, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD , "turn", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsParsInv.resize(0); opcUaIdsParsInv.resize(0);

	srefsParsRet.resize(1); opcUaIdsParsRet.resize(1);
	srefsParsRet[0] = "success"; opcUaIdsParsRet[0] = OpcUaId_Boolean;

	fAS_addMethod(VecWzskVJob::JOBWZSKACTROTARY, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD , "zero", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "angle"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "target"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecWzskVJob::JOBWZSKACTROTARY, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR , "angleTarget", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKSRCFPGAINFO, addressSpace, objectsFolder, jobFolder);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "hdrDRd"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "hdrDWr"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecWzskVJob::JOBWZSKSRCFPGAINFO, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR , "hdrDRdHdrDWr", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(2); icsVVartypeSubvars.resize(2);
	srefsSubvars[0] = "rndDRd"; icsVVartypeSubvars[0] = VecVVartype::FLOAT;
	srefsSubvars[1] = "rndDWr"; icsVVartypeSubvars[1] = VecVVartype::FLOAT;

	fAS_addVar(VecWzskVJob::JOBWZSKSRCFPGAINFO, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR , "rndDRdRndDWr", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	fAS_addJobFolder(VecWzskVJob::JOBWZSKSRCSYSINFO, addressSpace, objectsFolder, jobFolder);

	srefsSubvars.resize(5); icsVVartypeSubvars.resize(5);
	srefsSubvars[0] = "loadAll"; icsVVartypeSubvars[0] = VecVVartype::FLOATVEC;
	srefsSubvars[1] = "loadCore0"; icsVVartypeSubvars[1] = VecVVartype::FLOATVEC;
	srefsSubvars[2] = "loadCore1"; icsVVartypeSubvars[2] = VecVVartype::FLOATVEC;
	srefsSubvars[3] = "loadCore2"; icsVVartypeSubvars[3] = VecVVartype::FLOATVEC;
	srefsSubvars[4] = "loadCore3"; icsVVartypeSubvars[4] = VecVVartype::FLOATVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKSRCSYSINFO, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR , "loadAllLoadCore0LoadCore1LoadCore2LoadCore3", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

	srefsSubvars.resize(1); icsVVartypeSubvars.resize(1);
	srefsSubvars[0] = "temp"; icsVVartypeSubvars[0] = VecVVartype::FLOATVEC;

	fAS_addVar(VecWzskVJob::JOBWZSKSRCSYSINFO, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR , "temp", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);

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

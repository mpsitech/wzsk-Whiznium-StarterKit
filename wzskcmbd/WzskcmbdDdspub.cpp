/**
	* \file WzskcmbdDdspub.cpp
	* DDS publisher based on rti DDS Connext for Wzsk combined daemon (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "Wzskcmbd.h"

#include "WzskcmbdDdspub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 replier classes
 ******************************************************************************/

namespace rti {
	namespace request {
		template<> void ReplierListener<DdsJobWzskIprTrace::setLevel_req,DdsJobWzskIprTrace::setLevel_reply>::on_request_available(
					Replier<DdsJobWzskIprTrace::setLevel_req,DdsJobWzskIprTrace::setLevel_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprTrace::setLevel_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setLevel",
							{&request.data().levelOn(), &request.data().levelOff()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskIprTrace::setPOn_req,DdsJobWzskIprTrace::setPOn_reply>::on_request_available(
					Replier<DdsJobWzskIprTrace::setPOn_req,DdsJobWzskIprTrace::setPOn_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprTrace::setPOn_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setPOn",
							{&request.data().pOnLeft(), &request.data().pOnRight()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskIprTrace::setRoi_req,DdsJobWzskIprTrace::setRoi_reply>::on_request_available(
					Replier<DdsJobWzskIprTrace::setRoi_req,DdsJobWzskIprTrace::setRoi_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprTrace::setRoi_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoi",
							{&request.data().roiAx(), &request.data().roiAy(), &request.data().roiBx(), &request.data().roiBy(), &request.data().roiCx(), &request.data().roiCy(), &request.data().roiDx(), &request.data().roiDy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskIprTrace::setRoiNotFull_req,DdsJobWzskIprTrace::setRoiNotFull_reply>::on_request_available(
					Replier<DdsJobWzskIprTrace::setRoiNotFull_req,DdsJobWzskIprTrace::setRoiNotFull_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprTrace::setRoiNotFull_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoiNotFull",
							{&request.data().roiNotFull()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskIprCorner::setNTarget_req,DdsJobWzskIprCorner::setNTarget_reply>::on_request_available(
					Replier<DdsJobWzskIprCorner::setNTarget_req,DdsJobWzskIprCorner::setNTarget_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprCorner::setNTarget_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setNTarget",
							{&request.data().NTarget()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskIprCorner::setRoi_req,DdsJobWzskIprCorner::setRoi_reply>::on_request_available(
					Replier<DdsJobWzskIprCorner::setRoi_req,DdsJobWzskIprCorner::setRoi_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprCorner::setRoi_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoi",
							{&request.data().roiAx(), &request.data().roiAy(), &request.data().roiBx(), &request.data().roiBy(), &request.data().roiCx(), &request.data().roiCy(), &request.data().roiDx(), &request.data().roiDy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskIprCorner::setRoiNotFull_req,DdsJobWzskIprCorner::setRoiNotFull_reply>::on_request_available(
					Replier<DdsJobWzskIprCorner::setRoiNotFull_req,DdsJobWzskIprCorner::setRoiNotFull_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskIprCorner::setRoiNotFull_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoiNotFull",
							{&request.data().roiNotFull()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActServo::moveto_req,DdsJobWzskActServo::moveto_reply>::on_request_available(
					Replier<DdsJobWzskActServo::moveto_req,DdsJobWzskActServo::moveto_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActServo::moveto_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "moveto",
							{&request.data().target()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActServo::zero_req,DdsJobWzskActServo::zero_reply>::on_request_available(
					Replier<DdsJobWzskActServo::zero_req,DdsJobWzskActServo::zero_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActServo::zero_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "zero",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActLaser::setLeft_req,DdsJobWzskActLaser::setLeft_reply>::on_request_available(
					Replier<DdsJobWzskActLaser::setLeft_req,DdsJobWzskActLaser::setLeft_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActLaser::setLeft_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setLeft",
							{&request.data().left()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActLaser::setRight_req,DdsJobWzskActLaser::setRight_reply>::on_request_available(
					Replier<DdsJobWzskActLaser::setRight_req,DdsJobWzskActLaser::setRight_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActLaser::setRight_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setRight",
							{&request.data().right()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

	};
};

/******************************************************************************
 class WzskcmbdDdspub::Repliers
 ******************************************************************************/

WzskcmbdDdspub::Repliers::Repliers() {
	replierJobWzskIprTrace_setLevel = NULL;
	replierJobWzskIprTrace_setPOn = NULL;
	replierJobWzskIprTrace_setRoi = NULL;
	replierJobWzskIprTrace_setRoiNotFull = NULL;

	replierJobWzskIprCorner_setNTarget = NULL;
	replierJobWzskIprCorner_setRoi = NULL;
	replierJobWzskIprCorner_setRoiNotFull = NULL;

	replierJobWzskActServo_moveto = NULL;
	replierJobWzskActServo_zero = NULL;

	replierJobWzskActLaser_setLeft = NULL;
	replierJobWzskActLaser_setRight = NULL;
};

WzskcmbdDdspub::Repliers::~Repliers() {
	if (replierJobWzskIprTrace_setLevel) delete replierJobWzskIprTrace_setLevel;
	if (replierJobWzskIprTrace_setPOn) delete replierJobWzskIprTrace_setPOn;
	if (replierJobWzskIprTrace_setRoi) delete replierJobWzskIprTrace_setRoi;
	if (replierJobWzskIprTrace_setRoiNotFull) delete replierJobWzskIprTrace_setRoiNotFull;

	if (replierJobWzskIprCorner_setNTarget) delete replierJobWzskIprCorner_setNTarget;
	if (replierJobWzskIprCorner_setRoi) delete replierJobWzskIprCorner_setRoi;
	if (replierJobWzskIprCorner_setRoiNotFull) delete replierJobWzskIprCorner_setRoiNotFull;

	if (replierJobWzskActServo_moveto) delete replierJobWzskActServo_moveto;
	if (replierJobWzskActServo_zero) delete replierJobWzskActServo_zero;

	if (replierJobWzskActLaser_setLeft) delete replierJobWzskActLaser_setLeft;
	if (replierJobWzskActLaser_setRight) delete replierJobWzskActLaser_setRight;
};

/******************************************************************************
 class WzskcmbdDdspub::DataWriters
 ******************************************************************************/

WzskcmbdDdspub::DataWriters::DataWriters() {
	topicJobWzskIprTrace_pOnLeftPOnRight = NULL;
	writerJobWzskIprTrace_pOnLeftPOnRight = NULL;
	JobWzskIprTrace_pOnLeftPOnRight = NULL;

	topicJobWzskIprTrace_levelOnLevelOff = NULL;
	writerJobWzskIprTrace_levelOnLevelOff = NULL;
	JobWzskIprTrace_levelOnLevelOff = NULL;

	topicJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = NULL;
	writerJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = NULL;
	JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = NULL;

	topicJobWzskIprTrace_leftRight = NULL;
	writerJobWzskIprTrace_leftRight = NULL;
	JobWzskIprTrace_leftRight = NULL;

	topicJobWzskIprCorner_NTarget = NULL;
	writerJobWzskIprCorner_NTarget = NULL;
	JobWzskIprCorner_NTarget = NULL;

	topicJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = NULL;
	writerJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = NULL;
	JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = NULL;

	topicJobWzskIprCorner_flg = NULL;
	writerJobWzskIprCorner_flg = NULL;
	JobWzskIprCorner_flg = NULL;

	topicJobWzskActServo_angleTarget = NULL;
	writerJobWzskActServo_angleTarget = NULL;
	JobWzskActServo_angleTarget = NULL;

	topicJobWzskActLaser_leftRight = NULL;
	writerJobWzskActLaser_leftRight = NULL;
	JobWzskActLaser_leftRight = NULL;

	topicJobWzskAcqPtcloud_xYZ = NULL;
	writerJobWzskAcqPtcloud_xYZ = NULL;
	JobWzskAcqPtcloud_xYZ = NULL;

	topicJobWzskAcqPreview_gray = NULL;
	writerJobWzskAcqPreview_gray = NULL;
	JobWzskAcqPreview_gray = NULL;

	topicJobWzskAcqPreview_redGreenBlue = NULL;
	writerJobWzskAcqPreview_redGreenBlue = NULL;
	JobWzskAcqPreview_redGreenBlue = NULL;
};

WzskcmbdDdspub::DataWriters::~DataWriters() {
	if (topicJobWzskIprTrace_pOnLeftPOnRight) {
		delete topicJobWzskIprTrace_pOnLeftPOnRight;
		delete writerJobWzskIprTrace_pOnLeftPOnRight;
		delete JobWzskIprTrace_pOnLeftPOnRight;
	};
	if (topicJobWzskIprTrace_levelOnLevelOff) {
		delete topicJobWzskIprTrace_levelOnLevelOff;
		delete writerJobWzskIprTrace_levelOnLevelOff;
		delete JobWzskIprTrace_levelOnLevelOff;
	};
	if (topicJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy) {
		delete topicJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		delete writerJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		delete JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
	};
	if (topicJobWzskIprTrace_leftRight) {
		delete topicJobWzskIprTrace_leftRight;
		delete writerJobWzskIprTrace_leftRight;
		delete JobWzskIprTrace_leftRight;
	};
	if (topicJobWzskIprCorner_NTarget) {
		delete topicJobWzskIprCorner_NTarget;
		delete writerJobWzskIprCorner_NTarget;
		delete JobWzskIprCorner_NTarget;
	};
	if (topicJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy) {
		delete topicJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		delete writerJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
		delete JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy;
	};
	if (topicJobWzskIprCorner_flg) {
		delete topicJobWzskIprCorner_flg;
		delete writerJobWzskIprCorner_flg;
		delete JobWzskIprCorner_flg;
	};
	if (topicJobWzskActServo_angleTarget) {
		delete topicJobWzskActServo_angleTarget;
		delete writerJobWzskActServo_angleTarget;
		delete JobWzskActServo_angleTarget;
	};
	if (topicJobWzskActLaser_leftRight) {
		delete topicJobWzskActLaser_leftRight;
		delete writerJobWzskActLaser_leftRight;
		delete JobWzskActLaser_leftRight;
	};
	if (topicJobWzskAcqPtcloud_xYZ) {
		delete topicJobWzskAcqPtcloud_xYZ;
		delete writerJobWzskAcqPtcloud_xYZ;
		delete JobWzskAcqPtcloud_xYZ;
	};
	if (topicJobWzskAcqPreview_gray) {
		delete topicJobWzskAcqPreview_gray;
		delete writerJobWzskAcqPreview_gray;
		delete JobWzskAcqPreview_gray;
	};
	if (topicJobWzskAcqPreview_redGreenBlue) {
		delete topicJobWzskAcqPreview_redGreenBlue;
		delete writerJobWzskAcqPreview_redGreenBlue;
		delete JobWzskAcqPreview_redGreenBlue;
	};
};

/******************************************************************************
 namespace WzskcmbdDdspub
 ******************************************************************************/

void* WzskcmbdDdspub::run(
			void* arg
		) {
	xchg = (XchgWzskcmbd*) arg;
	jrefM2msess = 0;

	ReqWzsk* req = NULL;

	RootWzsk::DpchAppLogin* dpchapplogin = NULL;

	uint ixAcc;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// - start M2M session
	req = new ReqWzsk(ReqWzsk::VecVBasetype::DPCHAPP, ReqWzsk::VecVState::RECEIVE, "127.0.0.1");

	req->jref = xchg->jrefRoot;

	dpchapplogin = new RootWzsk::DpchAppLogin();
	dpchapplogin->jref = xchg->jrefRoot;
	dpchapplogin->username = xchg->stgwzskddspub.username;
	dpchapplogin->password = xchg->stgwzskddspub.password;
	dpchapplogin->m2mNotReg = true;

	req->dpchapp = dpchapplogin;

	xchg->addReq(req);

	req->cReady.lockMutex("WzskcmbdDdspub", "run[1]");
	if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdDdspub", "run[1]");
	req->cReady.unlockMutex("WzskcmbdDdspub", "run[1]");

	if (req->dpcheng) if (req->dpcheng->ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKCONFIRM) if (((DpchEngWzskConfirm*) (req->dpcheng))->accepted) jrefM2msess = req->dpcheng->jref;

	delete req;

	if (jrefM2msess != 0) {
		// - determine available jobs
		req = new ReqWzsk(ReqWzsk::VecVBasetype::DPCHAPP, ReqWzsk::VecVState::RECEIVE, "127.0.0.1");

		req->jref = jrefM2msess;

		req->dpchapp = new DpchAppWzskInit();
		req->dpchapp->jref = jrefM2msess;

		xchg->addReq(req);

		req->cReady.lockMutex("WzskcmbdDdspub", "run[2]");
		if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdDdspub", "run[2]");
		req->cReady.unlockMutex("WzskcmbdDdspub", "run[2]");

		if (req->dpcheng) if (req->dpcheng->ixWzskVDpch == VecWzskVDpch::DPCHENGM2MSESSWZSKDATA) if (req->dpcheng->has(M2msessWzsk::DpchEngData::STATSHR)) statshr = ((M2msessWzsk::DpchEngData*) (req->dpcheng))->statshr;

		delete req;
	};

	// -- set up DDS (method) repliers and (variable) publishers
	dds::domain::DomainParticipant participant(0);

	// - add replier for each method with execute access
	rti::request::ReplierParams params = rti::request::ReplierParams(participant);

	if (statshr.jrefIprtrace != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setLevel", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprTrace.setLevel");
			repliers.replierJobWzskIprTrace_setLevel = new rti::request::Replier<DdsJobWzskIprTrace::setLevel_req,DdsJobWzskIprTrace::setLevel_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setPOn", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprTrace.setPOn");
			repliers.replierJobWzskIprTrace_setPOn = new rti::request::Replier<DdsJobWzskIprTrace::setPOn_req,DdsJobWzskIprTrace::setPOn_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoi", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprTrace.setRoi");
			repliers.replierJobWzskIprTrace_setRoi = new rti::request::Replier<DdsJobWzskIprTrace::setRoi_req,DdsJobWzskIprTrace::setRoi_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD, "setRoiNotFull", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprTrace.setRoiNotFull");
			repliers.replierJobWzskIprTrace_setRoiNotFull = new rti::request::Replier<DdsJobWzskIprTrace::setRoiNotFull_req,DdsJobWzskIprTrace::setRoiNotFull_reply>(params);
		};
	};
	if (statshr.jrefIprcorner != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setNTarget", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprCorner.setNTarget");
			repliers.replierJobWzskIprCorner_setNTarget = new rti::request::Replier<DdsJobWzskIprCorner::setNTarget_req,DdsJobWzskIprCorner::setNTarget_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoi", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprCorner.setRoi");
			repliers.replierJobWzskIprCorner_setRoi = new rti::request::Replier<DdsJobWzskIprCorner::setRoi_req,DdsJobWzskIprCorner::setRoi_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD, "setRoiNotFull", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskIprCorner.setRoiNotFull");
			repliers.replierJobWzskIprCorner_setRoiNotFull = new rti::request::Replier<DdsJobWzskIprCorner::setRoiNotFull_req,DdsJobWzskIprCorner::setRoiNotFull_reply>(params);
		};
	};
	if (statshr.jrefActservo != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "moveto", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActServo.moveto");
			repliers.replierJobWzskActServo_moveto = new rti::request::Replier<DdsJobWzskActServo::moveto_req,DdsJobWzskActServo::moveto_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "zero", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActServo.zero");
			repliers.replierJobWzskActServo_zero = new rti::request::Replier<DdsJobWzskActServo::zero_req,DdsJobWzskActServo::zero_reply>(params);
		};
	};
	if (statshr.jrefActlaser != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setLeft", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActLaser.setLeft");
			repliers.replierJobWzskActLaser_setLeft = new rti::request::Replier<DdsJobWzskActLaser::setLeft_req,DdsJobWzskActLaser::setLeft_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERMETHOD, "setRight", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActLaser.setRight");
			repliers.replierJobWzskActLaser_setRight = new rti::request::Replier<DdsJobWzskActLaser::setRight_req,DdsJobWzskActLaser::setRight_reply>(params);
		};
	};

	// - register call listeners for each variable with view (read) access
	if (statshr.jrefIprtrace != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "pOnLeftPOnRight", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprTrace_pOnLeftPOnRight = new DdsJobWzskIprTrace::pOnLeftPOnRight();
			dataWriters.topicJobWzskIprTrace_pOnLeftPOnRight = new dds::topic::Topic<DdsJobWzskIprTrace::pOnLeftPOnRight>(participant, "JobWzskIprTrace.pOnLeftPOnRight");
			dataWriters.writerJobWzskIprTrace_pOnLeftPOnRight = new dds::pub::DataWriter<DdsJobWzskIprTrace::pOnLeftPOnRight>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprTrace_pOnLeftPOnRight);

			xchg->addClstnDdspub(statshr.jrefIprtrace, "pOnLeftPOnRight", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "levelOnLevelOff", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprTrace_levelOnLevelOff = new DdsJobWzskIprTrace::levelOnLevelOff();
			dataWriters.topicJobWzskIprTrace_levelOnLevelOff = new dds::topic::Topic<DdsJobWzskIprTrace::levelOnLevelOff>(participant, "JobWzskIprTrace.levelOnLevelOff");
			dataWriters.writerJobWzskIprTrace_levelOnLevelOff = new dds::pub::DataWriter<DdsJobWzskIprTrace::levelOnLevelOff>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprTrace_levelOnLevelOff);

			xchg->addClstnDdspub(statshr.jrefIprtrace, "levelOnLevelOff", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = new DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy();
			dataWriters.topicJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = new dds::topic::Topic<DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>(participant, "JobWzskIprTrace.roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy");
			dataWriters.writerJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = new dds::pub::DataWriter<DdsJobWzskIprTrace::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy);

			xchg->addClstnDdspub(statshr.jrefIprtrace, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprtrace, VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEVAR, "leftRight", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprTrace_leftRight = new DdsJobWzskIprTrace::leftRight();
			dataWriters.topicJobWzskIprTrace_leftRight = new dds::topic::Topic<DdsJobWzskIprTrace::leftRight>(participant, "JobWzskIprTrace.leftRight");
			dataWriters.writerJobWzskIprTrace_leftRight = new dds::pub::DataWriter<DdsJobWzskIprTrace::leftRight>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprTrace_leftRight);

			xchg->addClstnDdspub(statshr.jrefIprtrace, "leftRight", true);
		};
	};
	if (statshr.jrefIprcorner != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "NTarget", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprCorner_NTarget = new DdsJobWzskIprCorner::NTarget();
			dataWriters.topicJobWzskIprCorner_NTarget = new dds::topic::Topic<DdsJobWzskIprCorner::NTarget>(participant, "JobWzskIprCorner.NTarget");
			dataWriters.writerJobWzskIprCorner_NTarget = new dds::pub::DataWriter<DdsJobWzskIprCorner::NTarget>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprCorner_NTarget);

			xchg->addClstnDdspub(statshr.jrefIprcorner, "NTarget", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = new DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy();
			dataWriters.topicJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = new dds::topic::Topic<DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>(participant, "JobWzskIprCorner.roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy");
			dataWriters.writerJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy = new dds::pub::DataWriter<DdsJobWzskIprCorner::roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy);

			xchg->addClstnDdspub(statshr.jrefIprcorner, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "flg", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprCorner_flg = new DdsJobWzskIprCorner::flg();
			dataWriters.topicJobWzskIprCorner_flg = new dds::topic::Topic<DdsJobWzskIprCorner::flg>(participant, "JobWzskIprCorner.flg");
			dataWriters.writerJobWzskIprCorner_flg = new dds::pub::DataWriter<DdsJobWzskIprCorner::flg>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprCorner_flg);

			xchg->addClstnDdspub(statshr.jrefIprcorner, "flg", true);
		};
	};
	if (statshr.jrefActservo != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOVAR, "angleTarget", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskActServo_angleTarget = new DdsJobWzskActServo::angleTarget();
			dataWriters.topicJobWzskActServo_angleTarget = new dds::topic::Topic<DdsJobWzskActServo::angleTarget>(participant, "JobWzskActServo.angleTarget");
			dataWriters.writerJobWzskActServo_angleTarget = new dds::pub::DataWriter<DdsJobWzskActServo::angleTarget>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskActServo_angleTarget);

			xchg->addClstnDdspub(statshr.jrefActservo, "angleTarget", true);
		};
	};
	if (statshr.jrefActlaser != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActlaser, VecWzskVFeatgroup::VECVJOBWZSKACTLASERVAR, "leftRight", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskActLaser_leftRight = new DdsJobWzskActLaser::leftRight();
			dataWriters.topicJobWzskActLaser_leftRight = new dds::topic::Topic<DdsJobWzskActLaser::leftRight>(participant, "JobWzskActLaser.leftRight");
			dataWriters.writerJobWzskActLaser_leftRight = new dds::pub::DataWriter<DdsJobWzskActLaser::leftRight>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskActLaser_leftRight);

			xchg->addClstnDdspub(statshr.jrefActlaser, "leftRight", true);
		};
	};
	if (statshr.jrefAcqptcloud != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqptcloud, VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR, "xYZ", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqPtcloud_xYZ = new DdsJobWzskAcqPtcloud::xYZ();
			dataWriters.topicJobWzskAcqPtcloud_xYZ = new dds::topic::Topic<DdsJobWzskAcqPtcloud::xYZ>(participant, "JobWzskAcqPtcloud.xYZ");
			dataWriters.writerJobWzskAcqPtcloud_xYZ = new dds::pub::DataWriter<DdsJobWzskAcqPtcloud::xYZ>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqPtcloud_xYZ);

			xchg->addClstnDdspub(statshr.jrefAcqptcloud, "xYZ", true);
		};
	};
	if (statshr.jrefAcqpreview != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqpreview, VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR, "gray", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqPreview_gray = new DdsJobWzskAcqPreview::gray();
			dataWriters.topicJobWzskAcqPreview_gray = new dds::topic::Topic<DdsJobWzskAcqPreview::gray>(participant, "JobWzskAcqPreview.gray");
			dataWriters.writerJobWzskAcqPreview_gray = new dds::pub::DataWriter<DdsJobWzskAcqPreview::gray>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqPreview_gray);

			xchg->addClstnDdspub(statshr.jrefAcqpreview, "gray", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqpreview, VecWzskVFeatgroup::VECVJOBWZSKACQPREVIEWVAR, "redGreenBlue", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqPreview_redGreenBlue = new DdsJobWzskAcqPreview::redGreenBlue();
			dataWriters.topicJobWzskAcqPreview_redGreenBlue = new dds::topic::Topic<DdsJobWzskAcqPreview::redGreenBlue>(participant, "JobWzskAcqPreview.redGreenBlue");
			dataWriters.writerJobWzskAcqPreview_redGreenBlue = new dds::pub::DataWriter<DdsJobWzskAcqPreview::redGreenBlue>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqPreview_redGreenBlue);

			xchg->addClstnDdspub(statshr.jrefAcqpreview, "redGreenBlue", true);
		};
	};

	xchg->cStable.signal("WzskcmbdDdspub", "run");

	while (true) {
		xchg->cDdspub.lockMutex("WzskcmbdDdspub", "run");
		while (!(xchg->ddspubcall)) xchg->cDdspub.wait("WzskcmbdDdspub", "run");

		if ((xchg->ddspubcall->jref == statshr.jrefIprtrace) && (xchg->ddspubcall->argInv.sref == "pOnLeftPOnRight")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprTrace_pOnLeftPOnRight->pOnLeft(JobWzskIprTrace::shrdat.pOnLeft);
			dataWriters.JobWzskIprTrace_pOnLeftPOnRight->pOnRight(JobWzskIprTrace::shrdat.pOnRight);
			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprTrace_pOnLeftPOnRight->write(*(dataWriters.JobWzskIprTrace_pOnLeftPOnRight));
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprtrace) && (xchg->ddspubcall->argInv.sref == "levelOnLevelOff")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprTrace_levelOnLevelOff->levelOn(JobWzskIprTrace::shrdat.levelOn);
			dataWriters.JobWzskIprTrace_levelOnLevelOff->levelOff(JobWzskIprTrace::shrdat.levelOff);
			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprTrace_levelOnLevelOff->write(*(dataWriters.JobWzskIprTrace_levelOnLevelOff));
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprtrace) && (xchg->ddspubcall->argInv.sref == "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiAx(JobWzskIprTrace::shrdat.roiAx);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiAy(JobWzskIprTrace::shrdat.roiAy);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiBx(JobWzskIprTrace::shrdat.roiBx);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiBy(JobWzskIprTrace::shrdat.roiBy);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiCx(JobWzskIprTrace::shrdat.roiCx);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiCy(JobWzskIprTrace::shrdat.roiCy);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiDx(JobWzskIprTrace::shrdat.roiDx);
			dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiDy(JobWzskIprTrace::shrdat.roiDy);
			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->write(*(dataWriters.JobWzskIprTrace_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy));
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprtrace) && (xchg->ddspubcall->argInv.sref == "leftRight")) {
			JobWzskIprTrace::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprTrace_leftRight->left(JobWzskIprTrace::shrdat.left);
			dataWriters.JobWzskIprTrace_leftRight->right(JobWzskIprTrace::shrdat.right);
			JobWzskIprTrace::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprTrace_leftRight->write(*(dataWriters.JobWzskIprTrace_leftRight));
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprcorner) && (xchg->ddspubcall->argInv.sref == "NTarget")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprCorner_NTarget->_NTarget(JobWzskIprCorner::shrdat.NTarget);
			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprCorner_NTarget->write(*(dataWriters.JobWzskIprCorner_NTarget));
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprcorner) && (xchg->ddspubcall->argInv.sref == "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiAx(JobWzskIprCorner::shrdat.roiAx);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiAy(JobWzskIprCorner::shrdat.roiAy);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiBx(JobWzskIprCorner::shrdat.roiBx);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiBy(JobWzskIprCorner::shrdat.roiBy);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiCx(JobWzskIprCorner::shrdat.roiCx);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiCy(JobWzskIprCorner::shrdat.roiCy);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiDx(JobWzskIprCorner::shrdat.roiDx);
			dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->roiDy(JobWzskIprCorner::shrdat.roiDy);
			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy->write(*(dataWriters.JobWzskIprCorner_roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy));
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprcorner) && (xchg->ddspubcall->argInv.sref == "flg")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprCorner_flg->_flg(JobWzskIprCorner::shrdat.flg);
			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprCorner_flg->write(*(dataWriters.JobWzskIprCorner_flg));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActservo) && (xchg->ddspubcall->argInv.sref == "angleTarget")) {
			JobWzskActServo::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskActServo_angleTarget->angle(JobWzskActServo::shrdat.angle);
			dataWriters.JobWzskActServo_angleTarget->target(JobWzskActServo::shrdat.target);
			JobWzskActServo::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskActServo_angleTarget->write(*(dataWriters.JobWzskActServo_angleTarget));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActlaser) && (xchg->ddspubcall->argInv.sref == "leftRight")) {
			JobWzskActLaser::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskActLaser_leftRight->left(JobWzskActLaser::shrdat.left);
			dataWriters.JobWzskActLaser_leftRight->right(JobWzskActLaser::shrdat.right);
			JobWzskActLaser::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskActLaser_leftRight->write(*(dataWriters.JobWzskActLaser_leftRight));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqptcloud) && (xchg->ddspubcall->argInv.sref == "xYZ")) {
			JobWzskAcqPtcloud::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqPtcloud_xYZ->x(JobWzskAcqPtcloud::shrdat.x);
			dataWriters.JobWzskAcqPtcloud_xYZ->y(JobWzskAcqPtcloud::shrdat.y);
			dataWriters.JobWzskAcqPtcloud_xYZ->z(JobWzskAcqPtcloud::shrdat.z);
			JobWzskAcqPtcloud::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqPtcloud_xYZ->write(*(dataWriters.JobWzskAcqPtcloud_xYZ));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqpreview) && (xchg->ddspubcall->argInv.sref == "gray")) {
			JobWzskAcqPreview::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqPreview_gray->_gray(JobWzskAcqPreview::shrdat.gray);
			JobWzskAcqPreview::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqPreview_gray->write(*(dataWriters.JobWzskAcqPreview_gray));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqpreview) && (xchg->ddspubcall->argInv.sref == "redGreenBlue")) {
			JobWzskAcqPreview::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqPreview_redGreenBlue->red(JobWzskAcqPreview::shrdat.red);
			dataWriters.JobWzskAcqPreview_redGreenBlue->green(JobWzskAcqPreview::shrdat.green);
			dataWriters.JobWzskAcqPreview_redGreenBlue->blue(JobWzskAcqPreview::shrdat.blue);
			JobWzskAcqPreview::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqPreview_redGreenBlue->write(*(dataWriters.JobWzskAcqPreview_redGreenBlue));
		};

		xchg->ddspubcall = NULL;

		xchg->cDdspub.unlockMutex("WzskcmbdDdspub", "run");

		xchg->cDdspub.signal("WzskcmbdDdspub", "run");
	};

	pthread_cleanup_pop(0);

	return NULL;
};

void WzskcmbdDdspub::cleanup(
			void* arg
		) {
	XchgWzskcmbd* xchg = (XchgWzskcmbd*) arg;

	xchg->cDdspub.unlockMutex("WzskcmbdDdspub", "cleanup");
};

void WzskcmbdDdspub::runMethod(
			const ubigint jref
			, const uint ixWzskVFeatgroup
			, const string& srefIxVMethod
			, const vector<const void*>& parsInv
			, const vector<void*>& parsRet
		) {
	ReqWzsk* req = NULL;
	
	if (xchg->mDdspubcall.trylock("WzskcmbdDdspub", "runMethod", "srefIxVMethod=" + srefIxVMethod)) {
		req = new ReqWzsk(ReqWzsk::VecVBasetype::METHOD, ReqWzsk::VecVState::RECEIVE, "127.0.0.1");

		req->jref = jref;

		req->method = new Method(ixWzskVFeatgroup, srefIxVMethod);
		req->method->parsInv = parsInv;
		req->method->parsRet = parsRet;

		xchg->addReq(req);

		req->cReady.lockMutex("WzskcmbdDdspub", "runMethod", "srefIxVMethod=" + srefIxVMethod);
		if (req->ixVState != ReqWzsk::VecVState::REPLY) req->cReady.wait("WzskcmbdDdspub", "runMethod", "srefIxVMethod=" + srefIxVMethod);
		req->cReady.unlockMutex("WzskcmbdDdspub", "runMethod", "srefIxVMethod=" + srefIxVMethod);

		delete req;

		xchg->mDdspubcall.unlock("WzskcmbdDdspub", "runMethod", "srefIxVMethod=" + srefIxVMethod);
	};
};

XchgWzskcmbd* WzskcmbdDdspub::xchg;
ubigint WzskcmbdDdspub::jrefM2msess;
M2msessWzsk::StatShr WzskcmbdDdspub::statshr;
WzskcmbdDdspub::Repliers WzskcmbdDdspub::repliers;
WzskcmbdDdspub::DataWriters WzskcmbdDdspub::dataWriters;

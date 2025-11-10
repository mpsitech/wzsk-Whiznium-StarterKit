/**
	* \file WzskcmbdDdspub.cpp
	* DDS publisher based on rti DDS Connext for Wzsk combined daemon (implementation)
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

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
		template<> void ReplierListener<DdsJobWzskAcqCorner::setRoi_req,DdsJobWzskAcqCorner::setRoi_reply>::on_request_available(
					Replier<DdsJobWzskAcqCorner::setRoi_req,DdsJobWzskAcqCorner::setRoi_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskAcqCorner::setRoi_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "setRoi",
							{&request.data().roiX0(), &request.data().roiY0(), &request.data().roiX1(), &request.data().roiY1()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskAcqTrace::setRoi_req,DdsJobWzskAcqTrace::setRoi_reply>::on_request_available(
					Replier<DdsJobWzskAcqTrace::setRoi_req,DdsJobWzskAcqTrace::setRoi_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskAcqTrace::setRoi_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefAcqtrace, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "setRoi",
							{&request.data().roiX0(), &request.data().roiY0(), &request.data().roiX1(), &request.data().roiY1()},
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

		template<> void ReplierListener<DdsJobWzskActRotary::moveto_req,DdsJobWzskActRotary::moveto_reply>::on_request_available(
					Replier<DdsJobWzskActRotary::moveto_req,DdsJobWzskActRotary::moveto_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActRotary::moveto_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "moveto",
							{&request.data().target()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActRotary::stop_req,DdsJobWzskActRotary::stop_reply>::on_request_available(
					Replier<DdsJobWzskActRotary::stop_req,DdsJobWzskActRotary::stop_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActRotary::stop_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "stop",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActRotary::turn_req,DdsJobWzskActRotary::turn_reply>::on_request_available(
					Replier<DdsJobWzskActRotary::turn_req,DdsJobWzskActRotary::turn_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActRotary::turn_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "turn",
							{&request.data().ccwNotCw()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActRotary::zero_req,DdsJobWzskActRotary::zero_reply>::on_request_available(
					Replier<DdsJobWzskActRotary::zero_req,DdsJobWzskActRotary::zero_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActRotary::zero_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "zero",
							{&request.data().dummy()},
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
	replierJobWzskAcqCorner_setRoi = NULL;

	replierJobWzskAcqTrace_setRoi = NULL;

	replierJobWzskActLaser_setLeft = NULL;
	replierJobWzskActLaser_setRight = NULL;

	replierJobWzskActRotary_moveto = NULL;
	replierJobWzskActRotary_stop = NULL;
	replierJobWzskActRotary_turn = NULL;
	replierJobWzskActRotary_zero = NULL;
};

WzskcmbdDdspub::Repliers::~Repliers() {
	if (replierJobWzskAcqCorner_setRoi) delete replierJobWzskAcqCorner_setRoi;

	if (replierJobWzskAcqTrace_setRoi) delete replierJobWzskAcqTrace_setRoi;

	if (replierJobWzskActLaser_setLeft) delete replierJobWzskActLaser_setLeft;
	if (replierJobWzskActLaser_setRight) delete replierJobWzskActLaser_setRight;

	if (replierJobWzskActRotary_moveto) delete replierJobWzskActRotary_moveto;
	if (replierJobWzskActRotary_stop) delete replierJobWzskActRotary_stop;
	if (replierJobWzskActRotary_turn) delete replierJobWzskActRotary_turn;
	if (replierJobWzskActRotary_zero) delete replierJobWzskActRotary_zero;
};

/******************************************************************************
 class WzskcmbdDdspub::DataWriters
 ******************************************************************************/

WzskcmbdDdspub::DataWriters::DataWriters() {
	topicJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1 = NULL;
	writerJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1 = NULL;
	JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1 = NULL;

	topicJobWzskAcqCorner_shiftScoreMinScoreMax = NULL;
	writerJobWzskAcqCorner_shiftScoreMinScoreMax = NULL;
	JobWzskAcqCorner_shiftScoreMinScoreMax = NULL;

	topicJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1 = NULL;
	writerJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1 = NULL;
	JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1 = NULL;

	topicJobWzskActLaser_leftRight = NULL;
	writerJobWzskActLaser_leftRight = NULL;
	JobWzskActLaser_leftRight = NULL;

	topicJobWzskActRotary_angleTarget = NULL;
	writerJobWzskActRotary_angleTarget = NULL;
	JobWzskActRotary_angleTarget = NULL;

	topicJobWzskSrcFpgainfo_hdrDRdHdrDWr = NULL;
	writerJobWzskSrcFpgainfo_hdrDRdHdrDWr = NULL;
	JobWzskSrcFpgainfo_hdrDRdHdrDWr = NULL;

	topicJobWzskSrcFpgainfo_rndDRdRndDWr = NULL;
	writerJobWzskSrcFpgainfo_rndDRdRndDWr = NULL;
	JobWzskSrcFpgainfo_rndDRdRndDWr = NULL;

	topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = NULL;
	writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = NULL;
	JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = NULL;

	topicJobWzskSrcSysinfo_temp = NULL;
	writerJobWzskSrcSysinfo_temp = NULL;
	JobWzskSrcSysinfo_temp = NULL;
};

WzskcmbdDdspub::DataWriters::~DataWriters() {
	if (topicJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1) {
		delete topicJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1;
		delete writerJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1;
		delete JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1;
	};
	if (topicJobWzskAcqCorner_shiftScoreMinScoreMax) {
		delete topicJobWzskAcqCorner_shiftScoreMinScoreMax;
		delete writerJobWzskAcqCorner_shiftScoreMinScoreMax;
		delete JobWzskAcqCorner_shiftScoreMinScoreMax;
	};
	if (topicJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1) {
		delete topicJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1;
		delete writerJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1;
		delete JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1;
	};
	if (topicJobWzskActLaser_leftRight) {
		delete topicJobWzskActLaser_leftRight;
		delete writerJobWzskActLaser_leftRight;
		delete JobWzskActLaser_leftRight;
	};
	if (topicJobWzskActRotary_angleTarget) {
		delete topicJobWzskActRotary_angleTarget;
		delete writerJobWzskActRotary_angleTarget;
		delete JobWzskActRotary_angleTarget;
	};
	if (topicJobWzskSrcFpgainfo_hdrDRdHdrDWr) {
		delete topicJobWzskSrcFpgainfo_hdrDRdHdrDWr;
		delete writerJobWzskSrcFpgainfo_hdrDRdHdrDWr;
		delete JobWzskSrcFpgainfo_hdrDRdHdrDWr;
	};
	if (topicJobWzskSrcFpgainfo_rndDRdRndDWr) {
		delete topicJobWzskSrcFpgainfo_rndDRdRndDWr;
		delete writerJobWzskSrcFpgainfo_rndDRdRndDWr;
		delete JobWzskSrcFpgainfo_rndDRdRndDWr;
	};
	if (topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3) {
		delete topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
		delete writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
		delete JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3;
	};
	if (topicJobWzskSrcSysinfo_temp) {
		delete topicJobWzskSrcSysinfo_temp;
		delete writerJobWzskSrcSysinfo_temp;
		delete JobWzskSrcSysinfo_temp;
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

	if (statshr.jrefAcqcorner != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERMETHOD, "setRoi", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskAcqCorner.setRoi");
			repliers.replierJobWzskAcqCorner_setRoi = new rti::request::Replier<DdsJobWzskAcqCorner::setRoi_req,DdsJobWzskAcqCorner::setRoi_reply>(params);
		};
	};
	if (statshr.jrefAcqtrace != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqtrace, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEMETHOD, "setRoi", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskAcqTrace.setRoi");
			repliers.replierJobWzskAcqTrace_setRoi = new rti::request::Replier<DdsJobWzskAcqTrace::setRoi_req,DdsJobWzskAcqTrace::setRoi_reply>(params);
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
	if (statshr.jrefActrotary != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "moveto", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActRotary.moveto");
			repliers.replierJobWzskActRotary_moveto = new rti::request::Replier<DdsJobWzskActRotary::moveto_req,DdsJobWzskActRotary::moveto_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "stop", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActRotary.stop");
			repliers.replierJobWzskActRotary_stop = new rti::request::Replier<DdsJobWzskActRotary::stop_req,DdsJobWzskActRotary::stop_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "turn", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActRotary.turn");
			repliers.replierJobWzskActRotary_turn = new rti::request::Replier<DdsJobWzskActRotary::turn_req,DdsJobWzskActRotary::turn_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYMETHOD, "zero", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActRotary.zero");
			repliers.replierJobWzskActRotary_zero = new rti::request::Replier<DdsJobWzskActRotary::zero_req,DdsJobWzskActRotary::zero_reply>(params);
		};
	};

	// - register call listeners for each variable with view (read) access
	if (statshr.jrefAcqcorner != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "roiX0RoiY0RoiX1RoiY1", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1 = new DdsJobWzskAcqCorner::roiX0RoiY0RoiX1RoiY1();
			dataWriters.topicJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1 = new dds::topic::Topic<DdsJobWzskAcqCorner::roiX0RoiY0RoiX1RoiY1>(participant, "JobWzskAcqCorner.roiX0RoiY0RoiX1RoiY1");
			dataWriters.writerJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1 = new dds::pub::DataWriter<DdsJobWzskAcqCorner::roiX0RoiY0RoiX1RoiY1>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1);

			xchg->addClstnDdspub(statshr.jrefAcqcorner, "roiX0RoiY0RoiX1RoiY1", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqcorner, VecWzskVFeatgroup::VECVJOBWZSKACQCORNERVAR, "shiftScoreMinScoreMax", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqCorner_shiftScoreMinScoreMax = new DdsJobWzskAcqCorner::shiftScoreMinScoreMax();
			dataWriters.topicJobWzskAcqCorner_shiftScoreMinScoreMax = new dds::topic::Topic<DdsJobWzskAcqCorner::shiftScoreMinScoreMax>(participant, "JobWzskAcqCorner.shiftScoreMinScoreMax");
			dataWriters.writerJobWzskAcqCorner_shiftScoreMinScoreMax = new dds::pub::DataWriter<DdsJobWzskAcqCorner::shiftScoreMinScoreMax>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqCorner_shiftScoreMinScoreMax);

			xchg->addClstnDdspub(statshr.jrefAcqcorner, "shiftScoreMinScoreMax", true);
		};
	};
	if (statshr.jrefAcqtrace != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqtrace, VecWzskVFeatgroup::VECVJOBWZSKACQTRACEVAR, "roiX0RoiY0RoiX1RoiY1", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1 = new DdsJobWzskAcqTrace::roiX0RoiY0RoiX1RoiY1();
			dataWriters.topicJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1 = new dds::topic::Topic<DdsJobWzskAcqTrace::roiX0RoiY0RoiX1RoiY1>(participant, "JobWzskAcqTrace.roiX0RoiY0RoiX1RoiY1");
			dataWriters.writerJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1 = new dds::pub::DataWriter<DdsJobWzskAcqTrace::roiX0RoiY0RoiX1RoiY1>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1);

			xchg->addClstnDdspub(statshr.jrefAcqtrace, "roiX0RoiY0RoiX1RoiY1", true);
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
	if (statshr.jrefActrotary != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActrotary, VecWzskVFeatgroup::VECVJOBWZSKACTROTARYVAR, "angleTarget", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskActRotary_angleTarget = new DdsJobWzskActRotary::angleTarget();
			dataWriters.topicJobWzskActRotary_angleTarget = new dds::topic::Topic<DdsJobWzskActRotary::angleTarget>(participant, "JobWzskActRotary.angleTarget");
			dataWriters.writerJobWzskActRotary_angleTarget = new dds::pub::DataWriter<DdsJobWzskActRotary::angleTarget>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskActRotary_angleTarget);

			xchg->addClstnDdspub(statshr.jrefActrotary, "angleTarget", true);
		};
	};
	if (statshr.jrefSrcfpgainfo != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcfpgainfo, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "hdrDRdHdrDWr", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskSrcFpgainfo_hdrDRdHdrDWr = new DdsJobWzskSrcFpgainfo::hdrDRdHdrDWr();
			dataWriters.topicJobWzskSrcFpgainfo_hdrDRdHdrDWr = new dds::topic::Topic<DdsJobWzskSrcFpgainfo::hdrDRdHdrDWr>(participant, "JobWzskSrcFpgainfo.hdrDRdHdrDWr");
			dataWriters.writerJobWzskSrcFpgainfo_hdrDRdHdrDWr = new dds::pub::DataWriter<DdsJobWzskSrcFpgainfo::hdrDRdHdrDWr>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskSrcFpgainfo_hdrDRdHdrDWr);

			xchg->addClstnDdspub(statshr.jrefSrcfpgainfo, "hdrDRdHdrDWr", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcfpgainfo, VecWzskVFeatgroup::VECVJOBWZSKSRCFPGAINFOVAR, "rndDRdRndDWr", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskSrcFpgainfo_rndDRdRndDWr = new DdsJobWzskSrcFpgainfo::rndDRdRndDWr();
			dataWriters.topicJobWzskSrcFpgainfo_rndDRdRndDWr = new dds::topic::Topic<DdsJobWzskSrcFpgainfo::rndDRdRndDWr>(participant, "JobWzskSrcFpgainfo.rndDRdRndDWr");
			dataWriters.writerJobWzskSrcFpgainfo_rndDRdRndDWr = new dds::pub::DataWriter<DdsJobWzskSrcFpgainfo::rndDRdRndDWr>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskSrcFpgainfo_rndDRdRndDWr);

			xchg->addClstnDdspub(statshr.jrefSrcfpgainfo, "rndDRdRndDWr", true);
		};
	};
	if (statshr.jrefSrcsysinfo != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcsysinfo, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = new DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3();
			dataWriters.topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = new dds::topic::Topic<DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3>(participant, "JobWzskSrcSysinfo.loadAllLoadCore0LoadCore1LoadCore2LoadCore3");
			dataWriters.writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = new dds::pub::DataWriter<DdsJobWzskSrcSysinfo::loadAllLoadCore0LoadCore1LoadCore2LoadCore3>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3);

			xchg->addClstnDdspub(statshr.jrefSrcsysinfo, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefSrcsysinfo, VecWzskVFeatgroup::VECVJOBWZSKSRCSYSINFOVAR, "temp", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskSrcSysinfo_temp = new DdsJobWzskSrcSysinfo::temp();
			dataWriters.topicJobWzskSrcSysinfo_temp = new dds::topic::Topic<DdsJobWzskSrcSysinfo::temp>(participant, "JobWzskSrcSysinfo.temp");
			dataWriters.writerJobWzskSrcSysinfo_temp = new dds::pub::DataWriter<DdsJobWzskSrcSysinfo::temp>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskSrcSysinfo_temp);

			xchg->addClstnDdspub(statshr.jrefSrcsysinfo, "temp", true);
		};
	};

	xchg->cStable.signal("WzskcmbdDdspub", "run");

	while (true) {
		xchg->cDdspub.lockMutex("WzskcmbdDdspub", "run");
		while (!(xchg->ddspubcall)) xchg->cDdspub.wait("WzskcmbdDdspub", "run");

		if ((xchg->ddspubcall->jref == statshr.jrefAcqcorner) && (xchg->ddspubcall->argInv.sref == "roiX0RoiY0RoiX1RoiY1")) {
			JobWzskAcqCorner::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1->roiX0(JobWzskAcqCorner::shrdat.roiX0);
			dataWriters.JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1->roiY0(JobWzskAcqCorner::shrdat.roiY0);
			dataWriters.JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1->roiX1(JobWzskAcqCorner::shrdat.roiX1);
			dataWriters.JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1->roiY1(JobWzskAcqCorner::shrdat.roiY1);
			JobWzskAcqCorner::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1->write(*(dataWriters.JobWzskAcqCorner_roiX0RoiY0RoiX1RoiY1));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqcorner) && (xchg->ddspubcall->argInv.sref == "shiftScoreMinScoreMax")) {
			JobWzskAcqCorner::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqCorner_shiftScoreMinScoreMax->shift(JobWzskAcqCorner::shrdat.shift);
			dataWriters.JobWzskAcqCorner_shiftScoreMinScoreMax->scoreMin(JobWzskAcqCorner::shrdat.scoreMin);
			dataWriters.JobWzskAcqCorner_shiftScoreMinScoreMax->scoreMax(JobWzskAcqCorner::shrdat.scoreMax);
			JobWzskAcqCorner::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqCorner_shiftScoreMinScoreMax->write(*(dataWriters.JobWzskAcqCorner_shiftScoreMinScoreMax));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqtrace) && (xchg->ddspubcall->argInv.sref == "roiX0RoiY0RoiX1RoiY1")) {
			JobWzskAcqTrace::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1->roiX0(JobWzskAcqTrace::shrdat.roiX0);
			dataWriters.JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1->roiY0(JobWzskAcqTrace::shrdat.roiY0);
			dataWriters.JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1->roiX1(JobWzskAcqTrace::shrdat.roiX1);
			dataWriters.JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1->roiY1(JobWzskAcqTrace::shrdat.roiY1);
			JobWzskAcqTrace::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1->write(*(dataWriters.JobWzskAcqTrace_roiX0RoiY0RoiX1RoiY1));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActlaser) && (xchg->ddspubcall->argInv.sref == "leftRight")) {
			JobWzskActLaser::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskActLaser_leftRight->left(JobWzskActLaser::shrdat.left);
			dataWriters.JobWzskActLaser_leftRight->right(JobWzskActLaser::shrdat.right);
			JobWzskActLaser::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskActLaser_leftRight->write(*(dataWriters.JobWzskActLaser_leftRight));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActrotary) && (xchg->ddspubcall->argInv.sref == "angleTarget")) {
			JobWzskActRotary::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskActRotary_angleTarget->angle(JobWzskActRotary::shrdat.angle);
			dataWriters.JobWzskActRotary_angleTarget->target(JobWzskActRotary::shrdat.target);
			JobWzskActRotary::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskActRotary_angleTarget->write(*(dataWriters.JobWzskActRotary_angleTarget));
		} else if ((xchg->ddspubcall->jref == statshr.jrefSrcfpgainfo) && (xchg->ddspubcall->argInv.sref == "hdrDRdHdrDWr")) {
			JobWzskSrcFpgainfo::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskSrcFpgainfo_hdrDRdHdrDWr->hdrDRd(JobWzskSrcFpgainfo::shrdat.hdrDRd);
			dataWriters.JobWzskSrcFpgainfo_hdrDRdHdrDWr->hdrDWr(JobWzskSrcFpgainfo::shrdat.hdrDWr);
			JobWzskSrcFpgainfo::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskSrcFpgainfo_hdrDRdHdrDWr->write(*(dataWriters.JobWzskSrcFpgainfo_hdrDRdHdrDWr));
		} else if ((xchg->ddspubcall->jref == statshr.jrefSrcfpgainfo) && (xchg->ddspubcall->argInv.sref == "rndDRdRndDWr")) {
			JobWzskSrcFpgainfo::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskSrcFpgainfo_rndDRdRndDWr->rndDRd(JobWzskSrcFpgainfo::shrdat.rndDRd);
			dataWriters.JobWzskSrcFpgainfo_rndDRdRndDWr->rndDWr(JobWzskSrcFpgainfo::shrdat.rndDWr);
			JobWzskSrcFpgainfo::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskSrcFpgainfo_rndDRdRndDWr->write(*(dataWriters.JobWzskSrcFpgainfo_rndDRdRndDWr));
		} else if ((xchg->ddspubcall->jref == statshr.jrefSrcsysinfo) && (xchg->ddspubcall->argInv.sref == "loadAllLoadCore0LoadCore1LoadCore2LoadCore3")) {
			JobWzskSrcSysinfo::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3->loadAll(JobWzskSrcSysinfo::shrdat.loadAll);
			dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3->loadCore0(JobWzskSrcSysinfo::shrdat.loadCore0);
			dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3->loadCore1(JobWzskSrcSysinfo::shrdat.loadCore1);
			dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3->loadCore2(JobWzskSrcSysinfo::shrdat.loadCore2);
			dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3->loadCore3(JobWzskSrcSysinfo::shrdat.loadCore3);
			JobWzskSrcSysinfo::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3->write(*(dataWriters.JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3));
		} else if ((xchg->ddspubcall->jref == statshr.jrefSrcsysinfo) && (xchg->ddspubcall->argInv.sref == "temp")) {
			JobWzskSrcSysinfo::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskSrcSysinfo_temp->_temp(JobWzskSrcSysinfo::shrdat.temp);
			JobWzskSrcSysinfo::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskSrcSysinfo_temp->write(*(dataWriters.JobWzskSrcSysinfo_temp));
		};

		xchg->ddspubcall = NULL;

		xchg->cDdspub.unlockMutex("WzskcmbdDdspub", "run");

		xchg->cDdspub.signal("WzskcmbdDdspub", "run");
	};

	pthread_cleanup_pop(1);

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

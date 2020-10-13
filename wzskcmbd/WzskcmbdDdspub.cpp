/**
	* \file WzskcmbdDdspub.cpp
	* DDS publisher based on rti DDS Connext for Wzsk combined daemon (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
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

		template<> void ReplierListener<DdsJobWzskActServo::stop_req,DdsJobWzskActServo::stop_reply>::on_request_available(
					Replier<DdsJobWzskActServo::stop_req,DdsJobWzskActServo::stop_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActServo::stop_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "stop",
							{&request.data().dummy()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActServo::turn_req,DdsJobWzskActServo::turn_reply>::on_request_available(
					Replier<DdsJobWzskActServo::turn_req,DdsJobWzskActServo::turn_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActServo::turn_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "turn",
							{&request.data().ccwNotCw()},
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

		template<> void ReplierListener<DdsJobWzskActExposure::setExposure_req,DdsJobWzskActExposure::setExposure_reply>::on_request_available(
					Replier<DdsJobWzskActExposure::setExposure_req,DdsJobWzskActExposure::setExposure_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActExposure::setExposure_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActexposure, VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREMETHOD, "setExposure",
							{&request.data().autoNotManual(), &request.data().Texp()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskActExposure::setFocus_req,DdsJobWzskActExposure::setFocus_reply>::on_request_available(
					Replier<DdsJobWzskActExposure::setFocus_req,DdsJobWzskActExposure::setFocus_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskActExposure::setFocus_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefActexposure, VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREMETHOD, "setFocus",
							{&request.data().focus()},
							{&reply.success()});

				replier.send_reply(reply, request.info());
			};
		};

		template<> void ReplierListener<DdsJobWzskAcqPtcloud::setDeltaTheta_req,DdsJobWzskAcqPtcloud::setDeltaTheta_reply>::on_request_available(
					Replier<DdsJobWzskAcqPtcloud::setDeltaTheta_req,DdsJobWzskAcqPtcloud::setDeltaTheta_reply>& replier
				) {
			auto requests = replier.receive_requests(dds::core::Duration());
			DdsJobWzskAcqPtcloud::setDeltaTheta_reply reply;

			for (const auto& request: requests) {
				if (!request.info().valid()) continue;

				WzskcmbdDdspub::runMethod(WzskcmbdDdspub::statshr.jrefAcqptcloud, VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDMETHOD, "setDeltaTheta",
							{&request.data().deltaTheta()},
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
	replierJobWzskIprTrace_setRoi = NULL;
	replierJobWzskIprTrace_setRoiNotFull = NULL;

	replierJobWzskIprCorner_setNTarget = NULL;
	replierJobWzskIprCorner_setRoi = NULL;
	replierJobWzskIprCorner_setRoiNotFull = NULL;

	replierJobWzskActServo_moveto = NULL;
	replierJobWzskActServo_stop = NULL;
	replierJobWzskActServo_turn = NULL;
	replierJobWzskActServo_zero = NULL;

	replierJobWzskActLaser_setLeft = NULL;
	replierJobWzskActLaser_setRight = NULL;

	replierJobWzskActExposure_setExposure = NULL;
	replierJobWzskActExposure_setFocus = NULL;

	replierJobWzskAcqPtcloud_setDeltaTheta = NULL;
};

WzskcmbdDdspub::Repliers::~Repliers() {
	if (replierJobWzskIprTrace_setLevel) delete replierJobWzskIprTrace_setLevel;
	if (replierJobWzskIprTrace_setRoi) delete replierJobWzskIprTrace_setRoi;
	if (replierJobWzskIprTrace_setRoiNotFull) delete replierJobWzskIprTrace_setRoiNotFull;

	if (replierJobWzskIprCorner_setNTarget) delete replierJobWzskIprCorner_setNTarget;
	if (replierJobWzskIprCorner_setRoi) delete replierJobWzskIprCorner_setRoi;
	if (replierJobWzskIprCorner_setRoiNotFull) delete replierJobWzskIprCorner_setRoiNotFull;

	if (replierJobWzskActServo_moveto) delete replierJobWzskActServo_moveto;
	if (replierJobWzskActServo_stop) delete replierJobWzskActServo_stop;
	if (replierJobWzskActServo_turn) delete replierJobWzskActServo_turn;
	if (replierJobWzskActServo_zero) delete replierJobWzskActServo_zero;

	if (replierJobWzskActLaser_setLeft) delete replierJobWzskActLaser_setLeft;
	if (replierJobWzskActLaser_setRight) delete replierJobWzskActLaser_setRight;

	if (replierJobWzskActExposure_setExposure) delete replierJobWzskActExposure_setExposure;
	if (replierJobWzskActExposure_setFocus) delete replierJobWzskActExposure_setFocus;

	if (replierJobWzskAcqPtcloud_setDeltaTheta) delete replierJobWzskAcqPtcloud_setDeltaTheta;
};

/******************************************************************************
 class WzskcmbdDdspub::DataWriters
 ******************************************************************************/

WzskcmbdDdspub::DataWriters::DataWriters() {
	topicJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = NULL;
	writerJobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = NULL;
	JobWzskSrcSysinfo_loadAllLoadCore0LoadCore1LoadCore2LoadCore3 = NULL;

	topicJobWzskSrcSysinfo_temp = NULL;
	writerJobWzskSrcSysinfo_temp = NULL;
	JobWzskSrcSysinfo_temp = NULL;

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

	topicJobWzskIprCorner_flgShiftScoreMinScoreMax = NULL;
	writerJobWzskIprCorner_flgShiftScoreMinScoreMax = NULL;
	JobWzskIprCorner_flgShiftScoreMinScoreMax = NULL;

	topicJobWzskActServo_angleTarget = NULL;
	writerJobWzskActServo_angleTarget = NULL;
	JobWzskActServo_angleTarget = NULL;

	topicJobWzskActLaser_leftRight = NULL;
	writerJobWzskActLaser_leftRight = NULL;
	JobWzskActLaser_leftRight = NULL;

	topicJobWzskActExposure_autoNotManualTexp = NULL;
	writerJobWzskActExposure_autoNotManualTexp = NULL;
	JobWzskActExposure_autoNotManualTexp = NULL;

	topicJobWzskActExposure_focus = NULL;
	writerJobWzskActExposure_focus = NULL;
	JobWzskActExposure_focus = NULL;

	topicJobWzskAcqPtcloud_deltaTheta = NULL;
	writerJobWzskAcqPtcloud_deltaTheta = NULL;
	JobWzskAcqPtcloud_deltaTheta = NULL;

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
	if (topicJobWzskIprCorner_flgShiftScoreMinScoreMax) {
		delete topicJobWzskIprCorner_flgShiftScoreMinScoreMax;
		delete writerJobWzskIprCorner_flgShiftScoreMinScoreMax;
		delete JobWzskIprCorner_flgShiftScoreMinScoreMax;
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
	if (topicJobWzskActExposure_autoNotManualTexp) {
		delete topicJobWzskActExposure_autoNotManualTexp;
		delete writerJobWzskActExposure_autoNotManualTexp;
		delete JobWzskActExposure_autoNotManualTexp;
	};
	if (topicJobWzskActExposure_focus) {
		delete topicJobWzskActExposure_focus;
		delete writerJobWzskActExposure_focus;
		delete JobWzskActExposure_focus;
	};
	if (topicJobWzskAcqPtcloud_deltaTheta) {
		delete topicJobWzskAcqPtcloud_deltaTheta;
		delete writerJobWzskAcqPtcloud_deltaTheta;
		delete JobWzskAcqPtcloud_deltaTheta;
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
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "stop", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActServo.stop");
			repliers.replierJobWzskActServo_stop = new rti::request::Replier<DdsJobWzskActServo::stop_req,DdsJobWzskActServo::stop_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActservo, VecWzskVFeatgroup::VECVJOBWZSKACTSERVOMETHOD, "turn", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActServo.turn");
			repliers.replierJobWzskActServo_turn = new rti::request::Replier<DdsJobWzskActServo::turn_req,DdsJobWzskActServo::turn_reply>(params);
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
	if (statshr.jrefActexposure != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActexposure, VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREMETHOD, "setExposure", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActExposure.setExposure");
			repliers.replierJobWzskActExposure_setExposure = new rti::request::Replier<DdsJobWzskActExposure::setExposure_req,DdsJobWzskActExposure::setExposure_reply>(params);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActexposure, VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREMETHOD, "setFocus", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskActExposure.setFocus");
			repliers.replierJobWzskActExposure_setFocus = new rti::request::Replier<DdsJobWzskActExposure::setFocus_req,DdsJobWzskActExposure::setFocus_reply>(params);
		};
	};
	if (statshr.jrefAcqptcloud != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqptcloud, VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDMETHOD, "setDeltaTheta", ixAcc);
		if ((ixAcc & VecWzskWAccess::EXEC) == VecWzskWAccess::EXEC) {
			params.service_name("JobWzskAcqPtcloud.setDeltaTheta");
			repliers.replierJobWzskAcqPtcloud_setDeltaTheta = new rti::request::Replier<DdsJobWzskAcqPtcloud::setDeltaTheta_req,DdsJobWzskAcqPtcloud::setDeltaTheta_reply>(params);
		};
	};

	// - register call listeners for each variable with view (read) access
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
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefIprcorner, VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERVAR, "flgShiftScoreMinScoreMax", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskIprCorner_flgShiftScoreMinScoreMax = new DdsJobWzskIprCorner::flgShiftScoreMinScoreMax();
			dataWriters.topicJobWzskIprCorner_flgShiftScoreMinScoreMax = new dds::topic::Topic<DdsJobWzskIprCorner::flgShiftScoreMinScoreMax>(participant, "JobWzskIprCorner.flgShiftScoreMinScoreMax");
			dataWriters.writerJobWzskIprCorner_flgShiftScoreMinScoreMax = new dds::pub::DataWriter<DdsJobWzskIprCorner::flgShiftScoreMinScoreMax>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskIprCorner_flgShiftScoreMinScoreMax);

			xchg->addClstnDdspub(statshr.jrefIprcorner, "flgShiftScoreMinScoreMax", true);
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
	if (statshr.jrefActexposure != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActexposure, VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREVAR, "autoNotManualTexp", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskActExposure_autoNotManualTexp = new DdsJobWzskActExposure::autoNotManualTexp();
			dataWriters.topicJobWzskActExposure_autoNotManualTexp = new dds::topic::Topic<DdsJobWzskActExposure::autoNotManualTexp>(participant, "JobWzskActExposure.autoNotManualTexp");
			dataWriters.writerJobWzskActExposure_autoNotManualTexp = new dds::pub::DataWriter<DdsJobWzskActExposure::autoNotManualTexp>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskActExposure_autoNotManualTexp);

			xchg->addClstnDdspub(statshr.jrefActexposure, "autoNotManualTexp", true);
		};
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefActexposure, VecWzskVFeatgroup::VECVJOBWZSKACTEXPOSUREVAR, "focus", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskActExposure_focus = new DdsJobWzskActExposure::focus();
			dataWriters.topicJobWzskActExposure_focus = new dds::topic::Topic<DdsJobWzskActExposure::focus>(participant, "JobWzskActExposure.focus");
			dataWriters.writerJobWzskActExposure_focus = new dds::pub::DataWriter<DdsJobWzskActExposure::focus>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskActExposure_focus);

			xchg->addClstnDdspub(statshr.jrefActexposure, "focus", true);
		};
	};
	if (statshr.jrefAcqptcloud != 0) {
		xchg->triggerIxSrefToIxCall(NULL, VecWzskVCall::CALLWZSKACCESS, statshr.jrefAcqptcloud, VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDVAR, "deltaTheta", ixAcc);
		if ((ixAcc & VecWzskWAccess::VIEW) == VecWzskWAccess::VIEW) {
			dataWriters.JobWzskAcqPtcloud_deltaTheta = new DdsJobWzskAcqPtcloud::deltaTheta();
			dataWriters.topicJobWzskAcqPtcloud_deltaTheta = new dds::topic::Topic<DdsJobWzskAcqPtcloud::deltaTheta>(participant, "JobWzskAcqPtcloud.deltaTheta");
			dataWriters.writerJobWzskAcqPtcloud_deltaTheta = new dds::pub::DataWriter<DdsJobWzskAcqPtcloud::deltaTheta>(dds::pub::Publisher(participant), *dataWriters.topicJobWzskAcqPtcloud_deltaTheta);

			xchg->addClstnDdspub(statshr.jrefAcqptcloud, "deltaTheta", true);
		};
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

		if ((xchg->ddspubcall->jref == statshr.jrefSrcsysinfo) && (xchg->ddspubcall->argInv.sref == "loadAllLoadCore0LoadCore1LoadCore2LoadCore3")) {
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
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprtrace) && (xchg->ddspubcall->argInv.sref == "pOnLeftPOnRight")) {
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
		} else if ((xchg->ddspubcall->jref == statshr.jrefIprcorner) && (xchg->ddspubcall->argInv.sref == "flgShiftScoreMinScoreMax")) {
			JobWzskIprCorner::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskIprCorner_flgShiftScoreMinScoreMax->flg(JobWzskIprCorner::shrdat.flg);
			dataWriters.JobWzskIprCorner_flgShiftScoreMinScoreMax->shift(JobWzskIprCorner::shrdat.shift);
			dataWriters.JobWzskIprCorner_flgShiftScoreMinScoreMax->scoreMin(JobWzskIprCorner::shrdat.scoreMin);
			dataWriters.JobWzskIprCorner_flgShiftScoreMinScoreMax->scoreMax(JobWzskIprCorner::shrdat.scoreMax);
			JobWzskIprCorner::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskIprCorner_flgShiftScoreMinScoreMax->write(*(dataWriters.JobWzskIprCorner_flgShiftScoreMinScoreMax));
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
		} else if ((xchg->ddspubcall->jref == statshr.jrefActexposure) && (xchg->ddspubcall->argInv.sref == "autoNotManualTexp")) {
			JobWzskActExposure::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskActExposure_autoNotManualTexp->autoNotManual(JobWzskActExposure::shrdat.autoNotManual);
			dataWriters.JobWzskActExposure_autoNotManualTexp->Texp(JobWzskActExposure::shrdat.Texp);
			JobWzskActExposure::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskActExposure_autoNotManualTexp->write(*(dataWriters.JobWzskActExposure_autoNotManualTexp));
		} else if ((xchg->ddspubcall->jref == statshr.jrefActexposure) && (xchg->ddspubcall->argInv.sref == "focus")) {
			JobWzskActExposure::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskActExposure_focus->_focus(JobWzskActExposure::shrdat.focus);
			JobWzskActExposure::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskActExposure_focus->write(*(dataWriters.JobWzskActExposure_focus));
		} else if ((xchg->ddspubcall->jref == statshr.jrefAcqptcloud) && (xchg->ddspubcall->argInv.sref == "deltaTheta")) {
			JobWzskAcqPtcloud::shrdat.rlockAccess("WzskcmbdDdspub", "run");
			dataWriters.JobWzskAcqPtcloud_deltaTheta->_deltaTheta(JobWzskAcqPtcloud::shrdat.deltaTheta);
			JobWzskAcqPtcloud::shrdat.runlockAccess("WzskcmbdDdspub", "run");

			dataWriters.writerJobWzskAcqPtcloud_deltaTheta->write(*(dataWriters.JobWzskAcqPtcloud_deltaTheta));
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

